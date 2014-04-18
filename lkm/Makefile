##
## Makefile for lkm-syscall
##
## Made by xsyann
## Contact <contact@xsyann.com>
##
## Started on  Wed Mar 26 13:49:00 2014 xsyann
## Last update Fri Apr 18 22:13:46 2014 xsyann
##

TARGET	= syscall

obj-m	+= $(TARGET).o

CURRENT = $(shell uname -r)
KDIR	= /lib/modules/$(CURRENT)/build

all:
	$(shell ./get_syscall_table.sh syscall.c)
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
