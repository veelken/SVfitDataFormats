#include "AnalysisDataFormats/SVfit/interface/SVfitResonanceHypothesisBase.h"

SVfitResonanceHypothesisBase::SVfitResonanceHypothesisBase(const SVfitResonanceHypothesisBase& bluePrint)
  : name_(bluePrint.name_),
    barcode_(bluePrint.barcode_),
    daughters_(bluePrint.daughters_),
    mass_(bluePrint.mass_),
    massErrUp_(bluePrint.massErrUp_),
    massErrDown_(bluePrint.massErrDown_),
    isValidSolution_(bluePrint.isValidSolution_)
{}

SVfitResonanceHypothesisBase& SVfitResonanceHypothesisBase::operator=(const SVfitResonanceHypothesisBase& bluePrint)
{  
  name_ = bluePrint.name_;
  barcode_ = bluePrint.barcode_;
  daughters_ = bluePrint.daughters_;
  mass_ = bluePrint.mass_;
  massErrUp_ = bluePrint.massErrUp_;
  massErrDown_ = bluePrint.massErrDown_;
  isValidSolution_ = bluePrint.isValidSolution_;
  return (*this);
}

//
//-------------------------------------------------------------------------------
//

bool operator<(const SVfitResonanceHypothesisBase& hypothesis1, const SVfitResonanceHypothesisBase& hypothesis2)
{
  return (hypothesis1.barcode() < hypothesis2.barcode());
}
