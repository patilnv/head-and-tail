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
#ifndef __HEAD_TEST_H
#define __HEAD_TEST_H
#define n_bytes 4096
void tail1(int n_lines, FILE *fp);
void head(int n_lines, FILE *fp);
char *buffer;
#endif
