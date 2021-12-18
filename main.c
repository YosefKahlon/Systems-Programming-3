#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
char lowerCase(char c)
{

    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}
void swap(char *i, char *j)
{
    char temp = *i;
    *i = *j;
    *j = temp;
}
char aToZ(char c)
{
    int ascii = c;

    char pos;
    if (c >= 97 && c <= 122)
    {
        pos = ascii - 97;
        pos = 25 - pos;
        ascii = pos + 97;
    }

    return ascii;
}
//----------q1------------------------------

char charInGematria(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 1;
    }
    return 0;
}

//----------q2------------------------------
//a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// z  y  x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a

void reversWord(char *str, int len)
{

    for (int i = 0; i < len / 2; i++)
    {
        swap(&str[i], &str[len - 1 - i]);
    }
}

void Atbash_Sequences(char str[], char word[])
{
    int i = 0, k = 0;

    int size = strlen(str);
    char ans[size];
    char revers[size];

    char sighn = 126; // ~

    // //from uper to lower
    while (str[i])
    {

        str[i] = lowerCase(str[i]);
        char r = str[i];
        //  printf("%c", r);
        i++;
    }

    i = 0;
    // accspet only number
    while (str[i])
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            ans[k] = str[i];
            k++;
            i++;
        }
        else
        {
            i++;
        }
    }

    i = 0;

    strcpy(revers, ans);
    reversWord(revers, size);

    // a convert to z , b convert to y ...
    while (ans[i])
    {
        char r = ans[i];
        ans[i] = aToZ(ans[i]);
        i++;
    }

    i = 0;

    char ans1[TXT] = "";

    while (ans[i] != '\0')
    {
        strncpy(ans1, ans, size);
        if (!strcmp(ans1, str) || !strcmp(ans1, word))
        {
            strcat(ans1, ans);
            ans1[size] = sighn;
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("%s", ans1);
}

int main()
{
    char text[TXT] = "a-bc, OAYdbca-zwxyzabzyxw0dcba~";
    char word[WORD] = "abcd";

    // printf("please enter  your word: ");
    // scanf("%s", word);
    // printf("please enetr your txt : ");
    // fgets(text, TXT, stdin);

    // char c = text[strlen(text) - 1];
    // printf("-->%c<--\n", c);
    Atbash_Sequences(text, word);

    return 0;
}
