#ifndef AnalysisDataFormats_SVfit_SVfitResonanceHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitResonanceHypothesis_h

#include "DataFormats/Common/interface/OwnVector.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesis.h"

#include <string>

class SVfitEventHypothesis;

class SVfitResonanceHypothesis : public SVfitResonanceHypothesisBase
{
 public:

  SVfitResonanceHypothesis();
  SVfitResonanceHypothesis(const SVfitResonanceHypothesis&);
  virtual ~SVfitResonanceHypothesis() {}

  virtual SVfitResonanceHypothesis* clone() const { return new SVfitResonanceHypothesis(*this); }

  virtual SVfitResonanceHypothesis& operator=(const SVfitResonanceHypothesis&);

  const SVfitEventHypothesis* eventHypothesis() const { return eventHyp_; }
  void setEventHypothesis(const SVfitEventHypothesis* input) 
  {
    eventHyp_ = input;
  }

  /// fit hypotheses of daughter particles
  SVfitSingleParticleHypothesis* daughter(size_t idx) { return dynamic_cast<SVfitSingleParticleHypothesis*>(&daughters_[idx]); }
  const SVfitSingleParticleHypothesis* daughter(size_t idx) const { 
    return dynamic_cast<const SVfitSingleParticleHypothesis*>(&daughters_[idx]); 
  }
  
  /// momentum of particle before fit, after fit
  /// and difference in momentum (after - before) fit
  reco::Candidate::LorentzVector p4() const { return p4_; }
  reco::Candidate::LorentzVector p4_fitted() const { return (p4_ + dp4_); }
  reco::Candidate::LorentzVector dp4_fitted() const { return dp4_; }

  /// mean and median plus -1 sigma and +1 sigma limits on 
  /// reconstructed Pt, eta, phi
  ///
  /// NOTE: Pt, eta, phi will be valid only in case
  ///       SVfitAlgorithmByIntegration2 algorithm (Markov Chain integration) is used
  ///  
  double pt() const { return pt_; }
  double ptErrUp() const { return ptErrUp_; }
  double ptErrDown() const { return ptErrDown_; }
  bool pt_isValid() const { return pt_isValid_; }
  double eta() const { return eta_; }
  double etaErrUp() const { return etaErrUp_; }
  double etaErrDown() const { return etaErrDown_; }
  bool eta_isValid() const { return eta_isValid_; }
  double phi() const { return phi_; }
  double phiErrUp() const { return phiErrUp_; }
  double phiErrDown() const { return phiErrDown_; }
  bool phi_isValid() const { return phi_isValid_; }

  double dPhiVis() const { return dPhiVis_; }

  double prod_angle_rf() const { return prod_angle_rf_; }

  virtual void print(std::ostream& stream) const
  {
    stream << "<SVfitResonanceHypothesis::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    stream << " barcode = " << barcode_ << std::endl;
    stream << " p4: Pt = " << p4_.pt() << ","
	   << " eta = " << p4_.eta() << ", phi = " << p4_.phi() << ", mass = " << p4_.mass() << std::endl;
    stream << " p4_fitted: Pt = " << p4_fitted().pt() << ","
	   << " eta = " << p4_fitted().eta() << ", phi = " << p4_fitted().phi() << ",";
    if ( mass_ >= 0. ) stream << " mass = " << mass_ << " + " << massErrUp_ << " - " << massErrDown_ << std::endl;
    else stream << " mass = " << p4_fitted().mass() << std::endl;
    stream << "(prod. angle = " << prod_angle_rf_ << ")" << std::endl;
    stream << " isValidSolution = " << isValidSolution_ << std::endl;
    for ( edm::OwnVector<SVfitSingleParticleHypothesisBase>::const_iterator daughter = daughters_.begin();
          daughter != daughters_.end(); ++daughter ) {
      daughter->print(stream);
    }
  }

  unsigned numPolStates() const { return numPolStates_; }
  int polHandedness(unsigned idx) const { return polHandedness_[idx]; }

  enum { kPolUndefined, kPolLR, kPolRL, kPolLL, kPolRR, kPolWL, kPolWR, kPolWT };

  friend class SVfitEventBuilder;
  friend class SVfitResonanceBuilderBase;
  friend class SVfitResonanceBuilder;
  friend class SVfitResonanceBuilderW;
  friend class SVfitAlgorithmByLikelihoodMaximization;
  friend class SVfitAlgorithmByIntegration2;
  friend class SVfitResonanceLikelihoodMatrixElementW;
  template<typename T1, typename T2> friend class CompositePtrCandidateT1T2MEt;

 private:

  /// pointer to event hypothesis object
  const SVfitEventHypothesis* eventHyp_;

  /// momentum of particle before fit
  reco::Candidate::LorentzVector p4_;  

  /// difference in momentum (after - before) fit
  reco::Candidate::LorentzVector dp4_;

  /// "best fit" reconstructed Pt, eta, phi 
  /// plus -1 sigma and +1 sigma limits
  ///
  /// NOTE: uncertainties on Pt, eta, phi will be valid only in case
  ///       SVfitAlgorithmByIntegration2 algorithm (Markov Chain integration) is used
  ///  
  double pt_;
  double ptErrUp_;
  double ptErrDown_;
  bool pt_isValid_;
  double eta_;
  double etaErrUp_;
  double etaErrDown_;
  bool eta_isValid_;
  double phi_;
  double phiErrUp_;
  double phiErrDown_;
  bool phi_isValid_;

  /// azimuthal angle between visible tau decay products
  double dPhiVis_;
  
  /// production angle of tau lepton in rest-frame of tau+ tau- pair
  double prod_angle_rf_;

  /// different possible polarization states
  std::vector<int> polHandedness_;
  std::vector<int> polSign_;
  unsigned numPolStates_;
};

#endif
