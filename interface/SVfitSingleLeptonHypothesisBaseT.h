#ifndef AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesisBaseT_h
#define AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesisBaseT_h

/*
 * SVfitSingleLeptonHypothesisBaseT
 *
 * Class representing electrons and muons not originating from tau lepton decays
 *
 * NOTE: this base-class is used to make persistent solutions of SVfitAlgorithmByIntegration;
 *       solutions of SVfitAlgorithmByLikelihoodMaximization are of type SVfitSingleLeptonHypothesis
 *
 * Authors: Christian Veelken, LLR
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

template <typename T>
class SVfitSingleLeptonHypothesisBaseT : public T
{
 public:

  SVfitSingleLeptonHypothesisBaseT() {}
  SVfitSingleLeptonHypothesisBaseT(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : T(particle, name, barcode) 
  {}
  SVfitSingleLeptonHypothesisBaseT(const SVfitSingleLeptonHypothesisBaseT& bluePrint)
    : T(bluePrint)
  {}

  ~SVfitSingleLeptonHypothesisBaseT() {}

  SVfitSingleLeptonHypothesisBaseT& operator=(const SVfitSingleLeptonHypothesisBaseT& bluePrint)
  {
    T::operator=(bluePrint);
    return (*this);
  }

  SVfitSingleLeptonHypothesisBaseT* clone() const { return new SVfitSingleLeptonHypothesisBaseT(*this); }
  SVfitSingleParticleHypothesisBase* reduceToBase() const { return this->clone(); }
};

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

typedef SVfitSingleLeptonHypothesisBaseT<SVfitSingleParticleHypothesisBase> SVfitSingleLeptonHypothesisBase;

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesisBaseT_h */
