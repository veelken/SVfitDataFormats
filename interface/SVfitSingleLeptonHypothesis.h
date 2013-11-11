#ifndef AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesis_h

/*
 * SVfitSingleLeptonHypothesis
 *
 * Class representing electrons and muons not originating from tau lepton decays
 *
 * NOTE: this class is used to make persistent solutions of SVfitAlgorithmByLikelihoodMaximization;
 *       solutions of SVfitAlgorithmByIntegration are of type SVfitSingleLeptonHypothesisBase
 *
 * Authors: Christian Veelken, LLR
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleLeptonHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

class SVfitSingleLeptonHypothesis : public SVfitSingleLeptonHypothesisBaseT<SVfitSingleParticleHypothesis>
{
 public:

  SVfitSingleLeptonHypothesis() {}
  SVfitSingleLeptonHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : SVfitSingleLeptonHypothesisBaseT<SVfitSingleParticleHypothesis>(particle, name, barcode)
  {}
  SVfitSingleLeptonHypothesis(const SVfitSingleLeptonHypothesis& bluePrint)
    : SVfitSingleLeptonHypothesisBaseT<SVfitSingleParticleHypothesis>(bluePrint)
  {}

  ~SVfitSingleLeptonHypothesis() {}

  virtual SVfitSingleLeptonHypothesis& operator=(const SVfitSingleLeptonHypothesis& bluePrint)
  {
    SVfitSingleLeptonHypothesisBaseT<SVfitSingleParticleHypothesis>::operator=(bluePrint);
    return (*this);
  }

  SVfitSingleLeptonHypothesis* clone() const { return new SVfitSingleLeptonHypothesis(*this); }

  template<typename T> friend class SVfitLeptonBuilderDummy;
};

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitSingleLeptonHypothesis_h */
