#ifndef sampleClass_H
#define sampleClass_H

#include <RcppGSL.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppGSL)]]

/*
 * Definition of a sample class to test linking one .h to multiple .cpp
 * February 15, 2017
 */

class gslRNG {
public:

  // constructors
  gslRNG(int seed): seedAttr(seed) {};

  // class attributes
  int seedAttr;

  // class methods

  // draw rng from U(0,1)
  NumericVector runif(int n){
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r,seedAttr);
    NumericVector out(n);
    for(int i=0; i<n; i++){
      out[i] = gsl_ran_flat(r,0.0,1.0);
    }
    return(out);
  }

  // drawn rng from pois(lambda=mu)
  IntegerVector rpois(int n, double mu){
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r,seedAttr);
    IntegerVector out(n);
    for(int i=0; i<n; i++){
      out[i] = gsl_ran_poisson(r,mu);
    }
    return(out);
  }

}; // end class definition

#endif /* sampleClass_H */
