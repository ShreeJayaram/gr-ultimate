/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "orange_impl.h"

namespace gr {
  namespace OOKz {

    orange::sptr
    orange::make(float inte, int amplitude, int offset )
    {
      return gnuradio::get_initial_sptr
        (new orange_impl(inte, amplitude, offset));
    }

    /*
     * The private constructor
     */
    orange_impl::orange_impl(float inte, int amplitude, int offset )
      : gr::sync_interpolator("orange",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)),inte)
    {

	d_inte(inte);
	d_offset(offset);
	d_amplitude(amplitude);
	
    }

    /*
     * Our virtual destructor.
     */
    orange_impl::~orange_impl()
    {
    }

    int
    orange_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {

      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

	int i = 0;
	int j = 0;
	int ctr = 0;

	while(i < noutput_items) { 
	
		if (in[j] == 0)
			{ 
				out[i++] = offset() - (amplitude()/2);
			}
		if (in[j] == 1)
			{
				out[i++] = offset() + (amplitude()/2);
			}
		ctr++;
		if (ctr >= inte()){ 
			ctr = 0;
			j++;
		}
			} 
    

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace OOKz */
} /* namespace gr */

