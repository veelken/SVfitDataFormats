#ifndef AnalysisDataFormats_SVfit_SVfitResonanceHypothesisSummary_h
#define AnalysisDataFormats_SVfit_SVfitResonanceHypothesisSummary_h

#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisSummary.h"

#include <string>

class SVfitResonanceHypothesisSummary
{
 public:

  SVfitResonanceHypothesisSummary() {}
  SVfitResonanceHypothesisSummary(const SVfitResonanceHypothesisSummary&);
  SVfitResonanceHypothesisSummary(const SVfitResonanceHypothesisBase&);
  virtual ~SVfitResonanceHypothesisSummary() {}

  virtual SVfitResonanceHypothesisSummary* clone() const { return new SVfitResonanceHypothesisSummary(*this); }

  virtual SVfitResonanceHypothesisSummary& operator=(const SVfitResonanceHypothesisSummary&);

  void setName(const std::string& name) { name_ = name; }

  const std::string& name() const { return name_; }

  /// mean and median reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass() const { return mass_; }
  double massErrUp() const { return massErrUp_; }
  double massErrDown() const { return massErrDown_; }
  bool mass_isValid() const { return mass_isValid_; }
  
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

  bool isValidSolution() const { return mass_isValid_; }

  virtual void print(std::ostream& stream) const
  {
    stream << "<SVfitResonanceHypothesisSummary::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    if ( mass_isValid_ ) stream << " mass = " << mass_ << " + " << massErrUp_ << " - " << massErrDown_ << std::endl;
    else stream << " mass: no valid solution";
    if ( pt_isValid_   ) stream << " Pt   = " << pt_   << " + " << ptErrUp_   << " - " << ptErrDown_   << std::endl;
    if ( eta_isValid_  ) stream << " eta  = " << eta_  << " + " << etaErrUp_  << " - " << etaErrDown_  << std::endl;
    if ( phi_isValid_  ) stream << " phi  = " << phi_  << " + " << phiErrUp_  << " - " << phiErrDown_  << std::endl;
    for ( edm::OwnVector<SVfitSingleParticleHypothesisSummary>::const_iterator daughter = daughters_.begin();
          daughter != daughters_.end(); ++daughter ) {
      daughter->print(stream);
    }
  }

 protected:

  /// "human-readable" label for print-out
  std::string name_;

  /// fit hypotheses for daughter particles
  edm::OwnVector<SVfitSingleParticleHypothesisSummary> daughters_;

  /// "best fit" reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass_;
  double massErrUp_;
  double massErrDown_;

  /// flag indicating that computed mass hypotheses are physically "valid" solutions
  bool mass_isValid_;

  /// "best fit" reconstructed Pt, eta, phi 
  /// plus -1 sigma and +1 sigma limits  
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
};

#endif
