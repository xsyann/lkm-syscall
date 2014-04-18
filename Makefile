##
## Makefile for lkm-syscall
##
## Made by xsyann
## Contact <contact@xsyann.com>
##
## Started on  Fri Mar 28 15:05:15 2014 xsyann
## Last update Fri Apr 18 22:12:09 2014 xsyann
##

all:
	cd lkm; make
	cd test; make

clean:
	cd lkm; make clean
	cd test; make clean
