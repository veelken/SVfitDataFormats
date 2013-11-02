#ifndef __AnalysisDataFormats_SVfit_CompositeRefCandidateT1T2MEt_h__
#define __AnalysisDataFormats_SVfit_CompositeRefCandidateT1T2MEt_h__

/** \class CompositeRefCandidateT1T2MEt
 *
 * Combination of leptonic and hadronic decay products 
 * of a pair of tau leptons plus missing transverse momentum 
 * (representing the undetected momentum carried away by the neutrinos 
 *  produced in the two tau decays) 
 * 
 * \authors Colin Bernet,
 *          Michal Bluj,
 *          Christian Veelken
 *
 */

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DataFormats/Candidate/interface/CandidateFwd.h" 
#include "DataFormats/Candidate/interface/Candidate.h" 
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/Candidate/interface/LeafCandidate.h" 
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/Common/interface/OwnVector.h"

#include "AnalysisDataFormats/SVfit/interface/NSVfitResonanceHypothesisSummary.h"
#include "AnalysisDataFormats/SVfit/interface/tauAnalysisAuxFunctions.h"

#include <TMatrixD.h>

template<typename T1, typename T2>
class CompositePtrCandidateT1T2MEt : public reco::LeafCandidate 
{
  typedef edm::Ptr<T1> T1Ptr;
  typedef edm::Ptr<T2> T2Ptr;
  typedef edm::Ptr<reco::MET> MEtPtr;

 public:

  /// default constructor
  CompositePtrCandidateT1T2MEt()
    : metSignMatrix_(2,2),
      hasMEtSignMatrix_(false)
  {}

  /// constructor with MEt
  CompositePtrCandidateT1T2MEt(const T1Ptr leg1, const T2Ptr leg2, const reco::CandidatePtr met)
    : leg1_(leg1), 
      leg2_(leg2), 
      met_(met), 
      metSignMatrix_(2,2),
      hasMEtSignMatrix_(false) 
  {}

  /// constructor without MEt
  CompositePtrCandidateT1T2MEt(const T1Ptr leg1, const T2Ptr leg2)
    : leg1_(leg1), 
      leg2_(leg2), 
      metSignMatrix_(2,2),
      hasMEtSignMatrix_(false) 
  {}

  /// destructor
  ~CompositePtrCandidateT1T2MEt() {}

  /// access to daughter particles
  const T1Ptr leg1() const { return leg1_; }
  const T2Ptr leg2() const { return leg2_; }
  
  /// access to flag indicating which algorithm was used 
  /// to compute four-momentum of diTau candidate
  const std::string& getRecoMode() const { return recoMode_; }

  /// access to gen. momenta
  reco::Candidate::LorentzVector p4gen()      const { return p4Leg1gen() + p4Leg2gen();       }
  reco::Candidate::LorentzVector p4VisGen()   const { return p4VisLeg1gen() + p4VisLeg2gen(); }
  reco::Candidate::LorentzVector p4InvisGen() const { return p4gen() - p4VisGen();            }

  /// access to gen. mother particles
  /// (undecayed tau leptons)
  const reco::Candidate::LorentzVector& p4Leg1gen() const { return p4Leg1gen_; }
  const reco::Candidate::LorentzVector& p4Leg2gen() const { return p4Leg2gen_; }

  /// access to visible gen. daughter particles
  /// (electrons, muons, kaons, charged and neutral pions produced in tau decay)
  const reco::Candidate::LorentzVector& p4VisLeg1gen() const { return p4VisLeg1gen_; }
  const reco::Candidate::LorentzVector& p4VisLeg2gen() const { return p4VisLeg2gen_; }

  /// access to invisible gen daughter particles
  reco::Candidate::LorentzVector p4InvisLeg1gen() const { return p4Leg1gen_ - p4VisLeg1gen_; }
  reco::Candidate::LorentzVector p4InvisLeg2gen() const { return p4Leg2gen_ - p4VisLeg2gen_; }

  /// energy ratio of visible gen. daughter/mother particles
  double x1gen() const { return ( p4Leg1gen_.energy() > 0. ) ? p4VisLeg1gen_.energy()/p4Leg1gen_.energy() : -1.; }
  double x2gen() const { return ( p4Leg2gen_.energy() > 0. ) ? p4VisLeg2gen_.energy()/p4Leg2gen_.energy() : -1.; }

  /// get "true" positions of primary event vertex 
  /// and of tau decay vertices (generator level information)
  const reco::Candidate::Point& primaryVertexPosGen()   const { return primaryVertexPosGen_;   }
  const reco::Candidate::Point& decayVertexPosLeg1gen() const { return decayVertexPosLeg1gen_; }
  const reco::Candidate::Point& decayVertexPosLeg2gen() const { return decayVertexPosLeg2gen_; }
  
  /// return the number of source particle-like Candidates
  /// (the candidates used to construct this Candidate)       
  /// MET does not count. 
  size_t numberOfSourceCandidatePtrs() const { return 2; }

  /// return a Ptr to one of the source Candidates                                                               
  /// (the candidates used to construct this Candidate)                                                         
  reco::CandidatePtr sourceCandidatePtr(size_type idx) const {
    if      ( idx == 0 ) return leg1();
    else if ( idx == 1 ) return leg2();
    else assert(0);
  }

  /// access to missing transverse momentum
  const MEtPtr& met() const { return met_; }
  bool hasMEtSignMatrix() const { return hasMEtSignMatrix_; }
  const TMatrixD& metSignMatrix() const { return metSignMatrix_; }

  // get sum of charge of visible decay products
  // (not need to declare it in CompositePtrCandidateT1T2MEt; 
  //  already declared in Candidate base-class)

  /// get four-momentum of visible decay products
  const reco::Candidate::LorentzVector& p4Vis() const { return p4Vis_; }

  /// get four-momentum and scaling factors for momenta of visible decay products
  /// computed by collinear approximation
  const reco::Candidate::LorentzVector& p4CollinearApprox() const { return p4CollinearApprox_; }
  double x1CollinearApprox() const { return x1CollinearApprox_; }
  double x2CollinearApprox() const { return x2CollinearApprox_; }
  bool collinearApproxIsValid() const { return collinearApproxIsValid_; }

  /// get the four-momentum and x1-x2 (xi = visible energy fraction of the ith-tau)
  /// computed by improved coll. approx.
  const reco::Candidate::LorentzVector& p4ImprovedCollinearApprox() const { return p4ImprovedCollinearApprox_; }
  double x1ImprovedCollinearApprox() const { return x1ImprovedCollinearApprox_; }
  double x2ImprovedCollinearApprox() const { return x2ImprovedCollinearApprox_; }
  /// get the scale-factor to re-weight the mass of the diTaus rescued in the 
  /// improved coll.approx. This scale factor is a function of the visible diTau-pT
  /// The functional dependence can be configured by the user in the _cfg.
  double scaleFactor() const { return 1./scaleFactor_;}
  /// is the improved coll. approx. valid?
  bool ImprovedCollinearApproxIsValid() const { return ImprovedCollinearApproxIsValid_; }
  /// flag to discriminate which collinear approximation is valid:
  //     0 : coll. approx. and improved coll. approx. are false
  //     1 : coll. approx. is true 
  //     2 : coll. approx. is false but improved coll. approx. (not-back-to-back legs) is true 
  //     3 : coll. approx. is false but improved coll. approx. (back-to-back legs) is true 
  int validityCollinearApproxFlag() const { return validityCollinearApproxFlag_; }

  /// get "pseudo" four-momentum computed by CDF method
  /// (for a description of the method, see e.g. CDF note 8972)
  const reco::Candidate::LorentzVector& p4CDFmethod() const { return p4CDFmethod_; }

  /// get transverse mass of visible decay products + missing transverse momentum
  double mt12MET() const { return mt12MET_; }

  /// get transverse mass of first/second
  /// visible decay product + missing transverse momentum
  double mt1MET() const { return mt1MET_; }
  double mt2MET() const { return mt2MET_; }

  /// get transverse momentum of first/second
  /// visible decay product + missing transverse momentum
  double pt1MET() const { 
    if ( leg1_.isAvailable() && leg1_.isNonnull() && met_.isAvailable() && met_.isNonnull() ) 
      return (leg1_->p4() + met_->p4()).pt();
    else 
      return -1.; 
  }
  double pt2MET() const { 
    if ( leg2_.isAvailable() && leg2_.isNonnull() && met_.isAvailable() && met_.isNonnull() ) 
      return (leg2_->p4() + met_->p4()).pt();
    else
      return -1.; 
  }

  /// get acoplanarity angle (angle in transverse plane) between visible decay products
  double dPhi12() const { return dPhi12_; } 

  /// get separation in eta-phi between visible decay products
  double dR12() const { return dR12_; }

  /// get minimal/maximal pseudo-rapidity of visible decay products
  double visEtaMin() const { return visEtaMin_; }
  double visEtaMax() const { return visEtaMax_; }
  
  /// get acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  double dPhi1MET() const { return dPhi1MET_; }
  double dPhi2MET() const { return dPhi2MET_; }

  /// get values of CDF-"zeta" variables
  /// (indicating the consistency of the missing transverse momentum observed in an event
  ///  with the hypothesis of originating from tau neutrinos)
  double pZeta() const { return pZeta_; }
  double pZetaVis() const { return pZetaVis_; }
  double pZetaSig() const { return pZetaSig_; }

  /// get lower bound on Mtautau,
  /// reconstructed by algorithm described in:
  ///   "Speedy Higgs boson discovery in decays to tau lepton pairs: h --> tau tau"
  ///   by Alan J. Barr, Sky T. French, James A. Frost, Christopher G. Lester,
  ///   arXiv: 1106.2322v1 [hep-ph]
  double mTauTauMin() const { return mTauTauMin_; }
  bool mTauTauMin_isValid() const { return mTauTauMinIsValid_; }

  /// clone  object
  CompositePtrCandidateT1T2MEt<T1,T2>* clone() const { return new CompositePtrCandidateT1T2MEt<T1,T2>(*this); }

  friend std::ostream& operator<<(std::ostream& out, const CompositePtrCandidateT1T2MEt<T1,T2>& dic) {
    out << "Di-Candidate m = " << dic.mass();
    return out;
  }

  /// get Mtautau solutions reconstructed by NSVfit algorithm
  bool hasNSVFitSolutions() const { return (nSVfitSolutions_.begin() != nSVfitSolutions_.end()); }
  const NSVfitResonanceHypothesisSummary* nSVfitSolution(const std::string& algorithm, int* errorFlag = 0) const
  {
    const NSVfitResonanceHypothesisSummary* retVal = 0;
    for ( std::vector<NSVfitResonanceHypothesisSummary>::const_iterator nSVfitSolution = nSVfitSolutions_.begin();
	  nSVfitSolution != nSVfitSolutions_.end(); ++nSVfitSolution ) {
      if ( nSVfitSolution->name() == algorithm ) {
	retVal = &(*nSVfitSolution);
	break;
      }
    }

    if ( !retVal ) {
      if ( errorFlag ) {
	(*errorFlag) = 1;
      } else {
	edm::LogError ("CompositePtrCandidateT1T2MEt::nSVfitSolution") 
	  << " No nSVfit solution defined for algorithm = " << algorithm << " !!";
	std::cout << "available = { " << std::endl;
	bool isFirst = true;
	for ( std::vector<NSVfitResonanceHypothesisSummary>::const_iterator nSVfitSolution = nSVfitSolutions_.begin();
	      nSVfitSolution != nSVfitSolutions_.end(); ++nSVfitSolution ) {
	  if ( !isFirst ) std::cout << ", ";
	  std::cout << nSVfitSolution->name();
	  isFirst = false;
	}
	std::cout << " }" << std::endl;
      }
    }
    
    return retVal;
  }

 private:
  
  /// allow only CompositePtrCandidateT1T2MEtAlgorithm to change values of data-members
  template<typename T1_type, typename T2_type> friend class CompositePtrCandidateT1T2MEtAlgorithm; 

  /// set gen. four-momenta
  void setP4Leg1gen(const reco::Candidate::LorentzVector& p4) { p4Leg1gen_ = p4; }
  void setP4Leg2gen(const reco::Candidate::LorentzVector& p4) { p4Leg2gen_ = p4; }
  void setP4VisLeg1gen(const reco::Candidate::LorentzVector& p4) { p4VisLeg1gen_ = p4; }
  void setP4VisLeg2gen(const reco::Candidate::LorentzVector& p4) { p4VisLeg2gen_ = p4; }

  /// set "true" positions of primary event vertex 
  /// and of tau decay vertices (generator level information)
  void setPrimaryVertexPosGen(const reco::Candidate::Point& pos) { primaryVertexPosGen_ = pos; }
  void setDecayVertexPosLeg1gen(const reco::Candidate::Point& pos) { decayVertexPosLeg1gen_ = pos; }
  void setDecayVertexPosLeg2gen(const reco::Candidate::Point& pos) { decayVertexPosLeg2gen_ = pos; }

  /// set (PF)MEt significance matrix
  /// (see CMS AN-10/400 for description of the (PF)MEt significance computation)
  void setMEtSignMatrix(const TMatrixD& covMatrix2by2) 
  { 
    metSignMatrix_ = covMatrix2by2; 
    hasMEtSignMatrix_ = true;
  }

  /// set four-momentum of visible decay products
  void setP4Vis(const reco::Candidate::LorentzVector& p4) { p4Vis_ = p4; } 
  /// set four-momentum and scaling factors for momenta of visible decay products
  /// computed by collinear approximation
  void setCollinearApproxQuantities(const reco::Candidate::LorentzVector& p4, double x1, double x2, bool isValid, int flag)
  {
    p4CollinearApprox_ = p4;
    x1CollinearApprox_ = x1;
    x2CollinearApprox_ = x2;
    collinearApproxIsValid_ = isValid;
    validityCollinearApproxFlag_ = flag;
  }

  /// set four-momentum and scaling factors for momenta of visible decay products
  /// computed by Improved collinear approximation
  void setImprovedCollinearApproxQuantities(
         const reco::Candidate::LorentzVector& p4, double x1, double x2, double scaleFactor, bool isValid, int flag)
  {
    p4ImprovedCollinearApprox_ = p4;
    x1ImprovedCollinearApprox_ = x1;
    x2ImprovedCollinearApprox_ = x2;
    scaleFactor_ = scaleFactor;
    ImprovedCollinearApproxIsValid_ = isValid;
    validityCollinearApproxFlag_ = flag;
  }
  /// set "pseudo" four-momentum computed by CDF method
  /// (for a description of the method, see e.g. CDF note 8972)
  void setP4CDFmethod(const reco::Candidate::LorentzVector& p4) { p4CDFmethod_ = p4; }
  /// set transverse mass of visible decay products + missing transverse momentum
  void setMt12MET(double mt) { mt12MET_ = mt; }
  /// set transverse mass of first/second
  /// visible decay product + missing transverse momentum
  void setMt1MET(double mt) { mt1MET_ = mt; }
  void setMt2MET(double mt) { mt2MET_ = mt; }
  /// set acoplanarity angle (angle in transverse plane) between visible decay products
  void setDPhi12(double dPhi) { dPhi12_ = dPhi; }
  /// set separation in eta-phi between visible decay products
  void setDR12(double dR) { dR12_ = dR; }
  /// set minimal/maximal pseudo-rapidity of visible decay products
  void setVisEtaMin(double eta) { visEtaMin_ = eta; }
  void setVisEtaMax(double eta) { visEtaMax_ = eta; }
  /// set acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  void setDPhi1MET(double dPhi) { dPhi1MET_ = dPhi; }
  void setDPhi2MET(double dPhi) { dPhi2MET_ = dPhi; }
  /// set values of CDF-"zeta" variables
  void setPzeta(double pZeta) { pZeta_ = pZeta; }
  void setPzetaVis(double pZetaVis) { pZetaVis_ = pZetaVis; }
  void setPzetaSig(double pZetaSig) { pZetaSig_ = pZetaSig; }

  /// set lower bound on Mtautau
  void setTauPairMassMin(double mTauTauMin) { mTauTauMin_ = mTauTauMin; }
  void setTauPairMassMin_isValid(bool mTauTauMin_isValid) { mTauTauMinIsValid_ = mTauTauMin_isValid; }

  void addNSVfitSolution(const NSVfitResonanceHypothesisSummary& solution)
  {
    nSVfitSolutions_.push_back(solution);
  }

  /// references/pointers to decay products
  T1Ptr leg1_;
  T2Ptr leg2_;
  MEtPtr met_; 

  /// flag indicating which algorithm was used 
  /// to compute four-momentum of diTau candidate
  std::string recoMode_;

  /// gen. four-momenta
  reco::Candidate::LorentzVector p4Leg1gen_;
  reco::Candidate::LorentzVector p4Leg2gen_;
  reco::Candidate::LorentzVector p4VisLeg1gen_;
  reco::Candidate::LorentzVector p4VisLeg2gen_;

  /// "true" positions of primary event vertex 
  /// and of tau decay vertices (generator level information)
  reco::Candidate::Point primaryVertexPosGen_;
  reco::Candidate::Point decayVertexPosLeg1gen_;
  reco::Candidate::Point decayVertexPosLeg2gen_;

  /// (PF)MEt significance matrix
  /// (see CMS AN-10/400 for description of the (PF)MEt significance computation)
  TMatrixD metSignMatrix_;
  bool hasMEtSignMatrix_;

  /// four-momentum of visible decay products
  reco::Candidate::LorentzVector p4Vis_;
  /// four-momentum and scaling factors for momenta of visible decay products computed by collinear approximation
  reco::Candidate::LorentzVector p4CollinearApprox_;
  bool collinearApproxIsValid_;
  double x1CollinearApprox_;
  double x2CollinearApprox_;

  /// four-momentum of visible decay products
  reco::Candidate::LorentzVector p4ImprovedCollinearApprox_;
  /// four-momentum and x1-x2 fractions computed by improved collinear approximation
  bool ImprovedCollinearApproxIsValid_;
  double x1ImprovedCollinearApprox_;
  double x2ImprovedCollinearApprox_;
  /// scale factors for diTau mass computed in the improved coll. approx.
  double scaleFactor_;
  /// flag to discriminate which approximation is valid
  int validityCollinearApproxFlag_;

  /// "pseudo" four-momentum computed by CDF method
  reco::Candidate::LorentzVector p4CDFmethod_;
  /// transverse mass of visible decay products + missing transverse momentum
  double mt12MET_;
  /// transverse mass of first/second visible decay product + missing transverse momentum
  double mt1MET_;
  double mt2MET_;
  /// acoplanarity angle (angle in transverse plane) between visible decay products
  double dPhi12_;
  /// separation in eta-phi between visible decay products
  double dR12_;
  /// minimal/maximal pseudo-rapidity of visible decay products
  double visEtaMin_;
  double visEtaMax_;
  /// acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  double dPhi1MET_;
  double dPhi2MET_;
  /// CDF-"zeta" variables
  double pZeta_;
  double pZetaVis_;
  double pZetaSig_;

  /// lower bound on Mtautau
  double mTauTauMin_;
  bool mTauTauMinIsValid_;

  /// Mtautau solutions reconstructed by NSVfit algorithm
  std::vector<NSVfitResonanceHypothesisSummary> nSVfitSolutions_;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

typedef CompositePtrCandidateT1T2MEt<reco::Candidate, reco::Candidate> DiCandidatePair;
typedef CompositePtrCandidateT1T2MEt<pat::Electron, pat::Tau> PATElecTauPair;
typedef CompositePtrCandidateT1T2MEt<pat::Muon, pat::Tau> PATMuTauPair;
typedef CompositePtrCandidateT1T2MEt<pat::Tau, pat::Tau> PATDiTauPair;
typedef CompositePtrCandidateT1T2MEt<pat::Electron, pat::Muon> PATElecMuPair;
typedef CompositePtrCandidateT1T2MEt<pat::Electron, pat::Electron> PATDiElecPair;
typedef CompositePtrCandidateT1T2MEt<pat::Muon, pat::Muon> PATDiMuPair;

#endif
