#ifndef AnalysisDataFormats_SVfit_SVfitEventHypothesisBase_h
#define AnalysisDataFormats_SVfit_SVfitEventHypothesisBase_h

#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/Candidate/interface/Candidate.h" 
#include "DataFormats/METReco/interface/MET.h" 

#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"

#include <TH1.h>

#include <string>

class SVfitEventHypothesisBase
{
 public:

  SVfitEventHypothesisBase() {}
  SVfitEventHypothesisBase(const edm::Ptr<reco::Candidate>& met) 
    : met_(met)
  {}
  SVfitEventHypothesisBase(const SVfitEventHypothesisBase&);
  virtual ~SVfitEventHypothesisBase() {}

  virtual SVfitEventHypothesisBase* clone() const { return new SVfitEventHypothesisBase(*this); }

  virtual SVfitEventHypothesisBase& operator=(const SVfitEventHypothesisBase&);

  const std::string& name() const { return name_; }
  int barcode() const { return barcode_; }

  /// mean and median reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass() const { return mass_; }
  double massErrUp() const { return massErrUp_; }
  double massErrDown() const { return massErrDown_; }

  bool isValidSolution() const { return isValidSolution_; }

  /// pointer to MET object from which this hypothesis was made
  virtual const edm::Ptr<reco::Candidate>& met() const { return met_; }

  /// access to position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  ///
  /// NB: error on position returned by eventVertexErrSVrefitted method not 100% correct,
  ///     as uncertainty on "correction" to primary event vertex position
  ///     determined by SVfit algorithm is not taken into account
  ///
  bool eventVertexIsValid() const { return eventVertexIsValid_; }
  const AlgebraicVector3& reconstructedEventVertexPos() const { return eventVertexPos_; }
  AlgebraicVector3 eventVertexPos() const { return (eventVertexPos_ + eventVertexShift_); }
  const AlgebraicSymMatrix33& eventVertexCov() const { return eventVertexCov_; }

  const AlgebraicVector3& eventVertexShift() const { return eventVertexShift_; }

  /// fit hypotheses of lepton-pair resonances
  size_t numResonances() const { return resonances_.size(); }
  SVfitResonanceHypothesisBase* resonance(size_t idx) { return idx < resonances_.size() ? &resonances_[idx] : 0; }
  const SVfitResonanceHypothesisBase* resonance(size_t idx) const { return idx < resonances_.size() ? &resonances_[idx] : 0; }
  const SVfitResonanceHypothesisBase* resonance(const std::string& name) const
  {
    const SVfitResonanceHypothesisBase* retVal = 0;
    for ( edm::OwnVector<SVfitResonanceHypothesisBase>::const_iterator resonance = resonances_.begin();
	  resonance != resonances_.end(); ++resonance ) {
      if ( resonance->name() == name ) retVal = &(*resonance);
    }
    return retVal;
  }

  double nll() const { return nll_; }

  virtual void print(std::ostream& stream) const 
  {
    stream << "<SVfitEventHypothesisBase::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    stream << " barcode = " << barcode_ << std::endl;
    stream << " met(id = " << met_.id() << ", key =" << met_.key() << "): Pt = " << met_->pt() << ", phi = " << met_->phi() 
	   << " (Px = " << met_->px() << ", Py = " << met_->py() << ")" << std::endl;
    const reco::MET* met = dynamic_cast<const reco::MET*>(met_.get());
    if ( met ) {
      stream << " metCov:" << std::endl;
      met->getSignificanceMatrix().Print();
    }
    for ( edm::OwnVector<SVfitResonanceHypothesisBase>::const_iterator resonance = resonances_.begin();
          resonance != resonances_.end(); ++resonance ) {
      resonance->print(stream);
    }    
    stream << " -log(prob) = " << nll_ << std::endl;
  }

  friend class SVfitEventBuilderBase;
  friend class SVfitAlgorithmBase;
  friend class SVfitAlgorithmByLikelihoodMaximization;
  friend class SVfitAlgorithmByIntegration2;

 protected:

  /// "human-readable" label for print-out
  std::string name_;

  /// unique identifier to associate hypothesis to likelihood function
  int barcode_;

  /// -log(prob)
  double nll_;

  /// pointer to MET object from which this hypothesis was made
  edm::Ptr<reco::Candidate> met_;

  /// position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  AlgebraicVector3 eventVertexPos_;
  AlgebraicSymMatrix33 eventVertexCov_;
  AlgebraicVector3 eventVertexShift_;
  bool eventVertexIsValid_;

  /// fit hypotheses for daughter particles
  edm::OwnVector<SVfitResonanceHypothesisBase> resonances_;

  /// "best fit" reconstructed mass,
  /// -1 sigma and +1 sigma limits on reconstructed mass
  double mass_;
  double massErrUp_;
  double massErrDown_;

  /// flag indicating that computed mass hypotheses are physically "valid" solutions
  bool isValidSolution_;
};

// CV: implementation of operator< needed to store SVfitEventHypothesisBase objects in edm::OwnVector
bool operator<(const SVfitEventHypothesisBase&, const SVfitEventHypothesisBase&);

#endif


