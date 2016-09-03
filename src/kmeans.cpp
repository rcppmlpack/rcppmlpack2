// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/kmeans/kmeans.hpp> 	// particular algorithm used here


// [[Rcpp::export]]
Rcpp::List kmeans(const arma::mat& data, const int& clusters) {
    
    arma::Row<size_t> assignments;

    // Initialize with the default arguments.
    mlpack::kmeans::KMeans<> k;

    k.Cluster(data, clusters, assignments); 

    return Rcpp::List::create(Rcpp::Named("clusters")	= clusters,
                              Rcpp::Named("result")	= assignments);
}
