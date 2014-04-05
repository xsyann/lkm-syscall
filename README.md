lkm-syscall
===========

Linux Loadable Kernel Module system call hijacking


    > ./run.sh foobar
    ┌──────────────────────────────┐
    │  Load Kernel Module syscall  │
    └──────────────────────────────┘
    # insmod syscall.ko

    ┌──────────────────────────────┐
    │           lsmod              │
    └──────────────────────────────┘
    $ lsmod | grep 'syscall'
    syscall                12658  0 

    ┌──────────────────────────────┐
    │           Test               │
    └──────────────────────────────┘
    $ ./test 
    Call syscall at offset 184
    Syscall return 0

    ┌──────────────────────────────┐
    │ Unload Kernel Module syscall │
    └──────────────────────────────┘
    # rmmod syscall

    ┌──────────────────────────────┐
    │           dmesg              │
    └──────────────────────────────┘
    $ dmesg
    [37894.803863] Custom syscall loaded
    [37894.803870] Syscall table address : ffffffff81801420
    [37894.803899] Syscall at offset 184 : ffffffff810885f0
    [37894.803922] Custom syscall address ffffffffa0111000
    [37894.803924] Syscall hijacked
    [37894.803925] Syscall at offset 184 : ffffffffa0111000
    [37894.824530] LKM Syscall : Foo
    [37894.837080] Syscall at offset 184 : ffffffff810885f0
    [37894.837083] Custom syscall unloaded
