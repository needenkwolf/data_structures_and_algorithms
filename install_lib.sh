#!/bin/bash

make
sudo cp libdatastrucs.so /usr/local/lib/datastrucs/libdatastrucs.so

p=include
for f in $(ls $p); do
	if [ -f "$p/$f" ]; then
		sudo cp $p/$f /usr/local/include/datastrucs/$f
	fi
done
