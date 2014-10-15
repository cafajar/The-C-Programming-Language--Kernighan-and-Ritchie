#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int getline(char *line, int max);

/* find: print lines that match patttern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    return found;
}


/* read line into s, return length */
int getline(char *s, int lim)
{
    int c, i;
    char *s2 = s;

    while ((c=getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - s2;
}