#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

char *get_string(char *prompt)
{
    while (1)
    {
        printf("%s\n", prompt);
        fflush(stdout);

        char *buffer = NULL;
        size_t len = 0;

        ssize_t nread = getline(&buffer, &len, stdin);

        if (nread == -1)
        {
            free(buffer);
            return NULL;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0] != '\0')
        {
            return buffer;
        }

        free(buffer);
        printf("Invalid answer\n");
    }
}