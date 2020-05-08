#include "pythia_event_utils.h"
#include "Pythia8/Pythia.h"

namespace analysis {

int ClassifyHFProcess(Pythia8::Event event) {
  int process = 0;
  std::vector<int> outcome_particles;

  //Particles with status == 23 are the outcoming particles of the hardest subprocess
  for (int i = 0; i < event.size(); i++) {
    if (event[i].statusAbs() == 23) outcome_particles.push_back(i);
  }

  for (auto i : outcome_particles) {
    if ((event[i].idAbs() == 4) || (event[i].idAbs() == 5)) process++;
  }
  return process;
}

}
