MACHINE = $(shell uname -s)
LINUX  = Linux
MAC    = Darwin
#-D_DEBUG_
CXX=$(shell root-config --cxx) -g -I. -O2 -std=c++11  
##
## My Directories
##

##
CC = g++ -std=c++11
ROOT_INC     := $(ROOTSYS)/include
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --glibs)
##
LFLAGS       := -L.  -Llib  $(ROOTLIBS) -lRooFit -lRooFitCore 
CFLAGS       := -ggdb -fPIC -DLINUX -w -funsigned-char -I$(ROOT_INC) -I$(ROOTCFLAGS)


         
all:   Jandan 
	
Jandan:  
	g++ $(CFLAGS)   main.cpp  -o   main.exe   $(LFLAGS)	

clean:
		rm -rf 
		rm -rf *.o

remove:
          