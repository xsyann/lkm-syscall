#!/bin/bash

echo "┌──────────────────────────────┐"
echo "│  Load Kernel Module syscall  │"
echo "└──────────────────────────────┘"
echo "# insmod syscall.ko"
sudo insmod ./lkm/syscall.ko
echo ""
echo "┌──────────────────────────────┐"
echo "│           lsmod              │"
echo "└──────────────────────────────┘"
echo "$ lsmod | grep 'syscall'"
lsmod | grep "syscall"
echo ""
echo "┌──────────────────────────────┐"
echo "│           Test               │"
echo "└──────────────────────────────┘"
echo "$ ./test $1"
./test/test $1
echo ""
echo "┌──────────────────────────────┐"
echo "│ Unload Kernel Module syscall │"
echo "└──────────────────────────────┘"
echo "# rmmod syscall"
sudo rmmod syscall
echo ""
echo "┌──────────────────────────────┐"
echo "│           dmesg              │"
echo "└──────────────────────────────┘"
echo "$ dmesg"
dmesg | tail -n 9