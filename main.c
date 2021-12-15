#include <stdio.h>
#define TXT 1024
 #define WORD 30
// char lowerCase(char c)
// {

//     if (c >= 'A' && c <= 'Z')
//     {
//         return c - 'A' + 'a';
//     }
//     return c;
// }
// void swap(char i, char j)
// {
//     char temp = i;
//     i = j;
//     j = temp;
// }
// char aToZ(char c)
// {
//     int ascii = c;

//     char pos;
//     if (c >= 97 && c <= 122)
//     {
//         pos = ascii - 97;
//         pos = 25 - pos;
//         ascii = pos + 97;
//     }

//     return ascii;
// }
// //----------q1------------------------------
// // void Gematria_Sequences()
// // {
// // }
// //----------q2------------------------------
// //a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// // z  y  x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a
// void Atbash_Sequences(char n[])
// {
//     int i = 0;
//     // from uper to lower
//     while (n[i])
//     {
//         n[i] = lowerCase(n[i]);
//         i++;
//     }
//     int j = 0;
//     while ((n[j]))
//     {
//         char r = n[j];
//         n[j] = aToZ(n[j]);
//         printf("\nfrom %c -> %c \n ", r, n[j]);
//         j++;
//     }
// }

int main()
{
    char word[]="bee";
     char text[]="l’m bringing home my baby bumble beeWon’t my Mommy be so proud of me I’m bringing home my baby bumble bee – OUCH!! It stung me!!~";
    char c;
    char n1[] = "";
    int count = 0;
    int gimatri=0;
   // printf("%s",word);
    for(int char_word = 0; char_word < sizeof(word)-1; char_word++){
        //printf("%d\n", gimatri);
        gimatri=(((int)(word[char_word]))-96)+gimatri;
        //printf("%ls",&gimatri);
        
    }
   
   
   
        /* code */
    
    
    for (int i=0;i<((int)(sizeof(text)))-1;i++){
       
        if((((int)(text[i]))-96)==gimatri){
        printf("%c",text[i]);
        printf("~");
        
        }
        if((((int)(text[i]))-96)>gimatri){
            i=i+1;
            
           
        }
        if((( (int) (text[i]) )-96) < gimatri){
            int start=i;
            int end=start;
            int sum=0;
            if(i>=(int)(sizeof(text))){
                break;
            }
            for ( int size_temp = i; sum < gimatri ||size_temp<((int)(sizeof(text)))-1 ; size_temp++)
            {
                end=size_temp;
        
               // if(text[i]!=||text[i]!='\t'||text[i]!='\n'){
             sum=sum+((((int)(text[size_temp]))-96)) ;
              /* code */
              //  }
               if(sum==gimatri){
                   printf("%d",gimatri);
                   printf("%d\n",sum);
                   for (start ; start < end; start++)
                   {
                       printf("%c",text[start]);
                       /* code */
                   }
                   
                 
                   if(start==end){
                   printf("~");
                   }
                   //printf("%s",text[start]);
               }
               
            }
            
        }
            

    }

   

     return 0;

}


