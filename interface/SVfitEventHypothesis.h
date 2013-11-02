#ifndef AnalysisDataFormats_SVfit_SVfitEventHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitEventHypothesis_h

#include "DataFormats/Candidate/interface/Candidate.h" 

#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesis.h"

#include <string>

class SVfitEventHypothesis : public SVfitEventHypothesisBase
{
 public:

  SVfitEventHypothesis() {}
  SVfitEventHypothesis(const edm::Ptr<reco::Candidate>& met) 
    : SVfitEventHypothesisBase(met),
      p4MEt_(met->p4())
  {}
  SVfitEventHypothesis(const SVfitEventHypothesis&);
  virtual ~SVfitEventHypothesis() {}

  virtual SVfitEventHypothesis* clone() const { return new SVfitEventHypothesis(*this); }

  virtual SVfitEventHypothesis& operator=(const SVfitEventHypothesis&);

  /// fit hypotheses of lepton resonances
  SVfitResonanceHypothesis* resonance(size_t idx) { 
    return dynamic_cast<SVfitResonanceHypothesis*>(&resonances_[idx]); 
  }
  const SVfitResonanceHypothesis* resonance(size_t idx) const { 
    return dynamic_cast<const SVfitResonanceHypothesis*>(&resonances_[idx]); 
  }
  const SVfitResonanceHypothesis* resonance(const std::string& name) const
  {
    const SVfitResonanceHypothesis* retVal = 0;
    for ( edm::OwnVector<SVfitResonanceHypothesisBase>::const_iterator resonance = resonances_.begin();
	  resonance != resonances_.end(); ++resonance ) {
      if ( resonance->name() == name ) retVal = dynamic_cast<const SVfitResonanceHypothesis*>(&(*resonance));
    }
    return retVal;
  }
  
  /// momentum of multi-lepton system before fit, after fit
  /// and difference in momentum (after - before) fit
  reco::Candidate::LorentzVector p4() const { return p4_; }
  reco::Candidate::LorentzVector p4_fitted() const { return (p4_ + dp4_); }
  reco::Candidate::LorentzVector dp4fitted() const { return dp4_; }

  /// missing transverse momentum before fit
  /// and fitted value of missing transverse momentum
  reco::Candidate::LorentzVector p4MEt() const { return p4MEt_; }
  reco::Candidate::LorentzVector dp4MEt_fitted() const { return (dp4_ - p4MEt_); } 

  unsigned numPolStates() const { return numPolStates_; }
  int polHandedness(unsigned idx) const { return polHandedness_[idx]; }

  enum { kPolUndefined, kPolWLWL, kPolWRWR, kPolWTWT };

  virtual void print(std::ostream& stream) const 
  {
    SVfitEventHypothesisBase::print(stream);
    stream << " sqrt(s) = " << p4_fitted().mass() << std::endl;
  }

  friend class SVfitEventBuilderBase;
  friend class SVfitEventBuilder;

 private:

  /// momentum of particle before fit
  reco::Candidate::LorentzVector p4_;

  /// difference in momentum (after - before) fit
  reco::Candidate::LorentzVector dp4_;

  /// missing transverse momentum before fit
  reco::Candidate::LorentzVector p4MEt_;

  /// different possible polarization states
  std::vector<int> polHandedness_;
  unsigned numPolStates_;
};

#endif


