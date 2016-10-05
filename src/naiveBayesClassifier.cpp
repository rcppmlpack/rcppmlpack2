// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/naive_bayes/naive_bayes_classifier.hpp> 	// particular algorithm used here

// [[Rcpp::export]]
arma::irowvec naiveBayesClassifier(const arma::mat& train,
                                   const arma::mat& test,
                                   const arma::irowvec& labels,
                                   const int& classes) {
    
    // MLPACK wants Row<size_t> which is an unsigned representation
    // that R does not have
    arma::Row<size_t> labelsur, resultsur;

    // TODO: check that all values are non-negative
    labels_ = arma::conv_to<arma::Row<size_t>>::from(labels);

    // Initialize with the default arguments.
    // TODO: support more arguments>
    mlpack::naive_bayes::NaiveBayesClassifier<> nbc(train, labels_, classes);
    
    nbc.Classify(test, results_);
    
    arma::irowvec results = arma::conv_to<arma::irowvec>::from(results_);
    
    return results;
}
