/* This file is part of wwwd.
 *
 * wwwd is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * wwwd is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with wwwd. If not, see <https://www.gnu.org/licenses/>.
 */

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
