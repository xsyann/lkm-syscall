/*
** syscall.c for lkm_syscall
** 
** Made by xsyann
** Contact <contact@xsyann.com>
** 
** Started on  Fri Mar 14 10:04:32 2014 xsyann
** Last update Wed Mar 26 13:41:54 2014 xsyann
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yann KOETH");
MODULE_DESCRIPTION("Loadable Kernel Module Syscall");
MODULE_VERSION("0.1");

#define SYS_CALL_TABLE "sys_call_table"
#define SYSCALL_NI __NR_tuxcall

static ulong *syscall_table = (ulong *)0xffffffff81801420; /* SYS_CALL_TABLE */

static void *original_syscall = NULL;

static int lkm_syscall(const char *string)
{
    printk("LKM Syscall : %s\n", string);
    return 0;
}

static int is_syscall_table(ulong *p)
{
    return ((p != NULL) && (p[__NR_close] == (ulong)sys_close));
}

static int page_read_write(ulong address)
{  
    uint level;
    pte_t *pte = lookup_address(address, &level);

    if(pte->pte &~ _PAGE_RW)
	pte->pte |= _PAGE_RW;
    return 0;
}
 
static int page_read_only(ulong address)
{
    uint level;
    pte_t *pte = lookup_address(address, &level);
    pte->pte = pte->pte &~ _PAGE_RW;
    return 0;
}

static void replace_syscall(ulong offset, ulong func_address)
{
    if (!is_syscall_table(syscall_table))
	syscall_table = (ulong *)kallsyms_lookup_name(SYS_CALL_TABLE);
    if (is_syscall_table(syscall_table))
    {
	printk(KERN_INFO "Syscall table address : %p\n", syscall_table);
	page_read_write((ulong)syscall_table);
	original_syscall = (void *)(syscall_table[offset]);
	printk(KERN_INFO "Syscall at offset %lu : %p\n", offset, original_syscall);
	printk(KERN_INFO "Custom syscall address %p\n", lkm_syscall);
	syscall_table[offset] = func_address;
	printk(KERN_INFO "Syscall hijacked\n");
	printk(KERN_INFO "Syscall at offset %lu : %p\n", offset, (void *)syscall_table[offset]);
    	page_read_only((ulong)syscall_table);
    }
}

static int init_syscall(void)
{
    printk(KERN_INFO "Custom syscall loaded\n");
    replace_syscall(SYSCALL_NI, (ulong)lkm_syscall);
    return 0;
}

static void cleanup_syscall(void)
{
    page_read_write((ulong)syscall_table);
    syscall_table[SYSCALL_NI] = (ulong)original_syscall;
    page_read_only((ulong)syscall_table);
    printk(KERN_INFO "Syscall at offset %d : %p\n", SYSCALL_NI, (void *)syscall_table[SYSCALL_NI]);
    printk(KERN_INFO "Custom syscall unloaded\n");
}

module_init(init_syscall);
module_exit(cleanup_syscall);
