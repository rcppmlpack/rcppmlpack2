// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/logistic_regression/logistic_regression.hpp> 	// particular algorithm used here

// [[Rcpp::export]]
Rcpp::List logisticRegression(const arma::mat& train,
                              const arma::irowvec& labels,
                              const Rcpp::Nullable<Rcpp::NumericMatrix>& test = R_NilValue) {
    
    // MLPACK wants Row<size_t> which is an unsigned representation
    // that R does not have
    arma::Row<size_t> labelsur, resultsur;

    // TODO: check that all values are non-negative
    labelsur = arma::conv_to<arma::Row<size_t>>::from(labels);

    // Initialize with the default arguments.
    // TODO: support more arguments>
    mlpack::regression::LogisticRegression<> lrc(train, labelsur);
    
    arma::vec parameters = lrc.Parameters();

    Rcpp::List return_val;
    
    if (test.isNotNull()) {
      arma::mat test2 = Rcpp::as<arma::mat>(test);
      lrc.Classify(test2, resultsur);
      arma::vec results = arma::conv_to<arma::vec>::from(resultsur);
      return_val = Rcpp::List::create(Rcpp::Named("parameters") = parameters,
                                      Rcpp::Named("results") = results);
    } else {
      return_val = Rcpp::List::create(Rcpp::Named("parameters") = parameters);
    }

    return return_val;

}
