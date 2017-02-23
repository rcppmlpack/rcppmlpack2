// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

// particular algorithm used here
#include <mlpack/methods/naive_bayes/naive_bayes_classifier.hpp> 	

//' Run a Naive Bayes Classifier given training data (and optional test data).
//'
//' This function uses train set matrix and vector of target labels to run
//' a naive Bayes classifier for an externally given nummber of class. If
//' an optional test data set is supplied, it will be evulated given the
//' estimated from the initial test set.
//'
//' @title Run a Naive Bayes Classifier
//' @param train A matrix of training data values
//' @param labels An integer vector of target (class) labels, with the same 
//'  length and the training data set
//' @param classes An integer with the given number of classes
//' @param test An optional test set, with the same number of columns as
//'  the test set.
//' @return A list with several components: means of training data means,
//'  variance of training data variances, probanbilities of training data
//'  class probabilities. If a test data set was supplied an estimated
//'  classification vector is also returned.
//' @examples
//' data(trainSet)
//' M <- t(trainSet[, -5])    ## train data, transpose and removing class labels
//' lb <- trainSet[, 5]       ## class labels for train set
//' naiveBayesClassifier(M, lb, 2L)
//' tM <- t(testSet[, -5])    ## test data
//' naiveBayesClassifier(M, lb, 2L, tM)
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
        return Rcpp::List::create(Rcpp::Named("means") = nbc.Means(),
                                  Rcpp::Named("variances") = nbc.Variances(),
                                  Rcpp::Named("probabilities") = nbc.Probabilities(),
                                  Rcpp::Named("classification") = results);
    } else {
        return Rcpp::List::create(Rcpp::Named("means") = nbc.Means(),
                                  Rcpp::Named("variances") = nbc.Variances(),
                                  Rcpp::Named("probabilities") = nbc.Probabilities());
    }
}
