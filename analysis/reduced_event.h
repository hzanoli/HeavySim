#ifndef REDUCED_EVENT_H_
#define REDUCED_EVENT_H_

#include <vector>
#include "Pythia8/Pythia.h"
#include "reduced_particle.h"

namespace analysis {

/*
Given a pythia event, returns the number of heavy-flavour (charm or beauty)
quarks that are outgoing particles of the hardest subprocess. 
The different number of HF process are 
*/

int ClassifyHFProcess(Pythia8::Event event);

class ReducedEvent {
 private:
  int process_{-1};
  std::vector<ReducedParticle> particles_;

 public:
  ReducedEvent() = default;
  ReducedEvent(const Pythia8::Event& event,
               std::vector<ReducedParticle>& particles_to_save);
  ~ReducedEvent() = default;
};

}  // namespace analysis

#endif  // REDUCED_EVENT_H_
