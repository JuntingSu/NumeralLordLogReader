// test.c
 
#include <emscripten.h>  // EMSCRIPTEN_KEEPALIVE
 
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif
 
EXTERN_C EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
  return a + b;
}