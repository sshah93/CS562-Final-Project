/* Team Name: Team Binary Success
 * Team Members: Suketu Shah and JoaoPaulo Rodgriues
 *
 * File - header.h 
 * Source code File - cs562.cpp
 * Generated Files - output.pgc & output.c
 * Descrption - This program using Embedded SQL reads in the input of Phi operator from a txt file and generates a .c file which contains the query
 				and generates a program in C which implements the evaluation of the algorithm.
 				The algorithm utilizes a compact data structure known as mf_structure which roughly holds the data corresponding to the MF query. 
 *
 * Steps to run this program : 
 *  1. Log in to PostgreSQL server (ssh [username]@postgres.cs.stevens.edu).
 *  2. The program uses our default database "jrodrig9" at my credentials which are already input in cs562.cpp
 *	3. Run the Makefile by using the command "make"
 *	4. run the result program by using ./test (This creates the output.pgc file which can then be prepocessed as shown below:
 *  5. Preprocessor - $ ecpg -I /usr/include/postgresql output.pgc
 *  6. Compile      - $ gcc -c -I /usr/include/postgresql/ output.c
 *  7. Link         - $ gcc -L /usr/include/postgresql/ -lecpg -o output output.o
 *  8. Execute      - $ ./output
 */

#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <sstream>
#include <fstream>
#include <cstddef>
#include <postgresql/libpq-fe.h>

using namespace std;

#endif