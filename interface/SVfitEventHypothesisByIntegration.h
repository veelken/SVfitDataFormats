#ifndef AnalysisDataFormats_SVfit_SVfitEventHypothesisByIntegration_h
#define AnalysisDataFormats_SVfit_SVfitEventHypothesisByIntegration_h

#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisByIntegration.h"

#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/Common/interface/ClonePolicy.h"

#include <TH1.h>

#include <string>

struct TH1ClonePolicy;

class SVfitEventHypothesisByIntegration : public SVfitEventHypothesisBase
{
 public:

  SVfitEventHypothesisByIntegration() {}
  SVfitEventHypothesisByIntegration(const edm::Ptr<reco::Candidate>& met) 
    : SVfitEventHypothesisBase(met)
  {}
  SVfitEventHypothesisByIntegration(const SVfitEventHypothesisByIntegration&);
  SVfitEventHypothesisByIntegration(const SVfitEventHypothesisBase&);
  virtual ~SVfitEventHypothesisByIntegration() {}

  virtual SVfitEventHypothesisByIntegration* clone() const { return new SVfitEventHypothesisByIntegration(*this); }

  virtual SVfitEventHypothesisByIntegration& operator=(const SVfitEventHypothesisByIntegration&);

  /// fit hypotheses of lepton resonances
  SVfitResonanceHypothesisByIntegration* resonance(size_t idx) { 
    return dynamic_cast<SVfitResonanceHypothesisByIntegration*>(&resonances_[idx]); 
  }
  const SVfitResonanceHypothesisByIntegration* resonance(size_t idx) const { 
    return dynamic_cast<const SVfitResonanceHypothesisByIntegration*>(&resonances_[idx]); 
  }

  const TH1* histMassResults() const { return histMassResults_.get(); }

  friend class SVfitAlgorithmByIntegration;

 private:

  /// Nd-histogram containing full correlations of masses reconstructed for resonances
  std::auto_ptr<TH1> histMassResults_;
};

#endif


