#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mcl/OOT_Modules/gr-ultimate/python
export PATH=/home/mcl/OOT_Modules/gr-ultimate/build/python:$PATH
export LD_LIBRARY_PATH=/home/mcl/OOT_Modules/gr-ultimate/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/mcl/OOT_Modules/gr-ultimate/build/swig:$PYTHONPATH
/usr/bin/python2 /home/mcl/OOT_Modules/gr-ultimate/python/qa_orange.py 
