#!/bin/make

# Author: Anne C. van Rossum
# Date: Mar. 8, 2012

# The default.mk file makes svn retrieved modules compiling
-include aim/default.mk
# This include file should define BACKEND
-include $(HOME)/.rur/rur.mk
# Overwrite with your local changes, don't commit this to svn
-include aim/local.mk

CURRENT_MODULE_PATH:=$(CURDIR)
ROS_PACKAGE_PATH:=$(ROS_PACKAGE_PATH):$(CURRENT_MODULE_PATH)

ROS_FLAG=-DBUILD_ROS:bool=off
YARP_FLAG=-DBUILD_YARP:bool=off
FLAGS=$(ROS_FLAG) $(YARP_FLAG) -DBUILD_$(BACKEND):bool=on

backend_lc=`echo $(BACKEND) | tr A-Z a-z`

MODULENAME=ExampleModule

all: 
	@echo $(ROS_PACKAGE_PATH)
	@mkdir -p build
	cd build && cmake $(CMAKE_FLAGS) .. $(FLAGS)
	cd build && make

clean:
	cd build && make clean
	rm -f build/CMakeCache.txt
