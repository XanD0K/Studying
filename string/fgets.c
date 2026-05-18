#include <stdio.h>
#include <string.h>

char *get_string(const char *prompt)
{
    while (1)
    {
        printf("%s", prompt);
        fflush(stdout);

        char buffer[128];

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            return NULL;
        }

        char *p = strchr(buffer, '\n');
        if (p != NULL)
        {
            *p = '\0';
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (buffer[0] != '\0')
        {
            return strdup(buffer);
        }

        printf("Invalid input!\n");
    }
}