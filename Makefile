##
## Makefile for lkm-syscall
## 
## Made by xsyann
## Contact <contact@xsyann.com>
## 
## Started on  Fri Mar 28 15:05:15 2014 xsyann
## Last update Fri Mar 28 15:19:45 2014 xsyann
##

all:
	cd lkm; make
	cd test; make

clean:
	cd lkm; make clean
	cd test; make clean
