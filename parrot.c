/*
 * Parrot shell.  This shell repeats every line you type in,
 * without executing them.
 * Copyright (C) 2017 Balabit, Peter Ferenc Hajdu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int noLogout(const char* buffer) {
  if (buffer == NULL) return 0;
  return strncmp(buffer, "logout", 6);
}

const char *getLogin() {
  const char *login = getenv("USER");
  return (login == NULL) ? "harcsabajusz" : login;
}

const char *getHost() {
  static char hostname[BUFFER_SIZE];
  if (gethostname(hostname, BUFFER_SIZE) < 0) {
    strncpy(hostname, "szaguldokacsa", BUFFER_SIZE);
  }
  return hostname;
}

int main() {
  const char* hostname = getHost();
  const char* login = getLogin();
  char line_buffer[BUFFER_SIZE] = {0};
  char *readReturn = line_buffer;

  while (noLogout(readReturn)) {
    printf("%s[%s@%s ~]# ", line_buffer, login, hostname);
    fflush(stdout);
    readReturn = fgets(line_buffer, BUFFER_SIZE, stdin);
  }

  return 0;
}
