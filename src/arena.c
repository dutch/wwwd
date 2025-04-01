#include "arena.h"
#include <stdlib.h>
#include <stdint.h>

arena_t
mkarena(ptrdiff_t cap)
{
  arena_t a;

  a.beg = malloc(cap);
  a.end = a.beg ? a.beg + cap : 0;

  return a;
}

void *
alloc(arena_t *a, ptrdiff_t size, ptrdiff_t align, ptrdiff_t count)
{
  ptrdiff_t pad, avail;
  void *p;

  pad = -(uintptr_t)a->beg & (align - 1);
  avail = a->end - a->beg - pad;

  if (avail < 0 || count > avail / size)
    __builtin_longjmp(a->jmp_buf, 1);

  p = a->beg + pad;
  a->beg += pad + count * size;

  return p;
}
