#undef CPP17
#if __cplusplus >= 201703L
  #define CPP17
#endif

#ifdef CPP17
#define MAYBE_UNUSED [[maybe_unused]]
#else
#define MAYBE_UNUSED __attribute__((unused))
#endif
