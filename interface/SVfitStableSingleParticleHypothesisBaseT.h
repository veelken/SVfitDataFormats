#ifndef AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesisBaseT_h
#define AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesisBaseT_h

/*
 * SVfitStableSingleParticleHypothesisBaseT
 *
 * Class representing electrons or muons not originating from tau lepton decays
 * (e.g. produced in decays of W bosons)
 *
 * NOTE: this base-class is used to make persistent solutions of SVfitAlgorithmByIntegration;
 *       solutions of SVfitAlgorithmByLikelihoodMaximization are of type SVfitStableSingleParticleHypothesisBaseT
 *
 * Authors: Christian Veelken, LLR
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

template <typename T>
class SVfitStableSingleParticleHypothesisBaseT : public T
{
 public:

  SVfitStableSingleParticleHypothesisBaseT() {}
  SVfitStableSingleParticleHypothesisBaseT(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : T(particle, name, barcode) 
  {}
  SVfitStableSingleParticleHypothesisBaseT(const SVfitStableSingleParticleHypothesisBaseT& bluePrint)
    : T(bluePrint)
  {}

  ~SVfitStableSingleParticleHypothesisBaseT() {}

  SVfitStableSingleParticleHypothesisBaseT& operator=(const SVfitStableSingleParticleHypothesisBaseT& bluePrint)
  {
    T::operator=(bluePrint);
    return (*this);
  }

  SVfitStableSingleParticleHypothesisBaseT* clone() const { return new SVfitStableSingleParticleHypothesisBaseT(*this); }
  SVfitSingleParticleHypothesisBase* reduceToBase() const { return this->clone(); }
};

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

typedef SVfitStableSingleParticleHypothesisBaseT<SVfitSingleParticleHypothesisBase> SVfitStableSingleParticleHypothesisBase;

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesisBaseT_h */
