#!/bin/bash

:'
============================================================================================
File Name : 19a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

19.Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

Data : --/--/----
============================================================================================
'
# a. Create a FIFO using mknod
mknod my_fifo_mknod p && echo "mknod: FIFO created."

# b. Create a FIFO using mkfifo
mkfifo my_fifo_mkfifo && echo "mkfifo: FIFO created."

# c. Compare with strace
echo "strace for mknod:" && strace -c mknod trace_fifo_mknod p
echo "strace for mkfifo:" && strace -c mkfifo trace_fifo_mkfifo

# Cleanup
rm -f my_fifo_mknod my_fifo_mkfifo trace_fifo_mknod trace_fifo_mkfifo
