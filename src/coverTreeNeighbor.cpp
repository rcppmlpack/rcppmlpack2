// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>

#include <mlpack/methods/neighbor_search/neighbor_search.hpp>
#include <mlpack/core/tree/cover_tree.hpp>

using namespace Rcpp;
using namespace mlpack;
using namespace mlpack::neighbor;
using namespace mlpack::metric;
using namespace mlpack::tree;

//' Run a Cover Tree distance measure analysis which provides a specialised 
//'
//' This function performs a distance calculation using a Cover Tree.
//' A cover tree is a tree specifically designed to speed up nearest-neighbor
//' computation in high-dimensional spaces.  Each non-leaf node references a
//' point and has a nonzero number of children, including a \dQuote{self-child} which
//' references the same point.  A leaf node represents only one point.
//'
//' @title Run a Cover Tree distance analysis
//' @param dataset A matrix of training data values
//' @param k An integer specifying the number of classes
//' @return A list with two elements giving the nighbors and their distances
// [[Rcpp::export]]
List coverTreeNeighbor(const arma::mat& dataset, const int k) {

    // define a shortcut via a typedef
    typedef CoverTree<LMetric<2, true>, NeighborSearchStat<FurthestNeighborSort>,
                      arma::mat, FirstPointIsRoot> TreeType;

    TreeType referenceTree = TreeType(dataset);
    
    NeighborSearch<FurthestNeighborSort, LMetric<2, true>, arma::mat,
                   StandardCoverTree> coverTreeSearch(&referenceTree);
    
    arma::Mat<size_t> coverNeighbors;
    arma::mat coverDistances;
    coverTreeSearch.Search(dataset, k, coverNeighbors, coverDistances);

    return List::create(Named("neighbors") = coverNeighbors,
                        Named("distances") = coverDistances);
}
