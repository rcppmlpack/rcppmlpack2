// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/kmeans/kmeans.hpp> 	// particular algorithm used here


// [[Rcpp::export]]
Rcpp::List kmeans(const arma::mat& data, const int& clusters) {
    
    arma::Row<size_t> assignments; 		// to store results
    mlpack::kmeans::KMeans<> k;    		// initialize with the default arguments.
    k.Cluster(data, clusters, assignments);     // make call, filling 'assignments'

    return Rcpp::List::create(Rcpp::Named("clusters") = clusters,
                              Rcpp::Named("result")   = assignments);
}
