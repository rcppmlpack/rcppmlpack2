// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/logistic_regression/logistic_regression.hpp> 	// particular algorithm used here

// [[Rcpp::export]]
arma::irowvec logisticRegression(const arma::mat& train,
                                 const arma::mat& test,
                                 const arma::irowvec& labels) {
    
    // MLPACK wants Row<size_t> which is an unsigned representation
    // that R does not have
    arma::Row<size_t> labelsur, resultsur;

    // TODO: check that all values are non-negative
    labelsur = arma::conv_to<arma::Row<size_t>>::from(labels);

    // Initialize with the default arguments.
    // TODO: support more arguments>
    mlpack::regression::LogisticRegression<> lrc(train, labelsur);
    
    lrc.Classify(test, resultsur);
    
    arma::irowvec results = arma::conv_to<arma::irowvec>::from(resultsur);
    
    return results;
}

// [[Rcpp::export]]
arma::vec logisticRegressionParameters(const arma::mat& train,
                                       const arma::irowvec& labels) {
    
    // MLPACK wants Row<size_t> which is an unsigned representation
    // that R does not have
    arma::Row<size_t> labelsur;

    // TODO: check that all values are non-negative
    labelsur = arma::conv_to<arma::Row<size_t>>::from(labels);

    // Initialize with the default arguments.
    // TODO: support more arguments>
    mlpack::regression::LogisticRegression<> lrc(train, labelsur);
    
    return lrc.Parameters();
}

