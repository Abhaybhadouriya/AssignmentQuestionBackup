#!/bin/bash
file="original_file.txt"; soft_link="soft_link.txt"; hard_link="hard_link.txt"; fifo="my_fifo"
echo "This is the original file." > $file
ln -s $file $soft_link; ln $file $hard_link; mkfifo $fifo
ls -l $file $soft_link $hard_link $fifo
