#include "filter.h"
#include <vector>
#include "Pythia8/Pythia.h"

namespace analysis {

namespace filter {

std::vector<int> FilterKinematics(const Pythia8::Event& event, double eta_max) {
  std::vector<int> filtered_particles;
  filtered_particles.reserve(event.size());

  for (int i = 0; i < event.size(); ++i) {
    auto& particle = event[i];
    if (fabs(particle.eta()) > eta_max) continue;

    filtered_particles.push_back(i);
  }
  filtered_particles.shrink_to_fit();

  return filtered_particles;
}

std::vector<int> FilterParticles(const Pythia8::Event& event,
                                 const std::vector<int>& particles,
                                 std::vector<int> particle_ids) {
  std::vector<int> filtered_particles;
  filtered_particles.reserve(particles.size());

  for (auto& i : particles) {
    auto particle = event[i];
    if (IsInVector(int(particle.idAbs()), particle_ids)) {
      filtered_particles.push_back(i);
    }
  }

  filtered_particles.shrink_to_fit();
  return filtered_particles;
}

}  // namespace filter

}  // namespace analysis
