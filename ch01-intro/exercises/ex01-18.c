/*
 * =====================================================================================
 *
 *       Filename:  ex01-18.c
 *
 *    Description:  Remove trailing blanks and tabs from each line of input, and delete blank lines.
 *
 *        Version:  1.0
 *        Created:  9/2/2013 9:46:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#define MAXLINE 1000  /*  maximum input line size. */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line */
main()
{
    int len;                /*  current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 0)    /* there was a line */
            printf("%s", line);
    return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    /* get next char if it's not end of file or newline (check for overflow) */
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        if (c != '\t' && c != ' ') {
            s[i] = c;
        }
    /* If newline, copy it and bump iter */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

