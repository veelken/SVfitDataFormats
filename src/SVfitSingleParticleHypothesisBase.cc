#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

bool operator<(const SVfitSingleParticleHypothesisBase& hypothesis1, const SVfitSingleParticleHypothesisBase& hypothesis2)
{
  return (hypothesis1.barcode() < hypothesis2.barcode());
}

