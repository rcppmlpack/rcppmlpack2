// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

// particular algorithm used here
#include <mlpack/methods/naive_bayes/naive_bayes_classifier.hpp> 	

// [[Rcpp::export]]
Rcpp::List naiveBayesClassifier(const arma::mat& train,
                                   const arma::irowvec& labels,
                                   const int& classes,
                                   const Rcpp::Nullable<Rcpp::NumericMatrix>& test = R_NilValue) {
    
    // MLPACK wants Row<size_t> which is an unsigned representation
    // that R does not have
    arma::Row<size_t> labelsur, resultsur;

    // TODO: check that all values are non-negative
    labelsur = arma::conv_to<arma::Row<size_t>>::from(labels);

    // Initialize with the default arguments.
    // TODO: support more arguments>
    mlpack::naive_bayes::NaiveBayesClassifier<> nbc(train, labelsur, classes);

    Rcpp::List return_val;
    if (test.isNotNull()) {
        arma::mat armatest = Rcpp::as<arma::mat>(test);
        nbc.Classify(armatest, resultsur);
    
        arma::irowvec results = arma::conv_to<arma::irowvec>::from(resultsur);
        return Rcpp::List::create(Rcpp::Named("means") = nbc.Mean(),
                                  Rcpp::Named("variances") = nbc.Variances(),
                                  Rcpp::Named("probabilities") = nbc.Probabilities(),
                                  Rcpp::Named("classification") = results);
    } else {
        return Rcpp::List::create(Rcpp::Named("means") = nbc.Mean(),
                                  Rcpp::Named("variances") = nbc.Variances(),
                                  Rcpp::Named("probabilities") = nbc.Probabilities());
    }
}
