#ifndef WWWD_ARENA_HEADER
#define WWWD_ARENA_HEADER

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
