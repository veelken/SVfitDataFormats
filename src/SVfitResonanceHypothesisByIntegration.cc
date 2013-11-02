#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisByIntegration.h"

SVfitResonanceHypothesisByIntegration::SVfitResonanceHypothesisByIntegration(const SVfitResonanceHypothesisByIntegration& bluePrint)
  : SVfitResonanceHypothesisBase(bluePrint),
    massMean_(bluePrint.massMean_),
    massMedian_(bluePrint.massMedian_),
    massMaximum_(bluePrint.massMaximum_),
    massMaxInterpol_(bluePrint.massMaxInterpol_),
    massMean3sigmaWithinMax_(bluePrint.massMean3sigmaWithinMax_),
    massMean5sigmaWithinMax_(bluePrint.massMean5sigmaWithinMax_)
{}

SVfitResonanceHypothesisByIntegration::SVfitResonanceHypothesisByIntegration(const SVfitResonanceHypothesisBase& bluePrint)
  : SVfitResonanceHypothesisBase(bluePrint)
{
  daughters_.clear();
  size_t numDaughters = bluePrint.numDaughters();
  for ( size_t iDaughter = 0; iDaughter < numDaughters; ++iDaughter ) {
    std::auto_ptr<SVfitSingleParticleHypothesisBase> daughter_byIntegration(bluePrint.daughter(iDaughter)->reduceToBase());
    daughters_.push_back(daughter_byIntegration);
  }
}

SVfitResonanceHypothesisByIntegration& SVfitResonanceHypothesisByIntegration::operator=(
  const SVfitResonanceHypothesisByIntegration& bluePrint)
{
  SVfitResonanceHypothesisBase::operator=(bluePrint);
  massMean_ = bluePrint.massMean_;
  massMedian_ = bluePrint.massMedian_;
  massMaximum_ = bluePrint.massMaximum_;
  massMaxInterpol_ = bluePrint.massMaxInterpol_;
  massMean3sigmaWithinMax_ = bluePrint.massMean3sigmaWithinMax_;
  massMean5sigmaWithinMax_ = bluePrint.massMean5sigmaWithinMax_;
  return (*this);
}
