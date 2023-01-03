#include "finder.h"
#include <stdio.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30

void print_lines(char* str) {
    int len;
    while(1) {
        char* line = (char*)malloc(LINE * sizeof(char));
        len = getlines(line);
        if(len == -1) {
            free(line);
            break;
        }
        line = (char*)realloc(line, len * sizeof(char));
        if(substring(line, str) == 1)
            for(int i=0;i<len;i++) 
                putc(line[i], stdout);
        free(line);
    }
}

void print_similar_words(char* str) {
    int len;
    while(1) {
        char* word = (char*)malloc(WORD * sizeof(WORD));
        len = getword(word);
        if(len == -1) {
            free(word);
            break;
        }
        word = (char*)realloc(word, len * sizeof(char));
        if(similar(str, word, 1) == 1) {
            for(int i=0;i<len-1;i++)
                putc(word[i], stdout);
            putc('\n', stdout);
        }
        free(word);
    }
}

int substring(char* str1, char* str2) {
    int index1 = 0, index2;
    int isIn = 0;
    int saver;
    while((str1[index1] != '\n') && (isIn != 1)) {
        index2 = 0;
        isIn = 1;
        saver = index1;
        while((str2[index2] != '\n') && (str2[index2] != '\t') && (str2[index2] != ' ') && (isIn != 0)) {
            if(str2[index2] != str1[index1])
                isIn = 0;
            index1++;
            index2++;
        }
        index1 = ++saver;
    }
    return isIn;
}

int similar(char* str1, char* str2, int n) {
    int index1 = 0, index2 = 0;
    int debt = 0;
    while((str2[index2] != '\n') && (str2[index2] != '\t') && (str2[index2] != ' ') && (debt <= n)) {
        if(str2[index2] != str1[index1])
            debt++;
        else
            index1++;
        index2++;
    }
    if((debt <= n) && ((str1[index1] == '\n') || (str1[index1] == '\t') || (str1[index1] == ' ')))
        return 1;
    return 0;
}

int getlines(char s[]) {
    int len = 0;
    s[len] = getc(stdin);
    while(s[len] != '\n') {
        if(s[len] == EOF)
            return -1;
        s[++len] = getc(stdin);
    }
    return (len+1);
}

int getword(char w[]) {
    int len = 0;
    w[len] = getc(stdin);
    while((w[len] != '\t') && (w[len] != '\n') && (w[len] != ' ')) {
        if(w[len] == EOF)
            return -1;
        w[++len] = getc(stdin);
    }
    return (len+1);
}