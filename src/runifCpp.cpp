#include <RcppGSL.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include "sampleClass.h"
using namespace Rcpp;

// [[Rcpp::depends(RcppGSL)]]

// [[Rcpp::export]]
NumericVector runifVector(int n, int seed){

  gslRNG runifSampler(seed);

  NumericVector out = runifSampler.runif(n);

  return(out);
}
