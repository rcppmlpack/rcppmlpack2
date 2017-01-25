## RcppMLPACK2 [![Build Status](https://travis-ci.org/eddelbuettel/rcppmlpack2.svg)](https://travis-ci.org/eddelbuettel/rcppmlpack2) [![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html) 


Rcpp bindings for MLPACK 2.*

### Experimental

This is a more experimental version derived off [Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7)'s
excellent [RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package which is also on CRAN as
[RcppMLPACK](https://cran.r-project.org/package=RcppMLPACK).  That version is based on MLPACK 1.0.6
and embeds it, ensuring builds on all platforms CRAN cares about.

Here, we are trying to build something lighter-weight and more current. We will use _external_ (system) libraries for
[MLPACK](http://www.mlpack.org/) instead of bundling them inside the R package. See below for more detailed installation notes.

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

As mentioned above, the official [RcppMLPACK CRAN apckage](https://cran.r-project.org/package=RcppMLPACK)
with its [GitHub repo](https://github.com/thirdwing/RcppMLPACK)  includes the
source code from the MLPACK library (version 1.*). Thus users do not need to install
MLPACK itself in order to use RcppMLPACK.

This package, however, uses the external [MLPACK](http://www.mlpack.org/) library (version
2.* or later), so below for detailed instructions.

#### Debian

Thanks to Barak Pearlmutter, there is an excellent [Debian package](https://packages.debian.org/source/sid/mlpack)
and its versions 2.1.0 or later will do nicely. Just do `sudo apt-get install libmlpack-dev` (provided you point to Debian 
_sid_ (aka 'unstable') or _stretch_ (aka 'testing') as these packages are not yet in a stable Debian release).

#### Ubuntu

Inofficial packages for trusty (14.04) and xenial (16.04)
[are available in my PPA](https://launchpad.net/~edd/+archive/ubuntu/misc/+packages), and used by the
[Travis CI integration](https://github.com/eddelbuettel/rcppmlpack2/blob/master/.travis.yml).  They are based
on Barak's Debian packages.  Via the standard Debian-to-Ubuntu package transition, these should also appear in 
Ubuntu 17.04 and later.

#### OS X / Brew

James Balamuta has kindly prepared a 
[pull request which has been submitted and merged](https://github.com/Homebrew/homebrew-science/pull/4637) to
update the version of MLPACK in brew.  However, I hear that there are issue between the brew compiler stack 
and what is used for R.  So this may be in flux.


#### Others

You may have to install from source.  Let me know how it goes.

#### Important one-line patch

The `R CMD check` command may complain about `std::cout` when using mlpack 2.1.0. Use
[this one-line change](https://github.com/eddelbuettel/mlpack/commit/6dd600825395e1bdb0455ad836daefc49b5ca66f) which
is also part of the  MLPACK 2.1.1 release.

### Authors

[Qiang Kou](https://www.linkedin.com/pub/qiang-kou/2a/986/6b7) for the main
[RcppMLPACK](https://github.com/thirdwing/RcppMLPACK) package.

[James Balamuta](http://thecoatlessprofessor.com/) for various builds tricks and tests, in particular on OS X.

Dirk Eddelbuettel for most of the remainder of this experiment.

### License

GPL (>= 2)

