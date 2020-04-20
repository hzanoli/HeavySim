#include <vector>
#include "Pythia8/Pythia.h"

namespace analysis {
namespace filter {
/* Takes as input a PYTHIA event and a maximum value eta_max that the particle
 pseudorapidity can have. Returns a vector with the index of particles that
 are have an absolute pseudorapidity smaller than eta_max.
 */
std::vector<int> FilterKinematics(const Pythia8::Event& event,
                                  double eta_max = 0.8);

/* Finds if a value of type T is in is in vector.
Returns true if value is in vector, false otherwise
*/
template <typename T>
inline bool IsInVector(T value, std::vector<T> vector) {
  return std::find(vector.begin(), vector.end(), value) != vector.end();
}

/* Takes as input a vector with the index of particles and a vector with the PDG
code of the particles that will be filtered. Returns the particles which the
absolute value of the PDG code is in particle_ids*/
std::vector<int> FilterParticles(const Pythia8::Event& event,
                                 const std::vector<int>& particles,
                                 std::vector<int> particle_ids = {411, 421, 413,
                                                                  431});

}  // namespace filter
}  // namespace analysis
