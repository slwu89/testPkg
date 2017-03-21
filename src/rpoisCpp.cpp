#include <RcppGSL.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include "sampleClass.h"
using namespace Rcpp;

// [[Rcpp::depends(RcppGSL)]]

// [[Rcpp::export]]
IntegerVector rpoisVector(int n, int seed, double mu){

  gslRNG rpoisSampler(seed);

  IntegerVector out = rpoisSampler.rpois(n,mu);

  return(out);
}
