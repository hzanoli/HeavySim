#ifndef HEAVYSIM_CONTAINER_REDUCED_PARTICLE_CC_PYTHIA_PARTICLE_UTILS_H_
#define HEAVYSIM_CONTAINER_REDUCED_PARTICLE_CC_PYTHIA_PARTICLE_UTILS_H_

#include <vector>
#include "Pythia8/Pythia.h"

namespace analysis {
/* Given an event and a list of the position of the particles in this event,
 * finds their mothers, recursively. Returns a vector with the position of
 * all the chain of mother of the particles.
 */
std::vector<int> FindMothers(const Pythia8::Event& event,
                             const std::vector<int>& places);

/* Gets an event and a the position of one particle in this event.
 * Returns the 4 if this particle comes from charm, 5 if it comes from beauty,
 * or -1 otherwise.
 */
int CheckOrigin(const Pythia8::Event& event, int position);

}  // namespace analysis

#endif  // HEAVYSIM_CONTAINER_REDUCED_PARTICLE_CC_PYTHIA_PARTICLE_UTILS_H_
