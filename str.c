#include <stdio.h>
#include <string.h>
#include "mylib.h"

#define TXT 1024
#define WORD 30

//scan word until you get a blank char
void scanWord(char str[WORD]) {
    char c;
    int i = 0;

    while (c != '\t' && c != '\n' && c != ' ') {
        scanf("%c", &c);
        str[i] = c;
        i++;
    }
    str[i-1] = '\0';
}

//scan txt until you get the char  ~
void scanTxt(char str[TXT]) {

    char c;
    int i = 0;

    while (c != '~') {
        scanf("%c", &c);
        str[i] = c;
        i++;
    }
    str[i-1] = '\0';
}

int charInGematria(char c) {

    if (c >= 97 && c <= 122) {

        return c - 97 + 1;
    } else if (c >= 65 && c <= 90) {
        return c - 65 + 1;
    }
    return 0;
}


//copy  string from b[from] to  a[to]
void copy(int from, int to, char a[], char b[]) {
    int i = 0;
    while (from <= to) {

        a[i] = b[from];
        from++;
        i++;
    }


}

char aToZ(char c) {
    int ascii = c;

    char pos;
    if (c >= 'a' && c <= 'z') {
        pos = ascii - 'a';
        pos = 25 - pos;
        ascii = pos + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        pos = ascii - 'A';
        pos = 25 - pos;
        ascii = pos + 'A';
    }

    return ascii;
}

void swap(char *i, char *j) {
    char temp = *i;
    *i = *j;
    *j = temp;
}

void reversWord(char *str, int len) {

    for (int i = 0; i < len / 2; i++) {
        swap(&str[i], &str[len - 1 - i]);
    }
}

void Atbash_Sequences(char a[]) {
    int i = 0;

    while (a[i] != '\0') {

        a[i] = aToZ(a[i]);
        i++;
    }


}

int Anagram_Sequences(char word[], char temp[]) {

    int a[53] = {0};
    int b[53] = {0};


    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == 32) {
            a[26]++;
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            a[word[i] - 'a']++;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            a[word[i] - 'A' + 27]++;

        }
        i++;
    }
    i = 0;

    while (temp[i] != '\0') {
        if (temp[i] == 32) {
            b[26]++;
        } else if (temp[i] >= 'a' && temp[i] <= 'z') {
            b[temp[i] - 'a']++;
        } else if (temp[i] >= 'A' && temp[i] <= 'Z') {
            b[temp[i] - 'A' + 27]++;
        }
        i++;
    }

    for (i = 0; i < 53; i++) {

        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}


int minmal(char c) {

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;

}

int compre(char a[], char b[]) {

    int i = 0;
    int ans = 1;
    while (a[i] != '\0' && b[i] != '\0') {

        if (a[i] != b[i]) {

            ans = 0;
            break;
        }
        i++;
    }
    return ans;
}


//----------------------------q1-----------------------------------------
void func1(char word[], char txt[]) {

    int i = 0;
    char array[TXT];
    strcpy(array, txt);
    int k = 0;


    int sum = 0;
    while (word[i] != '\0') {
        sum += charInGematria(word[i]);
        i++;
    }


    i = 0;
    int c = 0;
    char str[TXT] = "";
    int sumTxt = 0;

    int from = 0;
    while (array[i] != '\0') {
        char temp[TXT] = "";

        copy(from, i, temp, array);


        while (temp[k] != '\0') {
            sumTxt += charInGematria(temp[k]);
            k++;
        }
        k = 0;

        if (sum > sumTxt) {
            i++;
            sumTxt = 0;
        } else if (sum < sumTxt) {
            sumTxt = 0;
            from++;
        } else {

            int j = 0;
            if (minmal(temp[j])) {
                while (temp[j] != '\0') {
                    str[c] = temp[j];
                    c++;
                    j++;
                }
                int lastIndex = strlen(str);
                str[lastIndex] = '~';
                c++;
                from++;
                i++;
                sumTxt = 0;
            } else {
                sumTxt = 0;
                from++;
            }
        }
    }

    int lastIndex = strlen(str) - 1;
    str[lastIndex] = '\0';
    printf("Gematria Sequences: %s\n", str);
}

//-----------------------------------q2------------------------------------------------
void func2(char word[], char txt[]) {

    char array[TXT];
    strcpy(array, txt);


    char atbashRegular[TXT];
    strcpy(atbashRegular, word);
    Atbash_Sequences(atbashRegular);


    char atbashReverse[TXT];
    strcpy(atbashReverse, word);
    reversWord(atbashReverse, strlen(atbashReverse));
    Atbash_Sequences(atbashReverse);

    char str[TXT] = "";


    int size = strlen(atbashReverse);

    int i = size;
    int from = 0;
    int k = 0;

    while (array[i] != '\0') {

        char temp[TXT] = "";

        copy(from, i - 1, temp, array);


        if (compre(temp, atbashReverse) == 1) {
            int j = 0;
            while (temp[j] != '\0') {
                str[k] = temp[j];
                k++;
                j++;
            }
            str[k] = '~';
            k++;
            from++;
            i++;
        } else if (compre(temp, atbashRegular) == 1) {
            int j = 0;
            while (temp[j] != '\0') {
                str[k] = temp[j];
                k++;
                j++;
            }
            str[k] = '~';
            k++;
            from++;
            i++;
        } else {
            from++;
            i++;
        }


    }


    str[strlen(str) - 1] = '\0';
    printf("Atbash Sequences: %s\n", str);
}


//-----------------------------------q3--S----------------------------------------------
void func3(char word[], char txt[]) {

    int i = 0;
    int k = 0;
    char removeArr[TXT];
    strcpy(removeArr, txt);


    char str[TXT] = "";


    int size = strlen(word);


    while (removeArr[i] != '\0') {

        char tempArr[TXT] = "";


        copy(i, size - 1, tempArr, removeArr);

        if (Anagram_Sequences(tempArr, word)) {
            int j = 0;
            while (tempArr[j] != '\0') {
                str[k] = tempArr[j];
                j++;
                k++;
            }
            int lastIndex = strlen(str);
            str[lastIndex] = '~';
            k++;
        }


        i++;
        size++;
    }


    int lastIndex = strlen(str) - 1;
    str[lastIndex] = '\0';
    printf("Anagram Sequences: %s", str);
}

//int main() {
//    char word[WORD] ;
//    char txt[TXT] ;
//    scanWord(word);
//    char cpyWord[WORD];
//    strcpy(cpyWord,word);
//    scanTxt(txt);
//    char cpyTxt[TXT];
//    strcpy(cpyTxt,txt);
//    func1(word, txt);
//    func2(word, txt);
//    func3(cpyWord, txt);
//    return  0;
//}