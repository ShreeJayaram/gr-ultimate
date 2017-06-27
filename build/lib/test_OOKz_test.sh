#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mcl/OOT_Modules/gr-ultimate/lib
export PATH=/home/mcl/OOT_Modules/gr-ultimate/build/lib:$PATH
export LD_LIBRARY_PATH=/home/mcl/OOT_Modules/gr-ultimate/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-OOKz 
