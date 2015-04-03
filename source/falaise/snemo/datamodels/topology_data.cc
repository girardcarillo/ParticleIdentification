// topology_data.cc

// Ourselves:
#include <falaise/snemo/datamodels/topology_data.h>

namespace snemo {

  namespace datamodel {


    datatools::properties & topology_data::grab_auxiliaries()
    {
      return _auxiliaries_;
    }

    const datatools::properties & topology_data::get_auxiliaries() const
    {
      return _auxiliaries_;
    }

    void topology_data::reset()
    {
      this->clear();
      return;
    }

    void topology_data::clear()
    {
      _auxiliaries_.clear();
      return;
    }

    topology_data::topology_data()
    {
      return;
    }

    topology_data::~topology_data()
    {
      this->reset();
      return;
    }

    void topology_data::tree_dump(std::ostream      & out_,
                                        const std::string & title_,
                                        const std::string & indent_,
                                        bool inherit_) const
    {
      std::string indent;
      if (! indent_.empty()) {
        indent = indent_;
      }
      if (! title_.empty()) {
        out_ << indent << title_ << std::endl;
      }

      // out_ << indent << datatools::i_tree_dumpable::tag
      //      << "Particle(s) : " << _particles_.size() << std::endl;

      // for (size_t i = 0; i < get_number_of_particles(); i++) {
      //   const particle_track & ptrack = get_particle(i);
      //   std::ostringstream indent2;
      //   out_ << indent << datatools::i_tree_dumpable::skip_tag;
      //   indent2 << indent << datatools::i_tree_dumpable::skip_tag;
      //   if (i == get_number_of_particles() - 1) {
      //     out_ << datatools::i_tree_dumpable::last_tag;
      //     indent2 << datatools::i_tree_dumpable::last_skip_tag;
      //   } else {
      //     out_ << datatools::i_tree_dumpable::tag;
      //     indent2 << datatools::i_tree_dumpable::skip_tag;
      //   }
      //   out_ << "Particle #" << i << " : " << std::endl;
      //   ptrack.tree_dump(out_, "", indent2.str());
      // }

      // const calibrated_calorimeter_hit::collection_type & the_calos = get_non_associated_calorimeters();
      // out_ << indent << datatools::i_tree_dumpable::tag
      //      << "Unassociated calorimeter(s) : " << the_calos.size() << std::endl;
      // for (size_t i = 0; i < the_calos.size(); i++) {
      //   const calibrated_calorimeter_hit & a_calo_hit = the_calos.at(i).get();
      //   std::ostringstream indent2;
      //   out_ << indent << datatools::i_tree_dumpable::skip_tag;
      //   indent2 << indent << datatools::i_tree_dumpable::skip_tag;
      //   if (i == the_calos.size() - 1) {
      //     out_ << datatools::i_tree_dumpable::last_tag;
      //     indent2 << datatools::i_tree_dumpable::last_skip_tag;
      //   } else {
      //     out_ << datatools::i_tree_dumpable::tag;
      //     indent2 << datatools::i_tree_dumpable::skip_tag;
      //   }
      //   out_ << "Hit Id=" << a_calo_hit.get_hit_id()
      //        << " @ " << a_calo_hit.get_geom_id();
      //   out_ << std::endl;
      // }


      // out_ << indent << datatools::i_tree_dumpable::inherit_tag(inherit_)
      //      << "Auxiliaries : ";
      // if (_auxiliaries_.empty()) {
      //   out_ << "<empty>";
      // }
      // out_ << std::endl;
      // {
      //   std::ostringstream indent_oss;
      //   indent_oss << indent;
      //   indent_oss << datatools::i_tree_dumpable::inherit_skip_tag(inherit_) ;
      //   _auxiliaries_.tree_dump(out_, "", indent_oss.str());
      // }

      return;
    }

    // serial tag for datatools::serialization::i_serializable interface :
    DATATOOLS_SERIALIZATION_SERIAL_TAG_IMPLEMENTATION(topology_data, "snemo::datamodel::topology_data")

  } // end of namespace model

} // end of namespace snemo