add_library(
    libhello STATIC
    hello.cc
    hello.hh
)
SET_TARGET_PROPERTIES(libhello PROPERTIES PREFIX "")