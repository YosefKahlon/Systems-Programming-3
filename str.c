#include <stdio.h>
#include <string.h>

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
}

//scan txt until you get the char  ~
void scanTxt(char str[TXT]) {

    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != '~') {
        scanf("%c", &c);
        str[i] = c;
        i++;
    }
}

int charInGematria(char c) {

    if (c >= 97 && c <= 122) {

        return c - 97 + 1;
    } else if (c >= 65 && c <= 90) {
        return c - 65 + 1;
    }
    return 0;
}

void func1(char word[], char txt[]) {

    int i = 0;
    int sum = 0;
    int sumTXT = 0;
    char str[TXT] = "", *pt, *temp; // pointer to str
    pt = txt;
    int length = strlen(pt);
    // caculte the sum of word
    while (word[i] != '\0') {
        sum += charInGematria(word[i]);
        i++;
    }

    //check sum
    while (*pt != '\0' && i < length) {
        printf("pt %s \n", pt);
        char tempArr[TXT] = "";
        temp = tempArr;
        strncpy(tempArr, pt, i); // copy to tempArr from pt < i
        printf("%s\n ", tempArr);
        temp = tempArr;

        if (!charInGematria(tempArr[0])) // dont include char with gematria 0 ;
        {
            //  printf(" temp[] %c \n" , tempArr[0]);
            pt++;
        }

        while (*temp != '\0') {
            sumTXT += charInGematria(*temp);
            temp++;
        }

        //printf("sum %d\n", sumTXT);

        if (sum < sumTXT) {
            sumTXT = 0;
            temp = tempArr;
            //  printf("before %s \n", pt);
            pt++; // add more char
            // printf("after %s \n", pt);
        } else if (sum > sumTXT) {
            printf("temp %s\n ", temp);
            temp = tempArr;
            sumTXT = 0;
            i++;

            printf("temp arr %s\n ", tempArr);
        } else // sum = sumTXT
        {

            strcat(str, tempArr);
            int lastIndex = strlen(str);
            str[lastIndex] = 126; //~;
            sumTXT = 0;
            pt++;
            i = 0;
        }

        printf("______________________________________________________________________________\n");
    }

    int lastIndex = strlen(str);
    str[lastIndex - 1] = '\0';

    printf("Gematria Sequences: %s\n", str);
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

//copy  string from b[from] to  a[to]
void copy(int from, int to, char a[], char b[]) {
    int i = 0;
    while (from <= to) {

        a[i] = b[from];
        from++;
        i++;
    }


}


void func3(char word[], char txt[]) {


    int i = 0;
    int k = 0;
    char removeArr[TXT];

    int len = strlen(txt);
    strcpy(removeArr, txt);
    // remove all bad   char
//    while (txt[i] != '\') {
//        removeArr[k] = txt[i];
//        i++;
//        k++;
//
//    }


    printf("%s\n", removeArr);

    char str[TXT] = "";


    int size = strlen(word);

    i = 0;
    k = 0;


    while (removeArr[i] != '\0') {

        char tempArr[TXT] = "";
        printf("BEFORE %s\n", tempArr);


        copy(i, size - 1, tempArr, removeArr);
        printf("AFTER %s\n", tempArr);
        if (Anagram_Sequences(tempArr, word)) {
            int j = 0;
            while (tempArr[j] != '\0') {
                str[k] = tempArr[j];
                j++;
                k++;
            }
            int lastIndex = strlen(str);
            printf("---->%d\n", lastIndex);
            str[lastIndex] = '~';
            k++;
        }


        i++;
        size++;
    }


    int lastIndex = strlen(str) - 1;
    str[lastIndex] = '\0';
    printf("Anagram Sequences: %s\n", str);
}

int main() {
    char word[WORD];//= "head";
    char txt[TXT] ;//= "lkjdfkhead ASSDdklfjdhead AAh eadSS~";

    //scanWord(word);
    //printf("is work  %s", word);
   // scanTxt(txt);
    //  printf("is work  %s", txt);

    func3(word, txt);


}