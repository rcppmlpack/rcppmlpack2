#!/bin/bash

MLPACK=${HOME}/git/mlpack
MLPACKDATA=${MLPACK}/src/mlpack/tests/data/
MLPACKBIN=${MLPACK}/build/bin/

r -e "X <- read.csv(\"${MLPACKDATA}/testSet.csv\", header=FALSE); "\
     "write.table(X[, -5], file=\"/tmp/testSet4col.csv\", col.names=FALSE, row.names=FALSE, sep=\",\", quote=FALSE)'"

${MLPACKBIN}/mlpack_logistic_regression --training_file ${MLPACKDATA}/trainSet.csv \
            --test_file /tmp/testSet4col.csv  \
            --output_file logisticOut.txt \
            --output_model logisticModel.txt \
            --output_probabilities_file logisticProbs.txt
