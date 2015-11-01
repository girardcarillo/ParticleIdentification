// test_angle_driver.cxx

// Standard library:
#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>

// This project:
#include <falaise/snemo/datamodels/particle_track.h>
#include <falaise/snemo/reconstruction/angle_driver.h>

int main()
{
  int error_code = EXIT_SUCCESS;
  try {
    std::clog << "Test program for the 'angle_driver' class." << std::endl;

    snemo::reconstruction::angle_driver AD;
    datatools::properties AD_config;
    AD_config.store("logging.priority", "debug");
    AD.initialize(AD_config);

    // Fake electron track :
    {
      snemo::datamodel::particle_track electron;
      // Push some fake calorimeter hits
      {
        snemo::datamodel::calibrated_calorimeter_hit::collection_type & the_calos
          = electron.grab_associated_calorimeter_hits();
        the_calos.push_back(new snemo::datamodel::calibrated_calorimeter_hit);
        snemo::datamodel::calibrated_calorimeter_hit & a_calo = the_calos.back().grab();
        a_calo.set_energy(1000 * CLHEP::keV);
      }
      electron.tree_dump();
      double angle = datatools::invalid_real();
      // ED.process(electron, energy);
      // std::clog << "Electron energy = " << energy/CLHEP::keV << " keV" << std::endl;
    }

    // Fake gamma track :
    {
      snemo::datamodel::particle_track gamma;
      // Push some fake calorimeter hits
      {
        snemo::datamodel::calibrated_calorimeter_hit::collection_type & the_calos
          = gamma.grab_associated_calorimeter_hits();
        the_calos.push_back(new snemo::datamodel::calibrated_calorimeter_hit);
        snemo::datamodel::calibrated_calorimeter_hit & a_calo1 = the_calos.back().grab();
        a_calo1.set_energy(500 * CLHEP::keV);
        the_calos.push_back(new snemo::datamodel::calibrated_calorimeter_hit);
        snemo::datamodel::calibrated_calorimeter_hit & a_calo2 = the_calos.back().grab();
        a_calo2.set_energy(1000 * CLHEP::keV);
      }
      gamma.tree_dump();
      double angle = datatools::invalid_real();
      // ED.process(gamma, energy);
      // std::clog << "Gamma energy = " << energy/CLHEP::keV << " keV" << std::endl;
    }

  } catch (std::exception & x) {
    std::cerr << "error: " << x.what() << std::endl;
    error_code = EXIT_FAILURE;
  } catch (...) {
    std::cerr << "error: " << "unexpected error !" << std::endl;
    error_code = EXIT_FAILURE;
  }
  return error_code;
}
