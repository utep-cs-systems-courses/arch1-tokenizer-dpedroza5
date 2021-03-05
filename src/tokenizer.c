#ifndef _TOKENIZER_
#define _TOKENIZER_
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c==' ' || c=='\t');
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c!=' ' || c!='\t' || c!='\0');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  while(*str){ 
    if(non_space_char(*str)){ 
      return str; 
    } 
    str++; 
  } 
  return 0;
} 
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){ 
  while(*word){
    if(space_char(*word)){
	return word; 
    } 
    word++; 
  }
  return 0;
}

/* Counts the number of words in the string argument.*/
//number of words is determined by number of spaces
int count_words(char *str){
  int count=1;
  char i;
  while(*str){
    i = str[0];
    str++;
    if(space_char(i)){
      count++;
    }
  }
  return count;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *outStr = malloc(len + 1); //adds 1 to include the zero-terminator
  for (int i=0; i<len; i++){
    outStr[i] = *&inStr[i]; //copies the value at the address of inStr at position i to outStr
  }
  outStr[len] = '\0';
  return outStr;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int size = count_words(str);
  char **t = malloc((size+1) * sizeof(char*));
  char *temp;
  return t;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i=0;
  int j=0;
  while(tokens[i]!=NULL){ //check if there are no more words
    printf("Token [%d] = ",i);//prints token number
    while(tokens[i][j]!= '\0'){
      printf("%c\n",tokens[i][j]);//prints token value
    }
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  char *ptr = *tokens;
  while(ptr != NULL){
    free(ptr);
    ptr++;
  }
  free(ptr);
}

#endif
