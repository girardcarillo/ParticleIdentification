/// \file falaise/snemo/cuts/channel_1eNg_cut.h
/* Author(s)     : Xavier Garrido <garrido@lal.in2p3.fr>
 * Creation date : 2015-03-18
 * Last modified : 2015-03-18
 *
 * Copyright (C) 2015 Xavier Garrido <garrido@lal.in2p3.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Description:
 *
 *   Channel_1eNg event cut.
 *
 * History:
 *
 */

#ifndef FALAISE_SNEMO_CUT_CHANNEL_1ENG_CUT_H
#define FALAISE_SNEMO_CUT_CHANNEL_1ENG_CUT_H 1

#include <falaise/snemo/cuts/base_channel_cut.h>

namespace snemo {

  namespace cut {

    /// \brief A channel_1eNg event cut
    class channel_1eNg_cut : public base_channel_cut
    {
    public:

      /// Check mode HAS_NUMBER_OF_GAMMAS
      virtual bool is_mode_has_number_of_gammas() const;

      /// Check mode RANGE_NUMBER_OF_GAMMAS
      virtual bool is_mode_range_number_of_gammas() const;

      /// Constructor
      channel_1eNg_cut(datatools::logger::priority logging_priority_ = datatools::logger::PRIO_FATAL);

      /// Destructor
      virtual ~channel_1eNg_cut();

      /// Initilization
      virtual void initialize(const datatools::properties & configuration_,
                              datatools::service_manager & service_manager_,
                              cuts::cut_handle_dict_type & cut_dict_);

      /// Reset
      virtual void reset();

    protected:

      /// Default values
      void _set_defaults();

      /// Selection
      virtual int _accept();

    private:

      int _number_of_gammas_min_;
      int _number_of_gammas_max_;

      // Macro to automate the registration of the cut :
      CUT_REGISTRATION_INTERFACE(channel_1eNg_cut);
    };

  }  // end of namespace cut

}  // end of namespace snemo

#endif // FALAISE_SNEMO_CUT_CHANNEL_1ENG_CUT_H

/*
** Local Variables: --
** mode: c++ --
** c-file-style: "gnu" --
** End: --
*/
