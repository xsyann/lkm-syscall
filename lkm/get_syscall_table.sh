#!/bin/bash

SYS_CALL_TABLE=$(sudo grep ' sys_call_table' /boot/System.map-$(uname -r) | cut -d' ' -f1)
sed -i "s/\([[:xdigit:]]*\)\(;.*SYS_CALL_TABLE\)/$SYS_CALL_TABLE\2/" $1
