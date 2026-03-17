#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>  // strcmp()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignores . e ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("Name: %s | Inode: %lu\n", entry->d_name, (unsigned long)entry->d_ino);
        // If d_type is available:
        // if (entry->d_type == DT_DIR) printf(" (Diretório)\n");
    }

    closedir(dir);
    return 0;
}