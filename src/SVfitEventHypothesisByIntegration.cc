#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisByIntegration.h"

SVfitEventHypothesisByIntegration::SVfitEventHypothesisByIntegration(const SVfitEventHypothesisByIntegration& bluePrint)
  : SVfitEventHypothesisBase(bluePrint)
{
  histMassResults_.reset((TH1*)bluePrint.histMassResults_->Clone());
}

SVfitEventHypothesisByIntegration::SVfitEventHypothesisByIntegration(const SVfitEventHypothesisBase& bluePrint)
  : SVfitEventHypothesisBase(bluePrint)
{
  resonances_.clear();
  size_t numResonances = bluePrint.numResonances();
  for ( size_t iResonance = 0; iResonance < numResonances; ++iResonance ) {
    std::auto_ptr<SVfitResonanceHypothesisBase> resonance_byIntegration(
      new SVfitResonanceHypothesisByIntegration(*bluePrint.resonance(iResonance)));
    resonances_.push_back(resonance_byIntegration);
  }
}

SVfitEventHypothesisByIntegration& SVfitEventHypothesisByIntegration::operator=(const SVfitEventHypothesisByIntegration& bluePrint)
{
  SVfitEventHypothesisBase::operator=(bluePrint);
  histMassResults_.reset((TH1*)bluePrint.histMassResults_->Clone());
  return (*this);
}
