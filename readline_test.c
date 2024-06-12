
#include "minishell.h"

int main() {

    int fd;

    // Ouvrir un fichier pour écrire
    fd = open("output.txt", O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Rediriger stdout vers le fichier
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        return 1;
    }

    // Fermer le descripteur de fichier original
    close(fd);

    // Maintenant, toute sortie sur stdout ira dans "output.txt"
    printf("Hello, world!\n");

    return 0;
}
