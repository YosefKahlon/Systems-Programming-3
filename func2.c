#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30



//copy  string from b[from] to  a[to]
void copy(int from, int to, char a[], char b[]) {
    int i = 0;
    while (from <= to) {

        a[i] = b[from];
        from++;
        i++;
    }
void func2(char word[], char txt[TXT]){

    char array[TXT];
    strcpy(array,txt);

    int i  = 0;
    char ans[txt];
    int size = strlen(word);


    while (array[i] != '\0'){
        char temp[size] = "";

        copy(i,size -1, temp, array);

        if ()




    }





}