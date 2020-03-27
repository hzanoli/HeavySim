#include "reduced_particle.h"
#include "Pythia8/Pythia.h"

namespace analysis {

ReducedParticle::ReducedParticle(const Pythia8::Particle& part,
                                 const Pythia8::Event& event) {
  pt_ = part.pT();
  pz_ = part.pz();
  phi_ = part.phi();
  eta_ = part.eta();

  index_ = part.index();
  pdg_ = part.id();
  origin_ = CheckOrigin(event, part.index());
}

std::vector<int> FindMothers(const Pythia8::Event& event,
                             const std::vector<int>& places) {
  std::vector<int> list_mothers;
  list_mothers.reserve(event.size());

  for (auto no : places) {
    auto mothers_current_particle = event[no].motherList();

    list_mothers.insert(list_mothers.end(), mothers_current_particle.begin(),
                        mothers_current_particle.end());

    auto mother_of_mothers = FindMothers(event, mothers_current_particle);

    list_mothers.insert(list_mothers.end(), mother_of_mothers.begin(),
                        mother_of_mothers.end());
  }
  
  list_mothers.shrink_to_fit();

  return list_mothers;
}

int CheckOrigin(const Pythia8::Event& event, int position) {
  auto mother_list = FindMothers(event, {position});

  for (auto mother_no : mother_list) {
    int id = event[mother_no].idAbs();
    if (id == 5) return 5;
  }

  for (auto mother_no : mother_list) {
    int id = event[mother_no].idAbs();
    if (id == 4) return 4;
  }

  return -1;
}

}  // namespace analysis