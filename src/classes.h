
#include "AnalysisDataFormats/SVfit/interface/CompositePtrCandidateT1T2MEt.h"
#include "AnalysisDataFormats/SVfit/interface/CompositePtrCandidateT1T2MEtFwd.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesis.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisByIntegration.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesis.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisByIntegration.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisSummary.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitTauToDaughtersHypothesisBaseT1T2.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitTauToHadHypothesis.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitStableSingleParticleHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleNeutrinoHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleLeptonHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisSummary.h"

#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/OwnVector.h"

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/MET.h"

#include "DataFormats/VertexReco/interface/Vertex.h"

namespace {
  struct AnalysisDataFormats_SVfit_dictionary {
    /// create dictionaries for DiCandidatePair objects
    DiCandidatePair dummyDiCandidatePair;
    edm::Wrapper<DiCandidatePair> dummyDiCandidatePairWrapper;
    DiCandidatePairCollection dummyDiCandidatePairCollection;
    edm::Wrapper<DiCandidatePairCollection> dummyDiCandidatePairCollectionWrapper;
    edm::Ref<DiCandidatePairCollection> dummyDiCandidatePairRef;
    edm::RefProd<DiCandidatePairCollection> dummyDiCandidatePairRefProd;
    edm::RefVector<DiCandidatePairCollection> dummyDiCandidatePairRefVector;

    /// create dictionaries for SVfit solution data-formats
    SVfitEventHypothesisBase dummySVfitEventHypothesisBase;
    SVfitEventHypothesis dummySVfitEventHypothesis;
    SVfitEventHypothesisByIntegration dummySVfitEventHypothesisByIntegration;
    SVfitResonanceHypothesisBase dummySVfitResonanceHypothesisBase;
    SVfitResonanceHypothesis dummySVfitResonanceHypothesis;
    SVfitResonanceHypothesisByIntegration dummySVfitResonanceHypothesisByIntegration;
    SVfitResonanceHypothesisSummary dummySVfitResonanceHypothesisSummary;
    SVfitTauToElecHypothesisBase dummySVfitTauToElecHypothesisBase;
    SVfitTauToElecHypothesis dummySVfitTauToElecHypothesis;
    SVfitTauToMuHypothesisBase dummySVfitTauToMuHypothesisBase;
    SVfitTauToMuHypothesis dummySVfitTauToMuHypothesis;
    SVfitTauToHadHypothesisBase dummySVfitTauToHadHypothesisBase;
    SVfitTauToHadHypothesis dummySVfitTauToHadHypothesis;
    SVfitStableSingleParticleHypothesisBase dummySVfitStableSingleParticleHypothesisBase;
    SVfitSingleNeutrinoHypothesisBase dummySVfitSingleNeutrinoHypothesisBase;
    SVfitSingleLeptonHypothesisBase dummySVfitSingleLeptonHypothesisBase;
    SVfitSingleParticleHypothesisSummary dummySVfitSingleParticleHypothesisSummary;
    std::vector<SVfitEventHypothesisBase> dummySVfitEventHypothesisBaseCollection;
    std::vector<SVfitEventHypothesis> dummySVfitEventHypothesisCollection;
    std::vector<SVfitEventHypothesisByIntegration> dummySVfitEventHypothesisByIntegrationCollection;
    edm::Wrapper<std::vector<SVfitEventHypothesisBase> > dummySVfitEventHypothesisBaseCollectionWrapper;
    edm::Wrapper<std::vector<SVfitEventHypothesis> > dummySVfitEventHypothesisCollectionWrapper;
    edm::Wrapper<std::vector<SVfitEventHypothesisByIntegration> > dummySVfitEventHypothesisByIntegrationCollectionWrapper;
    std::vector<SVfitEventHypothesisBase*> dummySVfitEventHypothesisBasePtrCollection;
    edm::OwnVector<SVfitEventHypothesisBase, edm::ClonePolicy<SVfitEventHypothesisBase> > dummySVfitEventHypothesisBaseOwnVector;
    std::vector<SVfitResonanceHypothesisBase*> dummySVfitResonanceHypothesisBasePtrCollection;
    edm::OwnVector<SVfitResonanceHypothesisBase, edm::ClonePolicy<SVfitResonanceHypothesisBase> > dummySVfitResonanceHypothesisBaseOwnVector;
    std::vector<SVfitResonanceHypothesisSummary> dummySVfitResonanceHypothesisSummaryCollection;
    std::auto_ptr<TH1> dummyTH1Ptr;
    std::vector<SVfitSingleParticleHypothesisBase*> dummySVfitSingleParticleHypothesisBasePtrCollection;
    edm::OwnVector<SVfitSingleParticleHypothesisBase, edm::ClonePolicy<SVfitSingleParticleHypothesisBase> > dummySVfitSingleParticleHypothesisBaseOwnVector;
    std::vector<SVfitSingleParticleHypothesisSummary*> dummySVfitSingleParticleHypothesisSummaryPtrCollection;
    edm::OwnVector<SVfitSingleParticleHypothesisSummary, edm::ClonePolicy<SVfitSingleParticleHypothesisSummary> > dummySVfitSingleParticleHypothesisSummaryOwnVector;
    
    /// create dictionaries for PATDiElecPair objects
    PATDiElecPair dummyPATDiElecPair;
    edm::Wrapper<PATDiElecPair> dummyPATDiElecPairWrapper;
    PATDiElecPairCollection dummyPATDiElecPairCollection;
    edm::Wrapper<PATDiElecPairCollection> dummyPATDiElecPairCollectionWrapper;
    edm::Ref<PATDiElecPairCollection> dummyPATDiElecPairRef;
    edm::RefVector<PATDiElecPairCollection> dummyPATDiElecPairRefVector;
    edm::RefProd<PATDiElecPairCollection> dummyPATDiElecPairRefProd;
    edm::Ptr<PATDiElecPair> dummyPATDiElecPairPtr;
    edm::AssociationVector<edm::RefProd<PATDiElecPairCollection>, std::vector<int> > dummyPATDiElecPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATDiElecPairCollection>, std::vector<int> > > dummyPATDiElecPairToMEtAssociationWrapper;

    /// create dictionaries for PATDiMuPair objects
    PATDiMuPair dummyPATDiMuPair;
    edm::Wrapper<PATDiMuPair> dummyPATDiMuPairWrapper;
    PATDiMuPairCollection dummyPATDiMuPairCollection;
    edm::Wrapper<PATDiMuPairCollection> dummyPATDiMuPairCollectionWrapper;
    edm::Ref<PATDiMuPairCollection> dummyPATDiMuPairRef;
    edm::RefVector<PATDiMuPairCollection> dummyPATDiMuPairRefVector;
    edm::RefProd<PATDiMuPairCollection> dummyPATDiMuPairRefProd;
    edm::Ptr<PATDiMuPair> dummyPATDiMuPairPtr;
    edm::AssociationVector<edm::RefProd<PATDiMuPairCollection>, std::vector<int> > dummyPATDiMuPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATDiMuPairCollection>, std::vector<int> > > dummyPATDiMuPairToMEtAssociationWrapper;

    /// create dictionaries for PATElecTauPair objects
    PATElecTauPair dummyPATElecTauPair;
    edm::Wrapper<PATElecTauPair> dummyPATElecTauPairWrapper;
    PATElecTauPairCollection dummyPATElecTauPairCollection;
    edm::Wrapper<PATElecTauPairCollection> dummyPATElecTauPairCollectionWrapper;
    edm::Ref<PATElecTauPairCollection> dummyPATElecTauPairRef;
    edm::RefVector<PATElecTauPairCollection> dummyPATElecTauPairRefVector;
    edm::RefProd<PATElecTauPairCollection> dummyPATElecTauPairRefProd;
    edm::Ptr<PATElecTauPair> dummyPATElecTauPairPtr;
    edm::AssociationVector<edm::RefProd<PATElecTauPairCollection>, std::vector<int> > dummyPATElecTauPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATElecTauPairCollection>, std::vector<int> > > dummyPATElecTauPairToMEtAssociationWrapper;

    /// create dictionaries for PATMuTauPair objects
    PATMuTauPair dummyPATMuTauPair;
    edm::Wrapper<PATMuTauPair> dummyPATMuTauPairWrapper;
    PATMuTauPairCollection dummyPATMuTauPairCollection;
    edm::Wrapper<PATMuTauPairCollection> dummyPATMuTauPairCollectionWrapper;
    edm::Ref<PATMuTauPairCollection> dummyPATMuTauPairRef;
    edm::RefVector<PATMuTauPairCollection> dummyPATMuTauPairRefVector;
    edm::RefProd<PATMuTauPairCollection> dummyPATMuTauPairRefProd;
    edm::Ptr<PATMuTauPair> dummyPATMuTauPairPtr;
    edm::AssociationVector<edm::RefProd<PATMuTauPairCollection>, std::vector<int> > dummyPATMuTauPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATMuTauPairCollection>, std::vector<int> > > dummyPATMuTauPairToMEtAssociationWrapper;

    /// create dictionaries for PATDiTauPair objects
    PATDiTauPair dummyPATDiTauPair;
    edm::Wrapper<PATDiTauPair> dummyPATDiTauPairWrapper;
    PATDiTauPairCollection dummyPATDiTauPairCollection;
    edm::Wrapper<PATDiTauPairCollection> dummyPATDiTauPairCollectionWrapper;
    edm::Ref<PATDiTauPairCollection> dummyPATDiTauPairRef;
    edm::RefVector<PATDiTauPairCollection> dummyPATDiTauPairRefVector;
    edm::RefProd<PATDiTauPairCollection> dummyPATDiTauPairRefProd;
    edm::Ptr<PATDiTauPair> dummyPATDiTauPairPtr;
    edm::AssociationVector<edm::RefProd<PATDiTauPairCollection>, std::vector<int> > dummyPATDiTauPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATDiTauPairCollection>, std::vector<int> > > dummyPATDiTauPairToMEtAssociationWrapper;
    
    /// create dictionaries for PATElecMuPair objects
    PATElecMuPair dummyPATElecMuPair;
    edm::Wrapper<PATElecMuPair> dummyPATElecMuPairWrapper;
    PATElecMuPairCollection dummyPATElecMuPairCollection;
    edm::Wrapper<PATElecMuPairCollection> dummyPATElecMuPairCollectionWrapper;
    edm::Ref<PATElecMuPairCollection> dummyPATElecMuPairRef;
    edm::RefVector<PATElecMuPairCollection> dummyPATElecMuPairRefVector;
    edm::RefProd<PATElecMuPairCollection> dummyPATElecMuPairRefProd;
    edm::Ptr<PATElecMuPair> dummyPATElecMuPairPtr;
    edm::AssociationVector<edm::RefProd<PATElecMuPairCollection>, std::vector<int> > dummyPATElecMuPairToMEtAssociation;
    edm::Wrapper<edm::AssociationVector<edm::RefProd<PATElecMuPairCollection>, std::vector<int> > > dummyPATElecMuPairToMEtAssociationWrapper;
  };
}
