# Makefile is a part of the PYTHIA event generator.
# Copyright (C) 2020 Torbjorn Sjostrand.
# PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
# Please respect the MCnet Guidelines, see GUIDELINES for details.
# Author: Philip Ilten, September 2014.
#
# This is is the Makefile used to build PYTHIA examples on POSIX systems.
# Example usage is:
#     make main01
# For help using the make command please consult the local system documentation,
# i.e. "man make" or "make --help".

################################################################################
# VARIABLES: Definition of the relevant variables from the configuration script.
################################################################################

# Set the shell.
SHELL=/usr/bin/env bash

# Include the configuration.
-include Makefile.inc

# Check distribution (use local version first, then installed version).
ifneq ("$(wildcard ../lib/libpythia8.*)","")
  PREFIX_LIB=../li
  PREFIX_INCLUDE=../include
endif
CXX_COMMON:=-I$(PREFIX_INCLUDE) $(CXX_COMMON) $(GZIP_LIB)
CXX_COMMON+= -L$(PREFIX_LIB) -Wl,-rpath,$(PREFIX_LIB) -lpythia8 -ldl
PYTHIA=$(PREFIX_LIB)/libpythia8$(LIB_SUFFIX)
################################################################################
################################################################################
################################################################################
# Works "out of the box"
main: main.cxx
	$(CXX) main.cxx -o test -w $(CXX_COMMON:c++11=c++14) $(FASTJET3_INCLUDE) $(FASTJET3_LIB)
jetmass: main.cxx
	$(CXX) jetmass.cxx -o jet_mass -w $(CXX_COMMON:c++11=c++14) $(FASTJET3_INCLUDE) $(FASTJET3_LIB)
	$ ./jet_mass
	$ python3 massplot.py
massjet: main.cxx
	$(CXX) massjet.cxx -o mass_jet -w $(CXX_COMMON:c++11=c++14) $(FASTJET3_INCLUDE) $(FASTJET3_LIB)
	$ ./mass_jet
	$ python3 massplot2.py
# For this one you should adjust PREFIX
#PREFIX=/Users/cmeherg

#FJ_LIB=-Wl,-rpath,$(PREFIX)/fastjet/lib -L$(PREFIX)/fastjet/lib -lfastjettools -lfastjet -lm
#FJ_INC=-I$(PREFIX)/fastjet/include

#main: main.cxx
#	$(CXX) main.cxx -o test -w $(CXX_COMMON:c++11=c++14) $(FJ_LIB) $(FJ_INC)


clean:
	        rm test *.o
