#ifndef AnalysisDataFormats_SVfit_SVfitEventHypothesisBaseFwd_h
#define AnalysisDataFormats_SVfit_SVfitEventHypothesisBaseFwd_h

#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesisBase.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/RefVector.h"

#include <vector>

/// collection of SVfitEventHypothesis objects
typedef std::vector<SVfitEventHypothesisBase> SVfitEventHypothesisBaseCollection;

/// persistent reference to a SVfitEventHypothesis object
typedef edm::Ref<SVfitEventHypothesisBaseCollection> SVfitEventHypothesisBaseRef;

/// references to SVfitEventHypothesis collection
typedef edm::RefProd<SVfitEventHypothesisBaseCollection> SVfitEventHypothesisBaseRefProd;

/// vector of references to SVfitEventHypothesis objects all in the same collection
typedef edm::RefVector<SVfitEventHypothesisBaseCollection> SVfitEventHypothesisBaseRefVector;

#endif
