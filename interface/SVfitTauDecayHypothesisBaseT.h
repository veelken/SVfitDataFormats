#ifndef AnalysisDataFormats_SVfit_SVfitTauDecayHypothesisBaseT_h
#define AnalysisDataFormats_SVfit_SVfitTauDecayHypothesisBaseT_h

/*
 * SVfitTauDecayHypothesisBaseT
 *
 * Base class representing tau lepton decay to electrons, muons or into hadrons.
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
class SVfitTauDecayHypothesisBaseT : public T
{
 public:

  SVfitTauDecayHypothesisBaseT() {}
  SVfitTauDecayHypothesisBaseT(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : T(particle, name, barcode) 
  {
    //std::cout << "<SVfitTauDecayHypothesisBaseT::SVfitTauDecayHypothesisBaseT>:" << std::endl;
    //std::cout << " constructor(const edm::Ptr<reco::Candidate>&, std::string, int)" << std::endl;
  }
  SVfitTauDecayHypothesisBaseT(const SVfitTauDecayHypothesisBaseT& bluePrint)
    : T(bluePrint),
      decayMode_(bluePrint.decayMode_)
  {}

  ~SVfitTauDecayHypothesisBaseT() {}

  SVfitTauDecayHypothesisBaseT& operator=(const SVfitTauDecayHypothesisBaseT& bluePrint)
  {
    T::operator=(bluePrint);
    decayMode_ = bluePrint.decayMode_;
    return (*this);
  }

  /// tau lepton hadronic decay mode
  /// (as defined in DataFormats/TauReco/interface/PFTauDecayMode.h)
  int decayMode() const { return decayMode_; }

 protected:

  /// tau lepton hadronic decay mode
  int decayMode_;
};

#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

typedef SVfitTauDecayHypothesisBaseT<SVfitSingleParticleHypothesisBase> SVfitTauDecayHypothesisBase;

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitTauDecayHypothesisBaseT_h */
