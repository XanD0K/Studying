#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>  // ctime()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) != 0) {
        fprintf(stderr, "Error in stat for '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    // Checks type
    if (S_ISDIR(st.st_mode)) {
        printf("'%s' é um diretório.\n", argv[1]);
    } else if (S_ISREG(st.st_mode)) {
        printf("'%s' é um arquivo regular.\n", argv[1]);
    } else {
        printf("'%s' é outro tipo (ex.: link).\n", argv[1]);
    }

    // Prints metadata
    printf("Tamanho: %ld bytes\n", (long)st.st_size);
    printf("Inode: %lu\n", (unsigned long)st.st_ino);
    printf("Permissões: %o (octal)\n", st.st_mode & 0777);  // Mask for perms
    printf("Última modificação: %s", ctime(&st.st_mtime));  // Converts time_t to string
    // E.g.: Changes permissions (carefull! Requires permission!)
    if (chmod(argv[1], 0644) == 0) {  // rw-r--r--
        printf("Permissions changed to 0644.\n");
    } else {
        fprintf(stderr, "Erro in chmod: %s\n", strerror(errno));
    }

    // E.g. Creates directory
    if (mkdir("new_dir", 0755) == 0) {  // rwxr-xr-x
        printf("Created 'new_dir' directory.\n");
    } else {
        fprintf(stderr, "Error in mkdir: %s\n", strerror(errno));
    }

    return 0;
}