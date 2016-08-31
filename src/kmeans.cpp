#include "RcppMLPACK.h"

#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>
#include <Rcpp.h>

using namespace mlpack::kmeans;
using namespace Rcpp;

// [[Rcpp::export]]
List kmeans(const arma::mat& data, const int& clusters) {
    
    arma::Row<size_t> assignments;

    // Initialize with the default arguments.
    KMeans<> k;

    k.Cluster(data, clusters, assignments); 

    return List::create(_["clusters"]	= clusters,
                        _["result"]	= assignments);
}
