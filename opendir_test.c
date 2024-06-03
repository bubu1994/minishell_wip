#include "minishell.h"

int main(void)

{
	const char *dirname = "./dossier";
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname); // Ouvrir le répertoire
    if (dir == NULL) {
        perror("opendir() erreur");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) // Lire et afficher les entrées du répertoire
	{
        printf("%s\n", entry->d_name);
    }
	rewinddir(dir); //repositionne le curseur de lecture au début du répertoire
	entry = readdir(dir);
    printf("%s\n", entry->d_name);
    closedir(dir); // Fermer le répertoire

	char *titi;

	titi = ttyname(0);
	printf("%s\n", titi);
	titi = ttyname(1);
	printf("%s\n", titi);
	titi = ttyname(2);
	printf("%s\n", titi);

    return 0;
}
