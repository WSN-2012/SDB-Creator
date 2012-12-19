/*
 * Copyright 2012 KTH
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
 * OF ANY KIND, either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
 */

/* Author: Andreas Torbiörnsson
The purpose of this program is to create a sqlite3 database for the SDB radio solution in the KTH CSD WSN project, fall 2012. It was mainly created to get familiar with the C API of SQLite and the code may not be that well structured.
The program is called with two parameters:
1. Text-file containing sql for creating a table in the database. All sql code must be on one line and can't contain more than 299 characters
2. Text-file containing sql insert statements to populate the database with data. One insert statement per line
The program creates a database called sdb.sqlite3 in the current folder based on the sql in the parameters.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>


void usage(){
	perror("\nERROR IN USAGE: Please enter files for db structure and db contents as parameters");
	exit(EXIT_FAILURE);
}

void create_table(char* tablefile, sqlite3* db){
	FILE* file;
	char line[300];
	sqlite3_stmt* stmt;
	file = fopen(tablefile,"rt");
	
	if(fgets(line, 300, file) == NULL){
		perror("SQL fildfe for table struct contains no lines\n");
		exit(EXIT_FAILURE);
	}
	fclose(file);

	int i = sqlite3_prepare_v2(db, line, -1, &stmt, NULL);
	if(i != SQLITE_OK){
		perror("Could not compile SQL statement\n");
		printf("\nError code: %d\n",i);
		sqlite3_finalize(stmt);
		exit(EXIT_FAILURE);
	}
	
	i = sqlite3_step(stmt);

	if(i != SQLITE_DONE){
		perror("SQL statement could not be executed without error");
		sqlite3_finalize(stmt);
		exit(EXIT_FAILURE);
	}

	sqlite3_finalize(stmt);
}	
	
void populate_db(char* contentfile, sqlite3* db){
	FILE* file;
	char line[300];
	sqlite3_stmt* stmt;
	file = fopen(contentfile,"rt");
	
	while(fgets(line, 300, file) != NULL){
		sqlite3_exec(db, line, NULL, NULL, NULL);
	}
	fclose(file);
}

	

int main(int argc, char** argv){
	sqlite3* db;
	int retval;
	
	if(argc != 3){
		usage();
	}
	
	retval = sqlite3_open("./sdb.sqlite3",&db);
	if(retval){
		perror("\nCould not connect to db... exiting\n");
		return -1;
	}
	
	
	create_table(argv[1], db);
	populate_db(argv[2], db);
	sqlite3_close(db);

}


