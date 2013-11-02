#ifndef AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesis_h

/*
 * SVfitSingleNeutrinoHypothesis
 *
 * Class representing neutrinos not originating from tau lepton decays
 * (e.g. produced in decays of W bosons)
 *
 * NOTE: this class is used to make persistent solutions of SVfitAlgorithmByLikelihoodMaximization;
 *       solutions of SVfitAlgorithmByIntegration are of type SVfitSingleNeutrinoHypothesisBase
 *
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleNeutrinoHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

class SVfitSingleNeutrinoHypothesis : public SVfitSingleNeutrinoHypothesisBaseT<SVfitSingleParticleHypothesis>
{
 public:

  SVfitSingleNeutrinoHypothesis() {}
  SVfitSingleNeutrinoHypothesis(const std::string& name, int barcode)
    : SVfitSingleNeutrinoHypothesisBaseT<SVfitSingleParticleHypothesis>(name, barcode)
  {
    p4_ = reco::Candidate::LorentzVector(0.,0.,0.,0.);
  }
  SVfitSingleNeutrinoHypothesis(const SVfitSingleNeutrinoHypothesis& bluePrint)
    : SVfitSingleNeutrinoHypothesisBaseT<SVfitSingleParticleHypothesis>(bluePrint)
  {}

  ~SVfitSingleNeutrinoHypothesis() {}

  virtual SVfitSingleNeutrinoHypothesis& operator=(const SVfitSingleNeutrinoHypothesis& bluePrint)
  {
    SVfitSingleNeutrinoHypothesisBaseT<SVfitSingleParticleHypothesis>::operator=(bluePrint);
    return (*this);
  }

  SVfitSingleNeutrinoHypothesis* clone() const { return new SVfitSingleNeutrinoHypothesis(*this); }

  friend class SVfitResonanceBuilderW;
};

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitSingleNeutrinoHypothesis_h */
