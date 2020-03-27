#ifndef REDUCED_PARTICLE_H_
#define REDUCED_PARTICLE_H_

#include <vector>
#include "Pythia8/Pythia.h"

namespace analysis {

/* Given an event and a list of the position of the particles in this event,
 * finds their mothers, recursively. Returns a vector with the position of
 * all the chain of mother of the particles.
 */
std::vector<int> FindMothers(const Pythia8::Event& event,
                             const std::vector<int>& places);

/* Gets an event and a the position of particles in the event
Returns the 4 if the particle comes from charm, 5 if it comes from beauty or -1
otherwise.
*/
int CheckOrigin(const Pythia8::Event& event, int position);

/* Storage for particle information level.
 */
class ReducedParticle {
 private:
  // Kinematics
  float pt_{-999.};
  float pz_{-999.};
  float phi_{-999.};
  float eta_{-999.};

  // MC information
  int index_{0};
  int pdg_{0};
  int origin_{0};

 public:
  ReducedParticle() = default;

  // Creates a particle given the particle and the event.
  ReducedParticle(const Pythia8::Particle& part, const Pythia8::Event& event);

  // Creates a particle given the position of it in the event.
  ReducedParticle(int position, const Pythia8::Event& event)
      : ReducedParticle(event[position], event){};

  ~ReducedParticle() = default;

  float Pt() const { return pt_; };
};

}  // namespace analysis

#endif  // REDUCED_PARTICLE_H_