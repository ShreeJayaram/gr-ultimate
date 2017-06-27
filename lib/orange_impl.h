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

#ifndef INCLUDED_OOKZ_ORANGE_IMPL_H
#define INCLUDED_OOKZ_ORANGE_IMPL_H

#include <OOKz/orange.h>

namespace gr {
  namespace OOKz {

    class orange_impl : public orange
    {
     private:
	float my_inte;
        int my_offset;
        int my_amplitude;
      

     public:
      orange_impl(float inte, int amplitude, int offset );
      ~orange_impl();

	void d_inte(float inte) { my_inte =  inte; }
        float inte() { return my_inte; } 

        void d_amplitude(int amplitude) { my_amplitude = amplitude; } 
        int amplitude() { return my_amplitude; } 

        void d_offset(int offset) { my_offset = offset; } 
        int offset() { return my_offset; } 

	

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace OOKz
} // namespace gr

#endif /* INCLUDED_OOKZ_ORANGE_IMPL_H */

