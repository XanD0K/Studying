#include <stdio.h>
#include <limits.h>

int main() {
    // Checks if PATH_MAX is defined
    #ifdef PATH_MAX 
        printf("PATH_MAX no seu sistema: %d\n", PATH_MAX);
        // Safe buffer for a path name
        char caminho[PATH_MAX];
        // e.g. read current directory w/ getcwd()
        if (getcwd(caminho, PATH_MAX) != NULL) {
            printf("Diretório atual: %s\n", caminho);
        } else {
            perror("Erro ao obter caminho");
        }
    #else
        printf("PATH_MAX não está definido no seu sistema.\n");
    #endif
    return 0;
}