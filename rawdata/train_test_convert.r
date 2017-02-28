#!/usr/bin/r

files <- c("testRes.csv", "testSet.csv", "trainRes.csv", "trainSet.csv")

for (f in files) {
    n <- gsub("\\.csv$", "", f)
    d <- as.matrix(read.csv(f, header=FALSE))
    rownames(d) <- colnames(d) <- NULL
    assign(n, d)
    print(d)
}
print(ls())
save(testRes, testSet, trainRes, trainSet, file="../data/trainSet.RData")
