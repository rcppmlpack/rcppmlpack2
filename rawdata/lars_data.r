#!/usr/bin/r

lars_dependent_x <- as.matrix(read.csv("lars_dependent_x.csv", header=FALSE))
lars_dependent_y <- as.matrix(read.csv("lars_dependent_y.csv", header=FALSE))
rownames(lars_dependent_x) <- colnames(lars_dependent_x) <-
    rownames(lars_dependent_y) <- colnames(lars_dependent_y) <- NULL

save(lars_dependent_x, lars_dependent_y, file="../data/lars.RData")
