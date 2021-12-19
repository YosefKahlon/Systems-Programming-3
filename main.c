#include <stdio.h>
#include <string.h>
#include "mylib.h"
#define TXT 1024
#define WORD 30

int main() {
    char word[WORD] ;
    char txt[TXT] ;
    scanWord(word);
    char cpyWord[WORD];
    strcpy(cpyWord,word);
    scanTxt(txt);
    char cpyTxt[TXT];
    strcpy(cpyTxt,txt);
    func1(word, txt);
    func2(word, txt);
    func3(cpyWord, txt);
    return  0;
}
