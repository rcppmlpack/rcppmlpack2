// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

// particular algorithm used here
#include <mlpack/methods/logistic_regression/logistic_regression.hpp> 	

//' Run a Logistic Regression given training data (and optional test data).
//'
//' This function uses a train set matrix and vector of target labels to run
//' a logistic regression. If an optional test data set is supplied, it will
//' be evaluated given the estimates from the initial test set.
//'
//' @title Run a Logistic Regression
//' @param train A matrix of training data values
//' @param labels An integer vector of target (class) labels, with the same 
//'  length as the training data set
//' @param test An optional test set, with the same number of columns as
//'  the test set.
//' @return A list with several components: means of training data means,
//'  variance of training data variances, probanbilities of training data
//'  class probabilities. If a test data set was supplied an estimated
//'  classification vector is also returned.
//' @examples
//' data(trainSet)
//' mat <- t(trainSet[, -5])     ## train data, transpose and removing class labels
//' lab <- trainSet[, 5]         ## class labels for train set
//' logisticRegression(mat, lab)
//' testMat <- t(testSet[, -5])  ## test data
//' logisticRegression(mat, lab, testMat)
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
