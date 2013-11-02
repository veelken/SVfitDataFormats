#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesis.h"

SVfitEventHypothesis::SVfitEventHypothesis(const SVfitEventHypothesis& bluePrint)
  : SVfitEventHypothesisBase(bluePrint),
    p4_(bluePrint.p4_),
    dp4_(bluePrint.dp4_),
    p4MEt_(bluePrint.p4MEt_)
{
  size_t numResonances = resonances_.size();
  for ( size_t iResonance = 0; iResonance < numResonances; ++iResonance ) {
    this->resonance(iResonance)->setEventHypothesis(this);	
  }
}

SVfitEventHypothesis& SVfitEventHypothesis::operator=(const SVfitEventHypothesis& bluePrint)
{
  SVfitEventHypothesisBase::operator=(bluePrint);
  p4_ = bluePrint.p4_;
  dp4_ = bluePrint.dp4_;
  p4MEt_ = bluePrint.p4MEt_;
  size_t numResonances = resonances_.size();
  for ( size_t iResonance = 0; iResonance < numResonances; ++iResonance ) {
    this->resonance(iResonance)->setEventHypothesis(this);
  }
  return (*this);
}
