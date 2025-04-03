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

void __attribute__ ((noreturn))
_exit(int status)
{
#if defined(__x86_64__)
  asm volatile ("syscall" :: "a" (60), "D" (status) : "rcx", "r11", "memory");
#elif defined(__i386__)
  asm volatile ("int $0x80" :: "a" (1), "b" (status) : "memory");
#endif

  for (;;) {}
}
