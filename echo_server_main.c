#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tcp_server.h"

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s [-v] [-p port]\n", prog_name);
}

int main(int argc, char *argv[]) {
    int port = DEFAULT_PORT;
    int verbose = 0;

    for (int ix = 1; ix < argc; ix++) {
        if (strcmp(argv[ix], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[ix], "-p") == 0) {
            if (ix + 1 < argc) {
                port = atoi(argv[++ix]);
            } else {
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            print_usage(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    start_tcp_server(port, verbose);
    return 0;
}
