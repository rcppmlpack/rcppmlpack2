#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP RcppMLPACK_coverTreeNeighbor(SEXP, SEXP);
extern SEXP RcppMLPACK_kMeans(SEXP, SEXP);
extern SEXP RcppMLPACK_LARS(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP RcppMLPACK_linearRegression(SEXP, SEXP, SEXP, SEXP);
extern SEXP RcppMLPACK_logisticRegression(SEXP, SEXP, SEXP);
extern SEXP RcppMLPACK_naiveBayesClassifier(SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"RcppMLPACK_coverTreeNeighbor",    (DL_FUNC) &RcppMLPACK_coverTreeNeighbor,    2},
    {"RcppMLPACK_kMeans",               (DL_FUNC) &RcppMLPACK_kMeans,               2},
    {"RcppMLPACK_LARS",                 (DL_FUNC) &RcppMLPACK_LARS,                 6},
    {"RcppMLPACK_linearRegression",     (DL_FUNC) &RcppMLPACK_linearRegression,     4},
    {"RcppMLPACK_logisticRegression",   (DL_FUNC) &RcppMLPACK_logisticRegression,   3},
    {"RcppMLPACK_naiveBayesClassifier", (DL_FUNC) &RcppMLPACK_naiveBayesClassifier, 4},
    {NULL, NULL, 0}
};

void R_init_RcppMLPACK(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
