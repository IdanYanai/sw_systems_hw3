#include "finder.h"
#include <stdio.h>
#define LINE 256
#define WORD 30

int main()
{
    char s[WORD];
    int len = getword(s);
    char str[len];
    for(int i=0;i<len;i++)
        str[i] = s[i];
    char command = getc(stdin);

    getc(stdin);
    getc(stdin);

    if(command == 'a')
        print_lines(str);
    else if(command == 'b')
        print_similar_words(str);

    return 0;
}
