# SDB-Creator

## General
### About
This is a project made by (or partially by) WSN-Team 2012 in the course CSD, which is part of the [Technology Transfer Alliance](http://ttaportal.org/).

### Purpose
To offer an uplink for wireless sensors in remote areas cut off from the Internet, a good way is to use the white space of radio band and transmit data over radio at an available frequency. A spectrum database (SDB) will be used to restore pairs of timeslot and frequency for the gateway at a specific geolocation to work accordingly.
To facilitate creating SDB with wanted values, this project has been created.

### Description
SDB-Creator is such a program that uses sqlite3 C API and gets values from two configure files to create a specific database.

## Build & Install
### Prerequisites
Install sqlite3 and its library:

1.  `apt-get install sqlite3`
2.  `apt-get install sqlite3-dev`

### Buidling
Follow the below steps to build it.

1.  `git clone https://github.com/WSN-2012/SDB-Creator.git`
2.  `cd SDB-Creator`
3.  `make`

## Running & Testing
Follow the below strps to create a SDB

1.  `nano sql_create_db.txt` to define the parameters of the table to be built
2.  `nano pop_db.txt` to edit the values to be inserted into the table
3.  `./create_test_sdb sql_create_db.txt pop_db.txt` to create a sqlite3 file 

So far a file called sdb.sqlite3 has been created. In the same directory, execute command `sqlite3 sdb.sqlite3` to access the SDB:

1.   `>select * from KistaSDB_2012;`
  (This command will show all the values in this table)
2.  `>.quit`
  (To quit sqlite3, don't forget the dot in front)

## License
Copyright 2012 KTH

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
