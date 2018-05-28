#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/lars/lars.hpp> 		// particular algorithm used here

//' Run a lars/lasso/elasticNet regression
//'
//' This function performs a lars, lasso or elastic net regression.
//'
//' @title Run a lars / lasso / elasticNet regression
//' @param matX A matrix of explanatory variables, i.e. regressors
//' @param vecY A vector with the target variable
//' @param lambda1 A doube with l1-norm penalty regularization parameter
//' @param lambda2 A doube with l2-norm penalty regularization parameter
//' @param useCholesky A logical value indicating whether to use the Cholesky
//' @param testX A optional matrix of test values to validate prediction
//' decomposition when solving the linear system, else full Gram matrix is used.
//' @return A list with estimated coefficient, the value of lambda1 after each iteration
//' and the predicted values, either from the training data or, if supplied, the test
//' set.
//' @examples
//' ## LARS demo data set from MLPACK with limited rank
//' data(lars)
//' fit1 <- LARS(matX = lars_dependent_x, vecY = lars_dependent_y, 0.1, 0.1, FALSE)
//' fit2 <- LARS(matX = lars_dependent_x, vecY = lars_dependent_y, 0.1, 0.1, TRUE)
// [[Rcpp::export]]
Rcpp::List LARS(arma::mat& matX, arma::vec& vecY,
                const double lambda1, const double lambda2,
                bool useCholesky = false,
                const Rcpp::Nullable<Rcpp::NumericMatrix>& testX = R_NilValue) {

    // Initialize the object.
    mlpack::regression::LARS lars(useCholesky, lambda1, lambda2);

    // Make sure y is oriented the right way.
    if (vecY.n_rows == 1)
        vecY = arma::trans(vecY);

    if (vecY.n_elem != matX.n_rows)
        Rcpp::stop("Number of responses must be equal to number of rows of X!");

    arma::vec beta;
    lars.Train(matX, vecY, beta, false /* do not transpose */);

    arma::vec lmb = lars.LambdaPath();
    arma::rowvec predictions;
    if (testX.isNotNull()) {
        arma::mat testset = Rcpp::as<arma::mat>(testX);
        if (testset.n_cols != lars.BetaPath().back().n_elem)
            Rcpp::stop("Dimensionality of test set (%d) "
                       "is not equal to the dimensionality of the model (%d)",
                       testset.n_cols, lars.BetaPath().back().n_elem);
        lars.Predict(testset.t(), predictions, false);
    } else {
        lars.Predict(matX.t(), predictions, false);
    }

    return Rcpp::List::create(Rcpp::Named("beta") = beta,
                              Rcpp::Named("lamdaPath") = lmb,
                              Rcpp::Named("predictions") = predictions);
}
