lkm-syscall
===========

Linux Loadable Kernel Module system call hijacking


    > ./run.sh foobar
     ------------------------------
    |  Load Kernel Module syscall  |
     ------------------------------

     ------------------------------
    |           lsmod              |
     ------------------------------
    syscall                12658  0 

     ------------------------------
    |           Test               |
     ------------------------------
    Call syscall at offset 184
    Syscall return 0

     ------------------------------
    | Unload Kernel Module syscall |
     ------------------------------

     ------------------------------
    |           dmesg              |
     ------------------------------
    [35468.433211] Custom syscall loaded
    [35468.433215] Syscall table address : ffffffff81801420
    [35468.433256] Syscall at offset 184 : ffffffff810885f0
    [35468.433258] Custom syscall address ffffffffa0111000
    [35468.433259] Syscall hijacked
    [35468.433260] Syscall at offset 184 : ffffffffa0111000
    [35468.444576] LKM Syscall : foobar
    [35468.466679] Syscall at offset 184 : ffffffff810885f0
    [35468.466682] Custom syscall unloaded
