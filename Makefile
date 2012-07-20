#!/bin/make

# Author: Anne C. van Rossum
# Date: Mar. 8, 2012

all: 
	@mkdir -p build
	cd build && cmake $(CMAKE_FLAGS) ..
	cd build && make

clean:
	cd build && make clean
	rm -f build/CMakeCache.txt
