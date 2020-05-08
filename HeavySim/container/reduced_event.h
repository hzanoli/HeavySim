#ifndef REDUCED_EVENT_H_
#define REDUCED_EVENT_H_

#include <vector>
#include "Pythia8/Pythia.h"
#include "reduced_particle.h"

namespace container {

class ReducedEvent {
 private:
  int process_{-1};
  std::vector<ReducedParticle> particles_;

 public:
  ReducedEvent() = default;
  ReducedEvent(int process, const std::vector<ReducedParticle>& particles)
      : process_(process), particles_(particles) {}
  ~ReducedEvent() = default;

  const std::vector<ReducedParticle>& Particles() const { return particles_; }
  int Process() const { return process_; }



};

}  // namespace analysis

#endif  // REDUCED_EVENT_H_
