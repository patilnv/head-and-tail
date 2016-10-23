#include<stdio.h>
#include<string.h>
// creating stack of lines
struct stack
{
          char st[100];
};
int  main(int argc , char *argv[])
{

             // stucture initialisation    
              struct stack s[100];

              FILE *np;
              char line[100];
         
              int n,v=0, i=0;

              np = fopen(argv[1] , "r");
              
              // reading line by line and push to stack
              while(fscanf(np , "%[^\n]\n" , line)!=EOF)
              {
                             strcpy(s[i].st , line);
                             i++;
                             n=i;
               }

               // pop line by line
              
               for(i=n;i>0;i--)
               {
                        // last 10 lines  
                         if(v == 10)
                               break;
                         else
                               printf("%s\n" , s[i].st);
                         v++;
               }
}

