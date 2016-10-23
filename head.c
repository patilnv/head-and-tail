#include <stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
	FILE *np;           
	int cnt = 1, p=0;   
	np = fopen(argv[1],"r");
	char c = fgetc(np);
	int size=ftell(np);
	int n = atoi(argv[2]);
	if( np == NULL ){
		printf("\n%sfile can not be opened!\n",argv[1]);
		return 1;   
	}
 			
	while(c !=EOF){
		printf("%c",c);
		if ( c=='\n'){
			if(p == n){
				break;
			}
			p++;
				
		} 
		
	}
	fclose(np);
	return 0;
}

