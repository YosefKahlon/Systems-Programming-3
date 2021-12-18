#include <stdio.h>
#include <string.h>
#include"mylib.h"
#define TXT 1024
#define WORD 30

int main() {
    char word[WORD] ;//= "sea";
     char txt[TXT] ;//= "A sailor went to sea, sea, sea\n"
    //                 "To see what he could see, see, see\n"
    //                 "But all that he could see, see, see\n"
    //                 "Was the bottom of the deep blue sea, sea, sea!~~";


    //scanWord(word);
    //printf("is work  %s", word);
    // scanTxt(txt);
    //  printf("is work  %s", txt);

    func1(word, txt);
    func2(word,txt);
    func3(word,txt);


}
