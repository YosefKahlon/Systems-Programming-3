#include <stdio.h>
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
void swap(char i, char j)
{
    char temp = i;
    i = j;
    j = temp;
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
// void Gematria_Sequences()
// {
// }
//----------q2------------------------------
//a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// z  y  x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a
void Atbash_Sequences(char n[])
{
    int i = 0;
    // from uper to lower
    while (n[i])
    {
        n[i] = lowerCase(n[i]);
        i++;
    }
    int j = 0;
    while ((n[j]))
    {
        char r = n[j];
        n[j] = aToZ(n[j]);
        printf("\nfrom %c -> %c \n ", r, n[j]);
        j++;
    }
}

int main()
{

    char c;
    char n1[] = "aBR  STs";
    int count = 0;

    for (int i = 0; i < sizeof(n1); i++)
    {
        if (n1[i] != ' ' || n1[i] != '\t' || n1[i] != '\n')
        {
            count ++ ; 
        }
    }

    char n[count];
    int k = 0;
for (size_t i = 0; i < sizeof(n1) && count; i++)
{
    if (n1[i] == ' '  || n1[i] == '\t' || n1[i] == '\n')
    {
            continue;      
    }
    else{
        n[k] = n1[i];
        k++;
    }
    
}
    Atbash_Sequences(n);
    int i = 0;
    while (n[i])
    {
        printf("%c", n[i]);
        i++;
    }

    return 0;

}
int func(){
    return 1;
}
