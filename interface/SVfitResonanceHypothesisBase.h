#ifndef AnalysisDataFormats_SVfit_SVfitResonanceHypothesisBase_h
#define AnalysisDataFormats_SVfit_SVfitResonanceHypothesisBase_h

#include "DataFormats/Common/interface/OwnVector.h"

#include "DataFormats/Candidate/interface/Candidate.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

#include <string>

class SVfitResonanceHypothesisBase
{
 public:

  SVfitResonanceHypothesisBase() 
    : mass_(-1.),
      massErrUp_(0.),
      massErrDown_(0.),
      isValidSolution_(false) 
  {}
  SVfitResonanceHypothesisBase(const SVfitResonanceHypothesisBase&);
  virtual ~SVfitResonanceHypothesisBase() {}

  virtual SVfitResonanceHypothesisBase* clone() const { return new SVfitResonanceHypothesisBase(*this); }

  virtual SVfitResonanceHypothesisBase& operator=(const SVfitResonanceHypothesisBase&);

  const std::string& name() const { return name_; }
  int barcode() const { return barcode_; }

  /// mean and median reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass() const { return mass_; }
  double massErrUp() const { return massErrUp_; }
  double massErrDown() const { return massErrDown_; }

  bool isValidSolution() const { return isValidSolution_; }

  /// fit hypotheses of daughter particles
  size_t numDaughters() const { return daughters_.size(); }
  SVfitSingleParticleHypothesisBase* daughter(size_t idx) { return &daughters_[idx]; }
  const SVfitSingleParticleHypothesisBase* daughter(size_t idx) const { return &daughters_[idx]; }
  const SVfitSingleParticleHypothesisBase* daughter(const std::string& name) const
  {
    const SVfitSingleParticleHypothesisBase* retVal = 0;
    for ( edm::OwnVector<SVfitSingleParticleHypothesisBase>::const_iterator daughter = daughters_.begin();
	  daughter != daughters_.end(); ++daughter ) {
      if ( daughter->name() == name ) retVal = &(*daughter);
    }
    return retVal;
  }

  virtual void print(std::ostream& stream) const
  {
    stream << "<SVfitResonanceHypothesisBase::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    stream << " barcode = " << barcode_ << std::endl;
    reco::Candidate::LorentzVector daughterP4Sum;
    for ( edm::OwnVector<SVfitSingleParticleHypothesisBase>::const_iterator daughter = daughters_.begin();
          daughter != daughters_.end(); ++daughter ) {
      if ( daughter->particle().isNonnull() ) daughterP4Sum += daughter->particle()->p4();
    }
    stream << " mass = " << mass_ << " + " << massErrUp_ << " - " << massErrDown_ 
	   << " (unfitted = " << daughterP4Sum.mass() << ")" << std::endl;
    stream << " isValidSolution = " << isValidSolution_ << std::endl;
    for ( edm::OwnVector<SVfitSingleParticleHypothesisBase>::const_iterator daughter = daughters_.begin();
          daughter != daughters_.end(); ++daughter ) {
      daughter->print(stream);
    }
  }

  friend class SVfitResonanceBuilderBase;
  friend class SVfitResonanceBuilderW;
  friend class SVfitAlgorithmBase;
  friend class SVfitAlgorithmByLikelihoodMaximization;
  friend class SVfitAlgorithmByIntegration2;

 protected:

  /// "human-readable" label for print-out
  std::string name_;

  /// unique identifier to associate hypothesis to likelihood function
  int barcode_; 

  /// fit hypotheses for daughter particles
  edm::OwnVector<SVfitSingleParticleHypothesisBase> daughters_;

  /// "best fit" reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass_;
  double massErrUp_;
  double massErrDown_;

  /// flag indicating that computed mass hypotheses are physically "valid" solutions
  bool isValidSolution_;
};

// CV: implementation of operator< needed to store SVfitResonanceHypothesisBase objects in edm::OwnVector
bool operator<(const SVfitResonanceHypothesisBase&, const SVfitResonanceHypothesisBase&);

#endif
