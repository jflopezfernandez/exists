/**
 * exists 0.1.1 GNU/Linux command-line utility
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "exists.h"

/* TODO: Make sure an argument was passed in */
/* TODO: Display usage if no argument */
/* TODO: Parse options */
/* TODO: Display help information */
/* TODO: Display version information */
/* TODO: Check whether file exists */
/* TODO: Accept bash file options to modify test argument */

int main(int argc, char *argv[])
{
    /**
     * Make sure the user supplied an argument.
     *
     * @todo Add checks for command-line options.
     */
    if (argc == 1) {
        fprintf(stderr, "Usage: exists <filename>\n");
        return EXIT_FAILURE;
    }

    /* Clear the error flag before invoking the kernel function */
    errno = 0;

    int status = access(argv[argc-1], F_OK);

    /**
     * If 'access' returns -1, something went wrong with the request, with the
     * most common explanation being that the file does not exists.
     *
     * @todo Add checks for all return codes.
     */
    if (status == -1) {
        switch (errno) {
            case ENOENT: {
                return EXIT_FAILURE;
            } break;
        }
    }

    return EXIT_SUCCESS;
}
