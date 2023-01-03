#include "finder.h"
#include <stdio.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30

int main()
{
    char* str = (char*)malloc(WORD * sizeof(char));
    int len = getword(str);
    str = (char*)realloc(str, len * sizeof(char));
    char command = getc(stdin);

    getc(stdin);
    getc(stdin);

    if(command == 'a')
        print_lines(str);
    else if(command == 'b')
        print_similar_words(str);

    free(str);
    return 0;
}
