
#include <RcppMLPACK.h>				// declares MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/kmeans/kmeans.hpp> 	// particular algorithm used here

// RcppMLPACK setup and C++11 use are enabled via src/Makevars{,win}

// [[Rcpp::export]]
Rcpp::List mlkmeans(const arma::mat& data, const int& clusters) {

    arma::Row<size_t> assignments; 		// to store results
    mlpack::kmeans::KMeans<> k;    		// initialize with the default arguments.
    k.Cluster(data, clusters, assignments);     // make call, filling 'assignments'

    return Rcpp::List::create(Rcpp::Named("clusters") = clusters,
                              Rcpp::Named("result")   = assignments);
}
