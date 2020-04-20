#ifndef REDUCED_PARTICLE_H_
#define REDUCED_PARTICLE_H_

#include <vector>

namespace container {

// Storage for particle information level.
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

  // Creates a particle by providing each value
  ReducedParticle(float pt, float pz, float phi, float eta, int index, int pdg,
                  int origin)
      : pt_(pt),
        pz_(pz),
        phi_(phi),
        eta_(eta),
        index_(index),
        pdg_(pdg),
        origin_(origin){};

  ~ReducedParticle() = default;

  float Pt() const { return pt_; };

  float Pz() const { return pz_; };

  float Phi() const { return phi_; };

  float Eta() const { return eta_; };

  int Index() const {return index_; };

  int Pdg() const { return pdg_; };
  int PDG() const { return Pdg(); };
  int PdgCode() const {return Pdg(); };

  int Origin() const {return origin_;}

};

}  // namespace analysis

#endif  // REDUCED_PARTICLE_H_