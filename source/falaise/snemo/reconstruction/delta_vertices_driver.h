/** \file falaise/snemo/reconstruction/delta_vertices_driver.h
 * Author(s)     : Xavier Garrido <garrido@lal.in2p3.fr>
 * Creation date : 2012-10-07
 * Last modified : 2014-02-09
 *
 * Copyright (C) 2012-2014 Xavier Garrido <garrido@lal.in2p3.fr>
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
 *   A driver class that wraps the GammaClustering algorithm.
 *
 * History:
 *
 */

#ifndef FALAISE_DELTA_VERTICES_PLUGIN_SNEMO_RECONSTRUCTION_DELTA_VERTICES_DRIVER_H
#define FALAISE_DELTA_VERTICES_PLUGIN_SNEMO_RECONSTRUCTION_DELTA_VERTICES_DRIVER_H 1

// Standard library:
#include <string>
#include <list>
#include <map>
#include <vector>

// Third party:
// - Boost:
#include <boost/scoped_ptr.hpp>

// - Bayeux/datatools:
#include <datatools/logger.h>
#include <datatools/properties.h>

// This project:
#include <falaise/snemo/datamodels/particle_track.h>

namespace geomtools {
  class manager;
}

namespace snemo {

  namespace datamodel {
    class particle_track_data;
  }
  namespace datamodel {
    class topology_data;
  }

  namespace geometry {
    class locator_plugin;
  }

  namespace reconstruction {

    /// Driver for the gamma clustering algorithms
    class delta_vertices_driver
    {
    public:

      static const std::string & delta_vertices_id();

      /// Check the geometry manager
      bool has_geometry_manager() const;

      /// Address the geometry manager
      void set_geometry_manager(const geomtools::manager & gmgr_);

      /// Return a non-mutable reference to the geometry manager
      const geomtools::manager & get_geometry_manager() const;

      /// Setting logging priority
      void set_logging_priority(const datatools::logger::priority priority_);

      /// Getting logging priority
      datatools::logger::priority get_logging_priority() const;

      /// Constructor
      delta_vertices_driver();

      /// Destructor
      ~delta_vertices_driver();

      //Main process
      int process(double & delta_vertices_y,
                  double & _delta_vertices_z,
                  snemo::datamodel::particle_track & pt1_,
                  snemo::datamodel::particle_track & pt2_);

      /// Check if theclusterizer is initialized
      bool is_initialized() const;

      /// Initialize the gamma tracker through configuration properties
      void initialize(const datatools::properties & setup_);

      /// Reset the clusterizer
      void reset();

    protected:

      /// Set the initialization flag
      void _set_initialized(bool);

      /// Special method to process and generate particle track data
      int _process_algo(double & delta_vertices_y,
                        double & delta_vertices_z,
                        snemo::datamodel::particle_track & pt1_,
                        snemo::datamodel::particle_track & pt2_);

      /// Give default values to specific class members.
      void _set_defaults ();

    private:
      bool                                 _initialized_;            //!< Initialization status
      datatools::logger::priority _logging_priority_; //!< Logging priority
      double _sigma_t_gamma_interaction_uncertainty_;     //!< The uncertainty on the track length
      datatools::properties _delta_vertices_setup_;                         //!< The Gamma Clustering parameters
      const geomtools::manager *           _geometry_manager_;       //!< The SuperNEMO geometry manager
      // for members
    };

  }  // end of namespace reconstruction

}  // end of namespace snemo


// Declare the OCD interface of the module
#include <datatools/ocd_macros.h>
DOCD_CLASS_DECLARATION(snemo::reconstruction::delta_vertices_driver)

#endif // FALAISE_DELTA_VERTICES_PLUGIN_SNEMO_RECONSTRUCTION_DELTA_VERTICES_DRIVER_H

/*
** Local Variables: --
** mode: c++ --
** c-file-style: "gnu" --
** tab-width: 2 --
** End: --
*/
