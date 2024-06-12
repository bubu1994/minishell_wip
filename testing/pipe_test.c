#include "minishell.h"

/*La fonction pipe() en C est utilisée pour créer un canal de communication
unidirectionnel entre deux processus. Ce canal permet à un processus d'écrire
des données que l'autre processus peut lire. 
pipe() --> crée [descripteur de lecture, descripteur d'écriture]
*/
int main(void)
{
    int     pipefd[2];
    pid_t   pid;
    int     status_pip;
    char    read_msg[100];
    char    write_msg[] = "Bonjour depuis le parent";

    status_pip = pipe(pipefd);
    if (status_pip == -1)
    {
        printf("Erreur pipe()\n");
        return (1);
    }
    pid = fork();
    if (pid == 0)//code du processus enfant
    {
        close(pipefd[1]);//fermer l'extrémité d'écriture dans l'enfant

        read(pipefd[0], read_msg, sizeof(read_msg));//Lire le message depuis le pipe
        printf("Message reçu par l'enfant : %s\n", read_msg);

        close(pipefd[0]);
    }
    else//processus parent
    {
        close(pipefd[0]); // Fermer l'extrémité de lecture dans le parent

        // Écrire le message dans le pipe
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]); // Fermer l'extrémité d'écriture

        // Attendre la fin de l'exécution de l'enfant
        wait(NULL);
    }
}