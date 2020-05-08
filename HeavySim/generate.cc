#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "Pythia8/Pythia.h"

#include "TFile.h"
#include "TTree.h"

#include "analysis/funcional_filter.h"
#include "container/reduced_event.h"
#include "container/reduced_particle.h"
#include "pythia_event_utils.h"
#include "pythia_particle_utils.h"

namespace filter = analysis::filter;

int main(int argc, char** argv);

/* Reads the arguments given to the program and sets the values of the seed,
 * number of events and tune.
 */
void ConfigureFromInput(std::vector<std::string> arguments, int& seed,
                        int& n_events, int& tune);

int main(int argc, char** argv) {
  // Configuring the settings of the program: Seed, number of events and pythia
  std::vector<std::string> arguments(argv + 1, argv + argc);

  int seed, n_events, tune;
  ConfigureFromInput(arguments, seed, n_events, tune);

  std::cout << "Setting seed to " << seed << std::endl;
  std::cout << "Setting Number of events to " << n_events << std::endl;
  std::cout << "Setting tune to " << tune << std::endl;

  // Creates the TTree output
  TFile file("tree.root", "RECREATE");
  TTree tree("event", "event");

  container::ReducedEvent event;
  tree.Branch("event", &event);

  // Set up Pythia
  Pythia8::Pythia pythia;
  pythia.readString("SoftQCD:all= on");
  pythia.readString("Beams:eCM = 13000.");
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = " + std::to_string(seed));
  pythia.init();

  for (int i_event(0); i_event < n_events; ++i_event) {
    pythia.next();

    auto particle_kine = filter::FilterKinematics(pythia.event);

    auto d0 = filter::FilterParticles(pythia.event, particle_kine, {421});
    std::vector<container::ReducedParticle> reduced_d0;

    for (auto i : d0) {
      const auto& part = pythia.event[i];

      auto red_part = container::ReducedParticle(
          part.pT(), part.pz(), part.phi(), part.eta(), part.index(), part.id(),
          analysis::CheckOrigin(pythia.event, part.index()));

      reduced_d0.push_back(red_part);
    }

    event = container::ReducedEvent(
        int(analysis::ClassifyHFProcess(pythia.event)), reduced_d0);
    tree.Fill();
  }

  tree.Print();
  file.Write();

  return 0;
}

void ConfigureFromInput(std::vector<std::string> arguments, int& seed,
                        int& n_events, int& tune) {
  seed = 13;
  n_events = 100;
  tune = -1;

  switch (arguments.size()) {
    case 0: {
      std::cout << "The arguments are: Number of events, Seed and Tune. None "
                   "were provided. Setting them to default values;"
                << std::endl;
      break;
    }
    case 1: {
      n_events = int(std::stol(arguments[0]));
      break;
    }
    case 2: {
      n_events = int(std::stol(arguments[0]));
      seed = int(std::stol(arguments[1]));
      break;
    }
    case 3: {
      n_events = int(std::stol(arguments[0]));
      seed = int(std::stol(arguments[1]));
      tune = int(std::stol(arguments[2]));
      break;
    }
    default: {
      std::cout << "Only 3 arguments are supported. The rest was ignored."
                << std::endl;
      n_events = int(std::stol(arguments[0]));
      seed = int(std::stol(arguments[1]));
      tune = int(std::stol(arguments[2]));
    }
  }
}
