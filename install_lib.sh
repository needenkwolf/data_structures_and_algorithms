#!/bin/bash

make
sudo mkdir -p /usr/local/lib/nkextralib/
sudo mkdir -p /usr/local/include/nkextralib/
sudo cp libdatastrucs.so /usr/local/lib/nkextralib/libdatastrucs.so

p=include
for f in $(ls $p); do
	if [ -f "$p/$f" ]; then
		sudo cp $p/$f /usr/local/include/nkextralib/$f
	fi
done
