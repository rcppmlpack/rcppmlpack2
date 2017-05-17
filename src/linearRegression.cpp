
#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/linear_regression/linear_regression.hpp> // particular algorithm used here

//' Run a linear regression (with optional ridge regression)
//'
//' This function performs a linear regression, and serves as a simple
//' test case for accessing an MLPACK function.
//'
//' @title Run a linear regression with optional ridge regression
//' @param matX A matrix of explanatory variables ('predictors') in standard
//' R format (i.e. \sQuote{tall and skinny'} to be transposed internally to MLPACK
//' format (i.e. `\sQuote{short and wide}).
//' @param vecY A vector of dependent variables ('responses')
//' @param lambda An optional ridge parameter, defaults to zero
//' @param intercept An optional boolean switch about an intercept, default is true.
//' @return A vector with fitted values
//' @examples
//'   # tbd
// [[Rcpp::export]]
arma::vec linearRegression(arma::mat& matX,
                           arma::vec& vecY,
                           const double lambda = 0.0,
                           const bool intercept = true) {

    //matX.print("X");
    matX = matX.t();
    mlpack::regression::LinearRegression lr(matX, vecY, lambda, intercept);

    arma::vec fittedValues(vecY.n_elem);
    lr.Predict(matX,  fittedValues);
    return fittedValues;
}
