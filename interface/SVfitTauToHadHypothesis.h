#ifndef AnalysisDataFormats_SVfit_SVfitTauToHadHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitTauToHadHypothesis_h

/*
 * SVfitTauToHadHypothesis
 *
 * Class to store information about tau lepton decay into hadrons.
 *
 * NOTE: this class is used to make persistent solutions of SVfitAlgorithmByLikelihoodMaximization;
 *       solutions of SVfitAlgorithmByIntegration are of type SVfitTauDecayHypothesis
 *
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitTauDecayHypothesis.h"

class SVfitTauToHadHypothesis : public SVfitTauDecayHypothesis
{
 public:

  SVfitTauToHadHypothesis() {}
  SVfitTauToHadHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : SVfitTauDecayHypothesis(particle, name, barcode)
  {
    //std::cout << "<SVfitTauToHadHypothesis::SVfitTauToHadHypothesis>:" << std::endl;
    //std::cout << " constructor(const edm::Ptr<reco::Candidate>&, std::string, int)" << std::endl;
    p4_ = particle->p4();
  }
  SVfitTauToHadHypothesis(const SVfitTauToHadHypothesis& bluePrint)
    : SVfitTauDecayHypothesis(bluePrint),
      decay_angle_VMrho_(bluePrint.decay_angle_VMrho_),
      mass2_VMrho_(bluePrint.mass2_VMrho_),
      decay_angle_VMa1_(bluePrint.decay_angle_VMa1_),
      decay_angle_VMa1r_theta_(bluePrint.decay_angle_VMa1r_theta_),
      decay_angle_VMa1r_phi_(bluePrint.decay_angle_VMa1r_phi_),
      mass2_VMa1_(bluePrint.mass2_VMa1_)
  {}
  ~SVfitTauToHadHypothesis() {}

  SVfitTauToHadHypothesis* clone() const { return new SVfitTauToHadHypothesis(*this); }
  SVfitSingleParticleHypothesisBase* reduceToBase() const { 
    return new SVfitTauToHadHypothesis(this->particle_, this->name_, this->barcode_);
  }

  SVfitTauToHadHypothesis& operator=(const SVfitTauToHadHypothesis& bluePrint)
  {
    SVfitTauDecayHypothesis::operator=(bluePrint);
    decay_angle_VMrho_ = bluePrint.decay_angle_VMrho_;
    mass2_VMrho_ = bluePrint.mass2_VMrho_;
    decay_angle_VMa1_ = bluePrint.decay_angle_VMa1_;
    decay_angle_VMa1r_theta_ = bluePrint.decay_angle_VMa1r_theta_;
    decay_angle_VMa1r_phi_ = bluePrint.decay_angle_VMa1r_phi_;
    mass2_VMa1_ = bluePrint.mass2_VMa1_;
    return (*this);
  }

  /// decay angles and masses of intermediate vector-meson resonances
  double decay_angle_VMrho() const { return decay_angle_VMrho_; }
  double mass2_VMrho() const { return mass2_VMrho_; }
  double decay_angle_VMa1() const { return decay_angle_VMa1_; }
  double decay_angle_VMa1r_theta() const { return decay_angle_VMa1r_theta_; }
  double decay_angle_VMa1r_phi() const { return decay_angle_VMa1r_phi_; }
  double mass2_VMa1() const { return mass2_VMa1_; }

  friend class SVfitTauToHadBuilder;

 private:

  /// decay angles and masses of intermediate vector-meson resonances
  double decay_angle_VMrho_;
  double mass2_VMrho_;
  double decay_angle_VMa1_;
  double decay_angle_VMa1r_theta_;
  double decay_angle_VMa1r_phi_;
  double mass2_VMa1_;
};

#endif
