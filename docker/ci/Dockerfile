## Emacs, make this -*- mode: sh; -*-

FROM r-base:latest

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/rcppmlpack" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

RUN apt-get update \
        && apt-get install -y --no-install-recommends \
                libmlpack-dev \
                libarmadillo-dev \
                libboost-program-options-dev \
                libboost-serialization-dev \
                libboost-test-dev \
                r-cran-rcpp \
                r-cran-rcpparmadillo \
                r-cran-knitr \
                r-cran-rmarkdown \
        && mkdir ~/.R \
        && echo _R_CHECK_FORCE_SUGGESTS_=FALSE > ~/.R/check.Renviron

CMD ["bash"]
