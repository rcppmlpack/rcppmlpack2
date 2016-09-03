## RcppMLPACK2 [![Build Status](https://travis-ci.org/eddelbuettel/rcppmlpack2.svg)](https://travis-ci.org/eddelbuettel/rcppmlpack2)

### Experimental

This is fork / experimental version derived off [Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7)'s excellent [RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package.

We are trying to build something lighter-weight here by using the _external_ system
libraries for [MLPACK](http://www.mlpack.org/) instead of bundling it.

### What is MLPACK?

[MLPACK](http://www.mlpack.org/) is a C++ machine learning library with emphasis on
scalability, speed, and ease-of-use. Its aim is to make machine learning possible for
novice users by means of a simple, consistent API, while simultaneously exploiting C++
language features to provide maximum performance and maximum flexibility for expert
users. MLPACK outperforms competing machine learning libraries by large margins; see the
[BigLearning workshop paper](http://www.mlpack.org/papers/mlpack2011.pdf) for details.

The algorithms implemented in MLPACK:

* Fast Hierarchical Clustering (Euclidean Minimum Spanning Trees)
* Gaussian Mixture Models (trained via EM)
* Hidden Markov Models (training, prediction, and classiﬁcation)
* Kernel Principal Components Analysis
* K-Means clustering
* LARS/Lasso Regression
* Least-squares Linear Regression
* Maximum Variance Unfolding (using LRSDP)
* Naive Bayes Classiﬁer
* Neighborhood Components Analysis (using LRSDP)
* RADICAL (Robust, Accurate, Direct ICA aLgorithm)
* Tree-based k-nearest-neighbors search and classiﬁer
* Tree-based range search

The official [RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package includes the
source code from the MLPACK library (version 1.*). Thus users do not need to install
MLPACK itself in order to use RcppMLPACK.

This package, however, uses the external [MLPACK](http://www.mlpack.org/) library (version
2.* or later), so see its documentation for installation.  Or on Debian/Ubuntu do `sudo
apt-get install libmlpack-dev`.

### Authors

[Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7) for the main
[RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package.

Dirk Eddelbuettel for this experiment.



