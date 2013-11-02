#ifndef AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesisBaseT_h
#define AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesisBaseT_h

/*
 * SVfitSingleNeutrinoHypothesisBaseT
 *
 * Class representing neutrinos not originating from tau lepton decays
 * (e.g. produced in decays of W bosons)
 *
 * NOTE: this base-class is used to make persistent solutions of SVfitAlgorithmByIntegration;
 *       solutions of SVfitAlgorithmByLikelihoodMaximization are of type SVfitTauDecayHypothesis
 *
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

template <typename T>
class SVfitSingleNeutrinoHypothesisBaseT : public T
{
 public:

  SVfitSingleNeutrinoHypothesisBaseT() {}
  SVfitSingleNeutrinoHypothesisBaseT(const std::string& name, int barcode)
    : T(name, barcode) 
  {}
  SVfitSingleNeutrinoHypothesisBaseT(const SVfitSingleNeutrinoHypothesisBaseT& bluePrint)
    : T(bluePrint)
  {}

  ~SVfitSingleNeutrinoHypothesisBaseT() {}

  SVfitSingleNeutrinoHypothesisBaseT& operator=(const SVfitSingleNeutrinoHypothesisBaseT& bluePrint)
  {
    T::operator=(bluePrint);
    return (*this);
  }

  SVfitSingleNeutrinoHypothesisBaseT* clone() const { return new SVfitSingleNeutrinoHypothesisBaseT(*this); }
  SVfitSingleParticleHypothesisBase* reduceToBase() const { return this->clone(); }
};

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

typedef SVfitSingleNeutrinoHypothesisBaseT<SVfitSingleParticleHypothesisBase> SVfitSingleNeutrinoHypothesisBase;

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesisBaseT_h */
