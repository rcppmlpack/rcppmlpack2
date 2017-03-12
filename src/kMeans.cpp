// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/kmeans/kmeans.hpp> 	// particular algorithm used here


//' Run a k-means clustering analysis, returning a list of cluster assignments
//'
//' This function performs a k-means clustering analysis on the given data set.
//'
//' @title Run a k-means clustering analysis
//' @param dataset A matrix of data values
//' @param clusters An integer specifying the number of clusters
//' @return A list with cluster assignments
//' @examples
//' x <- rbind(matrix(rnorm(100, sd = 0.3), ncol = 2),
//'            matrix(rnorm(100, mean = 1, sd = 0.3), ncol = 2))
//' colnames(x) <- c("x", "y")
//' cl <- kMeans(x, 2)
//'
//' data(trees, package="datasets")
//' cl2 <- kMeans(t(trees),3)
// [[Rcpp::export]]
Rcpp::List kMeans(const arma::mat& data, const int& clusters) {
    
    arma::Row<size_t> assignments; 		// to store results
    mlpack::kmeans::KMeans<> k;    		// initialize with the default arguments.
    k.Cluster(data, clusters, assignments);     // make call, filling 'assignments'

    return Rcpp::List::create(Rcpp::Named("clusters") = clusters,
                              Rcpp::Named("result")   = assignments);
}
