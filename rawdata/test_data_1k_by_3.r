#!/usr/bin/r

testData1kBy3 <- as.matrix(read.csv("test_data_3_1000.csv", header=FALSE))
rownames(testData1kBy3) <- colnames(testData1kBy3) <- NULL

save(testData1kBy3, file="../data/testData1kBy3.RData")
