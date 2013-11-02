#ifndef AnalysisDataFormats_SVfit_SVfitResonanceHypothesisByIntegration_h
#define AnalysisDataFormats_SVfit_SVfitResonanceHypothesisByIntegration_h

#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"

#include <string>

class SVfitEventHypothesis;

class SVfitResonanceHypothesisByIntegration : public SVfitResonanceHypothesisBase
{
 public:

  SVfitResonanceHypothesisByIntegration() {}
  SVfitResonanceHypothesisByIntegration(const SVfitResonanceHypothesisByIntegration&);
  SVfitResonanceHypothesisByIntegration(const SVfitResonanceHypothesisBase&);
  virtual ~SVfitResonanceHypothesisByIntegration() {}

  virtual SVfitResonanceHypothesisByIntegration* clone() const { return new SVfitResonanceHypothesisByIntegration(*this); }

  virtual SVfitResonanceHypothesisByIntegration& operator=(const SVfitResonanceHypothesisByIntegration&);

  /// mean and median reconstructed mass
  double mass_mean() const { return massMean_; }
  double mass_median() const { return massMedian_; }
  double mass_maximum() const { return massMaximum_; }
  double mass_maxInterpol() const { return massMaxInterpol_; }
  double mass_mean3sigmaWithinMax() const { return massMean3sigmaWithinMax_; }
  double mass_mean5sigmaWithinMax() const { return massMean5sigmaWithinMax_; }

  friend class SVfitAlgorithmByIntegration;

 private:

  /// mean and median reconstructed mass
  double massMean_;
  double massMedian_;
  double massMaximum_;
  double massMaxInterpol_;
  double massMean3sigmaWithinMax_;
  double massMean5sigmaWithinMax_;
};

#endif
