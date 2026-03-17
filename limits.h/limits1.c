#include <stdio.h>
#include <unistd.h>  // pathconf()
#include <limits.h>  // _PC_PATH_MAX

int main() {
    long max_path = pathconf("/", _PC_PATH_MAX);  // Checks root "/"
    if (max_path != -1) {
        printf("Max path size: %ld\n", max_path);
        // Dinamic allocation: char *path = malloc(max_path + 1);
    } else {
        printf("Limit not available; use a default value (e.g. 4096).\n");
    }
    return 0;
}