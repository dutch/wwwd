#ifndef WWWD_ARENA_HEADER
#define WWWD_ARENA_HEADER

#include <stddef.h>

typedef struct
{
  char *beg;
  char *end;
  void **jmp_buf;
} arena_t;

arena_t mkarena(ptrdiff_t);
void *alloc(arena_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t);

#define new(a,b,c) (b *)alloc(a, sizeof(b), _Alignof(b), c)

#endif
