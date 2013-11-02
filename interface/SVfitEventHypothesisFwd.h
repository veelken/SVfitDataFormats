#ifndef AnalysisDataFormats_SVfit_SVfitEventHypothesisFwd_h
#define AnalysisDataFormats_SVfit_SVfitEventHypothesisFwd_h

#include "AnalysisDataFormats/SVfit/interface/SVfitEventHypothesis.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/RefVector.h"

#include <vector>

/// collection of SVfitEventHypothesis objects
typedef std::vector<SVfitEventHypothesis> SVfitEventHypothesisCollection;

/// persistent reference to a SVfitEventHypothesis object
typedef edm::Ref<SVfitEventHypothesisCollection> SVfitEventHypothesisRef;

/// references to SVfitEventHypothesis collection
typedef edm::RefProd<SVfitEventHypothesisCollection> SVfitEventHypothesisRefProd;

/// vector of references to SVfitEventHypothesis objects all in the same collection
typedef edm::RefVector<SVfitEventHypothesisCollection> SVfitEventHypothesisRefVector;

#endif
