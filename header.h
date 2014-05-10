/* Team Name: Team Binary
 * Team Members: Suketu Shah and JoaoPaulo Rodgrigues
 *
 * File - header.h 
 * Source code File - cs562.cpp
 * Generated Files - output.pgc & output.c
 * Descrption - This program using Embedded SQL reads in the input of Phi operator from a txt file and generates a .c file which contains the query
 				and generates a program in C which implements the evaluation of the algorithm.
 				The algorithm is utilizes a compact data structure known as mf_structure which roughly holds the data corresponding to the MF query. 
 *
 * Steps to run this program : 
 *  1. Log in to PostgreSQL server (ssh [username]@postgres.cs.stevens.edu).
 *  2. In the program (L48), modify [dbname], [username], [password] to
 *     yours ([dbname] is the same as your [username] by default).
 *  3. Preprocessor - $ ecpg -I /usr/include/postgresql esql.pgc
 *  4. Compile      - $ gcc -c -I /usr/include/postgresql/ esql.c
 *  5. Link         - $ gcc -L /usr/include/postgresql/ -lecpg -o esql esql.o
 *  6. Execute      - $ ./esql
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