#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char sentence[100];
  printf("Enter a sentence \n > ");
  fgets(sentence,100,stdin);
  printf("%s\n",sentence);
  char *p = sentence;
  printf("Number of words: %d\n",count_words(p));
  
 done: //exit program
    return 0;
}
