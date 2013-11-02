#ifndef AnalysisDataFormats_SVfit_SVfitTauDecayHypothesis_h
#define AnalysisDataFormats_SVfit_SVfitTauDecayHypothesis_h

/*
 * SVfitTauDecayHypothesis
 *
 * Base class representing tau lepton decay to electrons, muons or into hadrons.
 *
 * NOTE: this base-class is used to make persistent solutions of SVfitAlgorithmByLikelihoodMaximization;
 *       solutions of SVfitAlgorithmByIntegration are of type SVfitTauDecayHypothesisBase
 *
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ptr.h"

#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"

#include "AnalysisDataFormats/SVfit/interface/SVfitTauDecayHypothesisBaseT.h"
#include "AnalysisDataFormats/SVfit/interface/SVfitSingleParticleHypothesisBase.h"

class SVfitTauDecayHypothesis : public SVfitTauDecayHypothesisBaseT<SVfitSingleParticleHypothesis>
{
 public:

  SVfitTauDecayHypothesis()
    : leadTrack_(0),
      leadTrackTrajectory_(0)
  {}
  SVfitTauDecayHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : SVfitTauDecayHypothesisBaseT<SVfitSingleParticleHypothesis>(particle, name, barcode),
      leadTrack_(0),
      leadTrackTrajectory_(0)
  {
    p4_ = particle->p4();
  }
  SVfitTauDecayHypothesis(const SVfitTauDecayHypothesis& bluePrint)
    : SVfitTauDecayHypothesisBaseT<SVfitSingleParticleHypothesis>(bluePrint),
      tracks_(bluePrint.tracks_),
      selTracks_(bluePrint.selTracks_),
      selTrackTrajectories_(bluePrint.selTrackTrajectories_),
      leadTrack_(bluePrint.leadTrack_),
      leadTrackTrajectory_(bluePrint.leadTrackTrajectory_),
      p4invis_rf_(bluePrint.p4invis_rf_),
      p4vis_rf_(bluePrint.p4vis_rf_),
      p3Vis_unit_(bluePrint.p3Vis_unit_),
      visMass_(bluePrint.visMass_),
      visEnFracX_(bluePrint.visEnFracX_),
      gjAngle_(bluePrint.gjAngle_),
      phiLab_(bluePrint.phiLab_),
      reconstructedDecayVertexPos_(bluePrint.reconstructedDecayVertexPos_),
      reconstructedDecayVertexCov_(bluePrint.reconstructedDecayVertexCov_),
      hasDecayVertexFit_(bluePrint.hasDecayVertexFit_),
      leadTrackExtrapolationIsValid_(bluePrint.leadTrackExtrapolationIsValid_),
      expectedDecayVertexPos_(bluePrint.expectedDecayVertexPos_),
      expectedDecayVertexCov_(bluePrint.expectedDecayVertexCov_),
      expectedFlightPath_unit_(bluePrint.expectedFlightPath_unit_),
      expectedDecayDistance_(bluePrint.expectedDecayDistance_),
      expectedDecayDistanceJacobiFactor_(bluePrint.expectedDecayDistanceJacobiFactor_)
  {}

  ~SVfitTauDecayHypothesis() {}

  virtual SVfitTauDecayHypothesis& operator=(const SVfitTauDecayHypothesis& bluePrint)
  {
    SVfitTauDecayHypothesisBaseT<SVfitSingleParticleHypothesis>::operator=(bluePrint);
    tracks_ = bluePrint.tracks_;
    selTracks_ = bluePrint.selTracks_;
    selTrackTrajectories_ = bluePrint.selTrackTrajectories_;
    leadTrack_ = bluePrint.leadTrack_;
    leadTrackTrajectory_ = bluePrint.leadTrackTrajectory_;
    p4invis_rf_ = bluePrint.p4invis_rf_;
    p4vis_rf_ = bluePrint.p4vis_rf_;
    p3Vis_unit_ = bluePrint.p3Vis_unit_;
    visMass_ = bluePrint.visMass_;
    visEnFracX_ = bluePrint.visEnFracX_;
    gjAngle_ = bluePrint.gjAngle_;
    phiLab_ = bluePrint.phiLab_;
    reconstructedDecayVertexPos_ = bluePrint.reconstructedDecayVertexPos_;
    reconstructedDecayVertexCov_ = bluePrint.reconstructedDecayVertexCov_;
    hasDecayVertexFit_ = bluePrint.hasDecayVertexFit_;
    leadTrackExtrapolationIsValid_ = bluePrint.leadTrackExtrapolationIsValid_;
    expectedDecayVertexPos_ = bluePrint.expectedDecayVertexPos_;
    expectedDecayVertexCov_ = bluePrint.expectedDecayVertexCov_;
    expectedFlightPath_unit_ = bluePrint.expectedFlightPath_unit_;
    expectedDecayDistance_ = bluePrint.expectedDecayDistance_;
    expectedDecayDistanceJacobiFactor_ = bluePrint.expectedDecayDistanceJacobiFactor_;
    return (*this);
  }

  /// collection of tracks associated to reco::Candidate
  virtual const std::vector<const reco::Track*>& tracks() const { return tracks_; }

  /// collection of tracks associated to reco::Candidate and passing track selection
  const std::vector<const reco::Track*>& selTracks() const { return selTracks_; }
  const std::vector<reco::TransientTrack>& selTrackTrajectories() const { return selTrackTrajectories_; }

  /// "leading" (highest Pt track)
  const reco::Track* leadTrack() const { return leadTrack_; }
  const reco::TransientTrack* leadTrackTrajectory() const { return leadTrackTrajectory_; }

  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  const reco::Candidate::LorentzVector& p4vis_rf()   const { return p4vis_rf_;   }
  const reco::Candidate::LorentzVector& p4invis_rf() const { return p4invis_rf_; }

  /// direction and mass of visible decay products
  const reco::Candidate::Vector& p3Vis_unit() const { return p3Vis_unit_; }
  double visMass() const { return visMass_; }

  /// energy ratio of visible decay products/tau lepton energy
  double visEnFracX() const { return visEnFracX_; }

  /// decay angles in tau lepton rest-frame
  double gjAngle() const { return gjAngle_; }
  double phiLab() const { return phiLab_; }

  /// access to position of secondary vertex (tau lepton decay vertex)
  /// reconstructed from fitting selected tracks
  const AlgebraicVector3& reconstructedDecayVertexPos() const { return reconstructedDecayVertexPos_; } 
  const AlgebraicMatrix33& reconstructedDecayVertexCov() const { return reconstructedDecayVertexCov_; } 

  bool leadTrackExtrapolationIsValid() const { return leadTrackExtrapolationIsValid_; }
  int leadTrackExtrapolationError() const { return leadTrackExtrapolationError_; }

  bool hasDecayVertexFit() const { return hasDecayVertexFit_; }

  /// access to position of secondary vertex (tau lepton decay vertex)
  /// computed from decay angles in tau lepton rest-frame plus decay distance
  const AlgebraicVector3& expectedDecayVertexPos() const { return expectedDecayVertexPos_; } 
  const AlgebraicMatrix33& expectedDecayVertexCov() const { return expectedDecayVertexCov_; }
  const AlgebraicVector3& expectedFlightPath_unit() const { return expectedFlightPath_unit_; }
  double expectedDecayDistance() const { return expectedDecayDistance_; }
  double expectedDecayDistanceJacobiFactor() const { return expectedDecayDistanceJacobiFactor_; }

  void print(std::ostream& stream) const
  {
    stream << "<SVfitTauDecayHypothesis::print>:" << std::endl;
    stream << " name = " << name_ << std::endl;
    stream << " barcode = " << barcode_ << std::endl;
    stream << " particle(id:key) = " << particle_.id() << ":" << particle_.key() << std::endl;
    stream << " p4Vis: Pt = " << p4_.pt() << ","
	   << " eta = " << p4_.eta() << ", phi = " << p4_.phi() 
	   << " (E = " << p4_.E() << ", Px = " << p4_.px() << ", Py = " << p4_.py() << ", mass = " << p4_.mass() << ")" << std::endl;
    reco::Candidate::LorentzVector p4Invis = p4_fitted() - p4_;
    stream << " p4Invis: Pt = " << p4Invis.pt() << ","
	   << " eta = " << p4Invis.eta() << ", phi = " << p4Invis.phi() 
	   << " (E = " << p4Invis.E() << ", Px = " << p4Invis.px() << ", Py = " << p4Invis.py() << ", mass = " << p4Invis.mass() << ")" << std::endl;  
    stream << " p4Tau: Pt = " << p4_fitted().pt() << ","
	   << " eta = " << p4_fitted().eta() << ", phi = " << p4_fitted().phi() 
	   << " (E = " << p4_fitted().E() << ", Px = " << p4_fitted().px() << ", Py = " << p4_fitted().py() << ", mass = " << p4_fitted().mass() << ")" << std::endl;    
    stream << "(gjAngle = " << gjAngle_ << ", phiLab = " << phiLab_ << ", x = " << visEnFracX_ << ")" << std::endl;
    stream << " isValidSolution = " << isValidSolution_ << std::endl;
  }

  friend class SVfitTauDecayBuilder;
  template<typename T1, typename T2> friend class CompositePtrCandidateT1T2MEt;

 protected:

  /// collection of tracks associated to reco::Candidate
  std::vector<const reco::Track*> tracks_;                      // transient data-member
  std::vector<const reco::Track*> selTracks_;                   // transient data-member
  std::vector<reco::TransientTrack> selTrackTrajectories_;      // transient data-member
  const reco::Track* leadTrack_;                                // transient data-member
  reco::TransientTrack* leadTrackTrajectory_;                   // transient data-member

  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  reco::Candidate::LorentzVector p4invis_rf_;
  reco::Candidate::LorentzVector p4vis_rf_;

  /// direction and mass of visible decay products
  reco::Candidate::Vector p3Vis_unit_;
  double visMass_;

  /// energy ratio of visible decay products/tau lepton energy
  double visEnFracX_;

  /// decay angles in tau lepton rest-frame
  double gjAngle_;
  double phiLab_;

  /// position of reconstructed tau lepton decay vertex
  AlgebraicVector3 reconstructedDecayVertexPos_;
  AlgebraicMatrix33 reconstructedDecayVertexCov_;
  
  bool hasDecayVertexFit_;

  bool leadTrackExtrapolationIsValid_;   
  int leadTrackExtrapolationError_;                             // transient data-member 

  AlgebraicVector3 expectedDecayVertexPos_;
  AlgebraicMatrix33 expectedDecayVertexCov_;
  AlgebraicVector3 expectedFlightPath_unit_;                    // transient data-member
  double expectedDecayDistance_;
  double expectedDecayDistanceJacobiFactor_;                    // transient data-member
};

#endif /* end of include guard: AnalysisDataFormats_SVfit_SVfitTauDecayHypothesis_h */
