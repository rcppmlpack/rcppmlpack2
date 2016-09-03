// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include <RcppMLPACK.h>

#include <mlpack/methods/neighbor_search/neighbor_search.hpp>
#include <mlpack/core/tree/cover_tree.hpp>

using namespace Rcpp;
using namespace mlpack;
using namespace mlpack::neighbor;
using namespace mlpack::metric;
using namespace mlpack::tree;

// [[Rcpp::export]]
List coverTreeNeighboir(const arma::mat& dataset, const int k) {
    // using a test from MLPACK 2.0.* in file src/mlpack/tests/kfn_test.cpp

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
