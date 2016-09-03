#include <Rcpp.h>			// header hierarchy to be sorted out
#include <RcppArmadilloConfig.h> 	// header hierarchy to be sorted out
#include <RcppMLPACK.h>			// header hierarchy to be sorted out

#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>

using namespace mlpack::kmeans;

// [[Rcpp::export]]
Rcpp::List kmeans(const arma::mat& data, const int& clusters) {
    
    arma::Row<size_t> assignments;

    // Initialize with the default arguments.
    KMeans<> k;

    k.Cluster(data, clusters, assignments); 

    return Rcpp::List::create(Rcpp::Named("clusters")	= clusters,
                              Rcpp::Named("result")	= assignments);
}
