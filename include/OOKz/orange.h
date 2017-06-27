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


#ifndef INCLUDED_OOKZ_ORANGE_H
#define INCLUDED_OOKZ_ORANGE_H

#include <OOKz/api.h>
#include <gnuradio/sync_interpolator.h>

namespace gr {
  namespace OOKz {

    /*!
     * \brief <+description of block+>
     * \ingroup OOKz
     *
     */
    class OOKZ_API orange : virtual public gr::sync_interpolator
    {
     public:
      typedef boost::shared_ptr<orange> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of OOKz::orange.
       *
       * To avoid accidental use of raw pointers, OOKz::orange's
       * constructor is in a private implementation
       * class. OOKz::orange::make is the public interface for
       * creating new instances.
       */
      static sptr make(float inte, int amplitude, int offset );

      virtual void d_inte(float inte) = 0;
      virtual float inte() = 0;

      virtual void d_amplitude(int amplitude) = 0;
      virtual int amplitude() = 0;

      virtual void d_offset(int offset) = 0;
      virtual int offset() = 0;
	
    };

  } // namespace OOKz
} // namespace gr

#endif /* INCLUDED_OOKZ_ORANGE_H */

