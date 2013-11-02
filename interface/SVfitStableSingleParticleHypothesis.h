#ifndef AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesis_h

/*
 * SVfitStableSingleParticleHypothesis
 *
 * Class representing electrons or muons not originating from tau lepton decays
 * (e.g. produced in decays of W bosons)
 *
 * NOTE: this class is used to make persistent solutions of SVfitAlgorithmByLikelihoodMaximization;
 *       solutions of SVfitAlgorithmByIntegration are of type SVfitStableSingleParticleHypothesisBase
 *
 * Authors: Christian Veelken, LLR
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitStableSingleParticleHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

class SVfitStableSingleParticleHypothesis : public SVfitStableSingleParticleHypothesisBaseT<SVfitSingleParticleHypothesis>
{
 public:

  SVfitStableSingleParticleHypothesis() {}
  SVfitStableSingleParticleHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : SVfitStableSingleParticleHypothesisBaseT<SVfitSingleParticleHypothesis>(particle, name, barcode)
  {}
  SVfitStableSingleParticleHypothesis(const SVfitStableSingleParticleHypothesis& bluePrint)
    : SVfitStableSingleParticleHypothesisBaseT<SVfitSingleParticleHypothesis>(bluePrint)
  {}
  
  ~SVfitStableSingleParticleHypothesis() {}

  virtual SVfitStableSingleParticleHypothesis& operator=(const SVfitStableSingleParticleHypothesis& bluePrint)
  {
    SVfitStableSingleParticleHypothesisBaseT<SVfitSingleParticleHypothesis>::operator=(bluePrint);
    return (*this);
  }

  SVfitStableSingleParticleHypothesis* clone() const { return new SVfitStableSingleParticleHypothesis(*this); }

  /// unit-vector in lepton flight direction
  const reco::Candidate::Vector& p3_unit() const { return p3_unit_; }

  friend class SVfitResonanceBuilderW;

 protected:

  /// unit-vector in lepton flight direction
  reco::Candidate::Vector p3_unit_;
};

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitStableSingleParticleHypothesis_h */
