## RcppMLPACK2 [![Build Status](https://travis-ci.org/eddelbuettel/rcppmlpack2.svg)](https://travis-ci.org/eddelbuettel/rcppmlpack2)

### Experimental

This is fork / experimental version derived off [Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7)'s
excellent [RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package.

We are trying to build something lighter-weight here by using _external_ system libraries for
[MLPACK](http://www.mlpack.org/) instead of bundling these. See below for installation notes.

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

### Installation

The official [RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package includes the
source code from the MLPACK library (version 1.*). Thus users do not need to install
MLPACK itself in order to use RcppMLPACK.

This package, however, uses the external [MLPACK](http://www.mlpack.org/) library (version
2.* or later), so below for detailed instructions.

#### Debian

Thanks to Barak Pearlmutter, there is an excellent [Debian package](https://packages.debian.org/source/sid/mlpack)
and its version 2.1.0 will do nicely. Just do `sudo apt-get install libmlpack-dev` (provided you point to Debian _sid_
as these packages are not yet in testing).


#### Ubuntu

Package for trusty (14.04) and xenial (16.04) [are available](http://dirk.eddelbuettel.com/deb/), and used by the
[Travis CI integration](https://github.com/eddelbuettel/rcppmlpack2/blob/master/.travis.yml). (The reason these are
downloaded directly is am inability to build these packages on Launchpad. One day we may manage to not have `g++` die
for lack of resources at Launchpad. Docker on our workstation worked just fine.)

#### OS X / Brew

We do not use this platform so we do not know. There may be a solution as well. If you know, tell us and we update this
section.

#### Others

You may have to install from source. 

#### Important one-line patch

The `R CMD check` command may complain about `std::cout` when using mlpack 2.1.0. Use
[this one-line change](https://github.com/eddelbuettel/mlpack/commit/6dd600825395e1bdb0455ad836daefc49b5ca66f) which
will be part of the next mlpack release to correct this.

### Authors

[Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7) for the main
[RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package.

Dirk Eddelbuettel for this experiment.



