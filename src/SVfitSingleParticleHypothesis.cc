#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesis.h"

SVfitSingleParticleHypothesis::SVfitSingleParticleHypothesis() 
  : mother_(NULL),
    pt_(0.),
    ptErrUp_(0.),
    ptErrDown_(0.),
    pt_isValid_(false),    
    eta_(0.),
    etaErrUp_(0.),
    etaErrDown_(0.),
    eta_isValid_(false),   
    phi_(0.),
    phiErrUp_(0.),
    phiErrDown_(0.),
    phi_isValid_(false)
{}

SVfitSingleParticleHypothesis::SVfitSingleParticleHypothesis(const std::string& name, int barcode)
  : SVfitSingleParticleHypothesisBase(name, barcode),
    mother_(NULL),
    pt_(0.),
    ptErrUp_(0.),
    ptErrDown_(0.),
    pt_isValid_(false),    
    eta_(0.),
    etaErrUp_(0.),
    etaErrDown_(0.),
    eta_isValid_(false),   
    phi_(0.),
    phiErrUp_(0.),
    phiErrDown_(0.),
    phi_isValid_(false)
{}

SVfitSingleParticleHypothesis::SVfitSingleParticleHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
  : SVfitSingleParticleHypothesisBase(particle, name, barcode),
    mother_(NULL),
    p4_(particle->p4()),
    pt_(0.),
    ptErrUp_(0.),
    ptErrDown_(0.),
    pt_isValid_(false),    
    eta_(0.),
    etaErrUp_(0.),
    etaErrDown_(0.),
    eta_isValid_(false),   
    phi_(0.),
    phiErrUp_(0.),
    phiErrDown_(0.),
    phi_isValid_(false)
{}

SVfitSingleParticleHypothesis::SVfitSingleParticleHypothesis(const SVfitSingleParticleHypothesis& bluePrint)
  : SVfitSingleParticleHypothesisBase(bluePrint),
    mother_(bluePrint.mother_),
    p4_(bluePrint.p4_),
    p4_fitted_(bluePrint.p4_fitted_),
    dp4_(bluePrint.dp4_),
    pt_(bluePrint.pt_),
    ptErrUp_(bluePrint.ptErrUp_),
    ptErrDown_(bluePrint.ptErrDown_),
    pt_isValid_(bluePrint.pt_isValid_),    
    eta_(bluePrint.eta_),
    etaErrUp_(bluePrint.etaErrUp_),
    etaErrDown_(bluePrint.etaErrDown_),
    eta_isValid_(bluePrint.eta_isValid_),   
    phi_(bluePrint.phi_),
    phiErrUp_(bluePrint.phiErrUp_),
    phiErrDown_(bluePrint.phiErrDown_),
    phi_isValid_(bluePrint.phi_isValid_),
    polHandedness_(bluePrint.polHandedness_),
    polSign_(bluePrint.polSign_)
{}

SVfitSingleParticleHypothesis& SVfitSingleParticleHypothesis::operator=(const SVfitSingleParticleHypothesis& bluePrint)  
{  
  SVfitSingleParticleHypothesisBase::operator=(bluePrint);
  mother_ = bluePrint.mother_;
  p4_ = bluePrint.p4_;
  p4_fitted_ = bluePrint.p4_fitted_;
  dp4_ = bluePrint.dp4_;
  pt_ = bluePrint.pt_;
  ptErrUp_ = bluePrint.ptErrUp_;
  ptErrDown_ = bluePrint.ptErrDown_;
  pt_isValid_ = bluePrint.pt_isValid_;
  eta_ = bluePrint.eta_;
  etaErrUp_ = bluePrint.etaErrUp_;
  etaErrDown_ = bluePrint.etaErrDown_;
  eta_isValid_ = bluePrint.eta_isValid_;
  phi_ = bluePrint.phi_;
  phiErrUp_ = bluePrint.phiErrUp_;
  phiErrDown_ = bluePrint.phiErrDown_;
  phi_isValid_ = bluePrint.phi_isValid_;
  polHandedness_ = bluePrint.polHandedness_;
  polSign_ = bluePrint.polSign_;
  return (*this);
}
