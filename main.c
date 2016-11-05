/************************************************************************
*   Copyright (C) 2017  Nitesh Vishwas Patil niteshpatil4753@gmail.com
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
**************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "tail_test.h"
#include "head_test.h"
int main(int argc, char *argv[]) {
	
	if(strcmp(argv[1], "tail") == 0) {
		FILE *fp;           // File pointer stream
		char *filename;     // get the file name from argument line test
		int count = 0, n = 10;  // count to check number of lines, n to check 
		
		// Check argument line passing
		if(argc < 3) {
			printf("Please enter correct format for tail information");
			return -1;
		}
		if(argc == 3) {
			filename = argv[2];
			fp = fopen(filename, "r");	
			if(fp == NULL) {
				printf("File not found, check the error %d\n", errno);
	      			return -1;
			}
			tail(n,fp);
		}
		else {
                       
			if(strcmp(argv[2], "-v") == 0) {
				filename = argv[3];
				fp = fopen(filename,"r");	
				if(fp == NULL) {
					printf("File not found, check the error %d\n",errno);
	      				return -1;
				}
				printf("<===%s===>", filename);
				tail(n,fp);
			}
			if(strcmp(argv[2], "-q") == 0) {
				filename = argv[3];
				fp = fopen(filename,"r");
			
				if(fp == NULL) {
					printf("File not found, check the error %d\n", errno);
	      				return -1;
				}
				tail(n,fp);
			}
			if(strcmp(argv[2],"-n") == 0) {
				n = atoi(argv[3]);
				filename = argv[4];
				fp = fopen(filename, "r");
			
				if(fp == NULL) {
					printf("File not found, check the error %d\n", errno);
	      				return -1;
				}
			
				tail(abs(n),fp);
			}
			if(strcmp(argv[2],"-c") == 0) {
				n = atoi(argv[3]);	
				if(n > 0) {
					n = -n;
				
				}
				filename = argv[4];
				fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not found, check the error %d\n", errno);
	      				return -1;
				}
				count = n / 2;
				while(count < 0) {
					fseek(fp,count,SEEK_END);
					printf("%c",fgetc(fp));
					count++;
				}
			}	
		}
		fclose(fp);
	}//end of tail

	else if((strcmp(argv[1], "head") == 0)) {
		FILE *fp;           // File pointer stream
		char *filename;     // get the file name from argument line test
		int count = 0, n = 10;  // count to check number of lines, n to check 
		// Check argument line passing
		if(argc < 3) {
			printf("Please enter correct format for head information");
			return -1;
		}
		// If we have only 3 arguements 
		if(argc == 3) {
			filename = argv[2];
			fp = fopen(filename,"r");
			if(fp == NULL) {
				printf("File not found, check the error %d\n",errno);
	      			return -1;
			}
			head(n,fp);
		}
		else {
			// Verbose mode
			if(strcmp(argv[2], "-v")==0) {
				filename = argv[3];
				fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not found, check the error %d\n",errno);
	      				return -1;
				}
				printf("<===%s===>\n",filename);
				head(n,fp);
			}
			// Quiet mode
			if(strcmp(argv[2], "-q")==0) {
				filename = argv[3];
				fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not found, check the error %d\n",errno);
	      				return -1;
				}
				head(n,fp);
			}
			// Lines mode
			if(strcmp(argv[2], "-n")==0) {
				n = atoi(argv[3]);
				filename = argv[4];
				fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not found, check the error %d\n",errno);
	      				return -1;
				}
				if(n > 0) {
					head(n,fp);
				}
				else {
					tail1(abs(n),fp);
				}
			}
			// Byte mode
			if(strcmp(argv[2], "-c")==0) {
				n = atoi(argv[3]);
				filename = argv[4];
				fp = fopen(filename,"r");
				if(fp == NULL) {
					printf("File not found, check the error %d\n",errno);
	      				return -1;
				}
				if(n > 0) {
					while(count < n / 2) {
						fseek(fp, count, SEEK_SET);
						printf("%c", fgetc(fp));
						count++;
					}
					printf("\n");
				}
				else {
					count = n / 2;

					while(count < 0) {
						fseek(fp, count, SEEK_END);
						printf("%c",fgetc(fp));
						count++;
					}
					printf("\n");
				}
			}			
		}
		fclose(fp);
	}//end of else if 
	return 0;
}//end of main

