#ifndef AnalysisDataFormats_SVfit_SVfitSingleParticleHypothesisBase_h
#define AnalysisDataFormats_SVfit_SVfitSingleParticleHypothesisBase_h

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/Common/interface/Ptr.h"

#include <string>

class SVfitSingleParticleHypothesisBase
{
 public:

  SVfitSingleParticleHypothesisBase()
    : isValidSolution_(false) 
  {}
  SVfitSingleParticleHypothesisBase(const std::string& name, int barcode)
    : name_(name),
      barcode_(barcode),
      isValidSolution_(false) 
  {}  
  SVfitSingleParticleHypothesisBase(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : name_(name),
      barcode_(barcode),
      particle_(particle),
      isValidSolution_(false) 
  {}
  SVfitSingleParticleHypothesisBase(const SVfitSingleParticleHypothesisBase& bluePrint)
    : name_(bluePrint.name_),
      barcode_(bluePrint.barcode_),
      particle_(bluePrint.particle_),
      isValidSolution_(false) 
  {}
  virtual ~SVfitSingleParticleHypothesisBase() {}

  virtual SVfitSingleParticleHypothesisBase* clone() const = 0;
  virtual SVfitSingleParticleHypothesisBase* reduceToBase() const = 0;

  virtual SVfitSingleParticleHypothesisBase& operator=(const SVfitSingleParticleHypothesisBase& bluePrint)
  {
    name_ = bluePrint.name_;
    barcode_ = bluePrint.barcode_;
    particle_ = bluePrint.particle_;
    //assert(particle_.get() != 0);
    return (*this);
  }

  const std::string& name() const { return name_; }
  int barcode() const { return barcode_; }

  /// pointer to reco::Candidate from which this hypothesis was made
  virtual const edm::Ptr<reco::Candidate>& particle() const { return particle_; }

  virtual void print(std::ostream& stream) const
  {
    stream << "<SVfitSingleParticleHypothesisBase::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    stream << " barcode = " << barcode_ << std::endl;
    stream << " particle(id:key) = " << particle_.id() << ":" << particle_.key() << std::endl;
    stream << " isValidSolution = " << isValidSolution_ << std::endl;
  }

 protected:

  /// "human-readable" label for print-out
  std::string name_;

  /// unique identifier to associate hypothesis to likelihood function
  int barcode_;

  /// pointer to reco::Candidate from which this hypothesis was made
  edm::Ptr<reco::Candidate> particle_;

  /// flag indicating that computed mass hypotheses are physically "valid" solutions
  bool isValidSolution_;
};

// CV: implementation of operator< needed to store SVfitSingleParticleHypothesisBase objects in edm::OwnVector
bool operator<(const SVfitSingleParticleHypothesisBase&, const SVfitSingleParticleHypothesisBase&);

#endif
