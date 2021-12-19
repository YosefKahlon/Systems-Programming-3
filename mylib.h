#ifndef _mylib_h
# define _mylib_h
#define TXT 1024
#define WORD 30


void scanWord(char str[WORD]);

void scanTxt(char str[TXT]);

int charInGematria(char c);

void copy(int from, int to, char a[30], char b[30]);

char aToZ(char c);

void swap(char *i, char *j);

void reversWord(char *str, int len);

void Atbash_Sequences(char a[WORD]);

int Anagram_Sequences(char word[WORD], char temp[WORD]);

int minmal(char c);

int compre(char a[WORD], char b[WORD]);


void func1(char word[WORD], char txt[TXT]);

void func2(char word[WORD], char txt[TXT]);

void func3(char word[WORD], char txt[TXT]);

#endif