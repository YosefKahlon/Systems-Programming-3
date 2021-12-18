#include <stdio.h>
#include <string.h>

char lowerCase(char c)
{

    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}

//----------q1------------------------------
void Gematria_Sequences()
{





    
}
//----------q2------------------------------
//a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// z  y  x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a
void Atbash_Sequences(char n[])
{

    int i = 0;
// from uper to lower 
    while (n[i]){
        n[i]=lowerCase(n[i]);
        i++;
    }
  
    
    






    char abc[26];
    char zxy[26];
    char i, j;
    int k = 0;

    for (i = 'a', j = 'z'; i <= 'z', j >= 'a'; i++, j--)
    {
        abc[k] = i;
        zxy[k] = j;
    }
}

//----------q3------------------------------
void Anagram_Sequences() {}