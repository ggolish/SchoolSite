#include <stdio.h>

int main() {
   int ch; int line = 1;
   while ((ch = fgetc(stdin)) != EOF) {
     // do something with ch;
     if (line % 3 == 1) printf("%c\n", ch);      
     if (ch == '\n') line++;
   }
   
   return 0;
}