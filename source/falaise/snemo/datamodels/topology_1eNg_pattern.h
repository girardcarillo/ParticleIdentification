/// \file falaise/snemo/datamodels/topology_1e1Ng_pattern.h
/* Author(s) :    François Mauger <mauger@lpccaen.in2p3.fr>
 * Creation date: 2012-03-19
 * Last modified: 2014-01-27
 *
 * Description: The 1e1Ng class of trajectory patterns
 */

#ifndef FALAISE_SNEMO_DATAMODEL_TOPOLOGY_1ENG_PATTERN_H
#define FALAISE_SNEMO_DATAMODEL_TOPOLOGY_1ENG_PATTERN_H 1

// Standard library:
#include <string>

// This project:
#include <falaise/snemo/datamodels/base_topology_pattern.h>
#include <falaise/snemo/datamodels/topology_measurement.h>

namespace snemo {

  namespace datamodel {

    /// \brief The 1e1Ng class of reconstructed topology
    class topology_1eNg_pattern : public base_topology_pattern
    {
    public:

      /// Typedef for TOF dictionnary
      typedef std::vector<TOF_measurement> TOF_collection_type;

      /// Typedef for TOF dictionnary
      typedef std::vector<angle_measurement> angle_collection_type;

      /// Return pattern identifier of the pattern
      static const std::string & pattern_id();

      /// Constructor
      topology_1eNg_pattern();

      /// Destructor
      virtual ~topology_1eNg_pattern();

      /// Set number of gammas
      void set_number_of_gammas(const size_t ngammas_);

      /// Return internal probability
      size_t get_number_of_gammas() const;

      /// Return a non mutable reference to the TOF collection
      const TOF_collection_type & get_TOF_collection() const;

      /// Return a mutable reference to the TOF dictionary
      TOF_collection_type & grab_TOF_collection();

      /// Return a non mutable reference to the angle collection
      const angle_collection_type & get_angle_collection() const;

      /// Return a mutable reference to the angle dictionary
      angle_collection_type & grab_angle_collection();


      /// Smart print
      virtual void tree_dump(std::ostream      & out_    = std::clog,
                             const std::string & title_  = "",
                             const std::string & indent_ = "",
                             bool inherit_               = false) const;

    private:

      size_t _number_of_gammas_;
      TOF_collection_type _tofs_;
      angle_collection_type _angles_;

      DATATOOLS_SERIALIZATION_DECLARATION();

    };

  } // end of namespace datamodel

} // end of namespace snemo

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_KEY2(snemo::datamodel::topology_1eNg_pattern,
                        "snemo::datamodel::topology_1eNg_pattern")

#endif // FALAISE_SNEMO_DATAMODEL_TOPOLOGY_1ENG_PATTERN_H

/*
** Local Variables: --
** mode: c++ --
** c-file-style: "gnu" --
** tab-width: 2 --
** End: --
*/