#!/bin/bash

DATE=$(date +%d-%m-%y_%H-%M)

for i in {1..10}
do
    ../bin/resource &
    sudo gdb -batch -x debug.commands -p $! >> files/profiling_$DATE.txt
    sleep $[ ( $RANDOM % 3 )  + 1 ]s
    sudo gdb -batch -x debug.commands -p $! >> files/profiling_$DATE.txt
    sleep $[ ( $RANDOM % 3 )  + 1 ]s
    sudo gdb -batch -x debug.commands -p $! >> files/profiling_$DATE.txt
    sleep $[ ( $RANDOM % 3 )  + 1 ]s
    sudo gdb -batch -x debug.commands -p $! >> files/profiling_$DATE.txt
done;

grep ghost files/profiling_$DATE.txt > files/resume_$DATE.txt
./analyse_profiling.rb files/resume_$DATE.txt > files/percent_$DATE.txt
