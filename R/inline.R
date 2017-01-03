inlineCxxPlugin <- Rcpp:::Rcpp.plugin.maker(
               include.before = "#include <RcppMLPACK.h>",
               libs           = sprintf("%s $(LAPACK_LIBS) $(BLAS_LIBS) $(FLIBS)",
                                        "-lrt -larmadillo -lboost_program_options -lboost_unit_test_framework -lboost_serialization -lmlpack"),
               LinkingTo      = c("RcppArmadillo", "Rcpp", "BH", "RcppMLPACK"),
               package        = "RcppMLPACK"
           )
