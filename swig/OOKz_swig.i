/* -*- c++ -*- */

#define OOKZ_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "OOKz_swig_doc.i"

%{
#include "OOKz/orange.h"
%}


%include "OOKz/orange.h"
GR_SWIG_BLOCK_MAGIC2(OOKz, orange);
