/*************************************************************************
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "tail_test.h"
void tail(int n_lines, FILE *fp);

void tail(int n_lines, FILE *fp)
{
	char **lineptr = calloc(sizeof(char*), n_lines);
    	int in = 0;
	size_t size= 0;
	char *line;
	int i;
	if(!lineptr)
	{
        	perror("calloc");
    	}
    	while(getline(&line, &size, fp) > 0)
	{
		in = (in + 1) % n_lines;
        	if(lineptr[in]) 
		{
            		free(lineptr[in]);
        	}
        	lineptr[in] = line;
        	line = NULL;
		size=0;
    	}
    	for (i = n_lines; i > 0; i--) 
	{
		in = (in + 1) % n_lines;
        	if(lineptr[in])
 		{
            		printf("%s", lineptr[in]);
            		free(lineptr[in]);
        	}	
    	}
    	free(lineptr);
}
