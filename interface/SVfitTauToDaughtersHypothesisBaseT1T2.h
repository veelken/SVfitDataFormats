#ifndef AnalysisDataFormats_SVfit_SVfitTauToDaughtersHypothesisBaseT1T2_h
#define AnalysisDataFormats_SVfit_SVfitTauToDaughtersHypothesisBaseT1T2_h

/*
 * SVfitTauToDaughtersHypothesisBaseT1T2
 *
 *  Class to store information about tau lepton decay into electrons, muons or hadrons.
 *
 * NOTE: 
 *      (1) this class is used to make persistent 
 *           o tau decays into electrons and muons,
 *             reconstructed by SVfitAlgorithmByLikelihoodMaximization or SVfitAlgorithmByIntegration
 *           o tau decays into hadrons,
 *             reconstructed by SVfitAlgorithmByIntegration
 *      (2) information about tau lepton decays into hadrons reconstructed by SVfitAlgorithmByLikelihoodMaximization
 *          are stored in objects of type SVfitTauToHadHypothesis
 *        
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

template <typename T1, typename T2>
class SVfitTauToDaughtersHypothesisBaseT1T2 : public T1
{
 public:
  SVfitTauToDaughtersHypothesisBaseT1T2() {}
  SVfitTauToDaughtersHypothesisBaseT1T2(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : T1(particle, name, barcode)
  {
    //std::cout << "<SVfitTauToDaughtersHypothesisBaseT1T2::SVfitTauToDaughtersHypothesisBaseT1T2>:" << std::endl;
    //std::cout << " constructor(const edm::Ptr<reco::Candidate>&, std::string, int)" << std::endl;
  }
  SVfitTauToDaughtersHypothesisBaseT1T2(const SVfitTauToDaughtersHypothesisBaseT1T2& bluePrint)
    : T1(bluePrint)
  {}
  ~SVfitTauToDaughtersHypothesisBaseT1T2() {}

  SVfitTauToDaughtersHypothesisBaseT1T2* clone() const { return new SVfitTauToDaughtersHypothesisBaseT1T2(*this); }
  SVfitSingleParticleHypothesisBase* reduceToBase() const { return this->clone(); }

  SVfitTauToDaughtersHypothesisBaseT1T2& operator=(const SVfitTauToDaughtersHypothesisBaseT1T2& bluePrint)
  {
    T1::operator=(bluePrint);
    return (*this);
  }

  template <typename T> friend class SVfitTauToLepBuilder;
};

#include "AnalysisDataFormats/SVfit/interface/SVfitTauDecayHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

typedef SVfitTauToDaughtersHypothesisBaseT1T2<SVfitTauDecayHypothesisBase, pat::Electron> SVfitTauToElecHypothesisBase;
typedef SVfitTauToDaughtersHypothesisBaseT1T2<SVfitTauDecayHypothesisBase, pat::Muon> SVfitTauToMuHypothesisBase;
typedef SVfitTauToDaughtersHypothesisBaseT1T2<SVfitTauDecayHypothesisBase, pat::Tau> SVfitTauToHadHypothesisBase;

#include "AnalysisDataFormats/SVfit/interface/SVfitTauDecayHypothesis.h"

typedef SVfitTauToDaughtersHypothesisBaseT1T2<SVfitTauDecayHypothesis, pat::Electron> SVfitTauToElecHypothesis;
typedef SVfitTauToDaughtersHypothesisBaseT1T2<SVfitTauDecayHypothesis, pat::Muon> SVfitTauToMuHypothesis;

#endif
