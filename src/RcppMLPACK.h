#ifndef RcppMLPACK__RcppMLPACK__h
#define RcppMLPACK__RcppMLPACK__h

#if _WIN64
#ifndef ARMA_64BIT_WORD
#define ARMA_64BIT_WORD
#endif
#endif

#if defined(__MINGW32__)
#define ARMA_DONT_USE_CXX11
#endif

#endif
