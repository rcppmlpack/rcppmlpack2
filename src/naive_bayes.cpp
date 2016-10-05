// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/naive_bayes/naive_bayes_classifier.hpp> 	// particular algorithm used here

// [[Rcpp::export]]
arma::irowvec naive_bayes(const arma::mat& train, const arma::mat& test, const arma::Row<size_t>& labels, const int& classes) {
    
    arma::Row<size_t> mlp_results;

    // Initialize with the default arguments.
    mlpack::naive_bayes::NaiveBayesClassifier<> nbc(train, labels, classes);
    
    nbc.Classify(test, mlp_results);
    
    arma::irowvec results = arma::conv_to<arma::irowvec>::from(mlp_results);
    
    return results;
}
