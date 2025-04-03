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

void
_exit(int status)
{
  asm volatile ("syscall" :: "r" (60), "D" (status) : "rcx", "r11", "memory");
}
