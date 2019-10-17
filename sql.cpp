//
//  sql.cpp
//  Banque
//
//  Created by Nofel Syed on 17/10/2019.
//  Copyright © 2019 Nofel Syed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "/usr/local/mysql/include/mysql.h"

MYSQL mysql;    // MYSQL global
MYSQL * conn ;  // represents connection to database

int main()
{
  mysql_init( &mysql ) ;
  
  //   http://dev.mysql.com/doc/refman/5.0/en/mysql-real-connect.html
  conn = mysql_real_connect(  &mysql,
                              "localhost",// synonymous with 127.0.0.1
                              "root",     // connect as user="root".  Uh, bad security here..
                              "root",         // my root password is blank.  REALLY bad security :)
                              "mysql",    // connect to the 'mysql' _database_ within MySQL itself.
                               0, 0, 0 ) ;
  
  // Check if connection succeeded.
  if( !conn )
  {
    printf( "Couldn't connect to MySQL database server!\n" ) ;
    printf( "Error: %s\n", mysql_error( &mysql ) ) ;
    return 1 ;
  }
  //else  puts( "Connect success" ) ;
  
  // Here, we are connected.
  // form a sql string to execute.
  if( mysql_query( conn, "select * from user" ) )
  {
    printf("Whoops!  The query failed.  Error:  %s\n", mysql_error( conn ) );
    return 1 ;
  }

  // here, query succeeded, so we can proceed to pull out results.
  MYSQL_RES * resultset ;
  MYSQL_ROW row;  // MYSQL_ROW is #defined as (char **)
  // Data ALWAYS comes back from MySQL as
  // an array of strings.  To convert it
  // to ints or whatever is YOUR JOB as the programmer.

  // mysql_store_result basically fetches
  // the entire array of results and dumps them
  // into our local program memory space (all
  // in the resultset variable.
  resultset = mysql_store_result( conn );

  // How many rows will there be?
  my_ulonglong numRows = mysql_num_rows( resultset ) ;
  printf( "There are %llu ROWS (records) of data\n", numRows ) ;
  
  // Now tell me what columns there are
  // in the result set.
  int numFields = mysql_num_fields( resultset ) ;
  printf( "There are %d FIELDS (columns) of data\n", numFields ) ;

  // Print all those column by name
  MYSQL_FIELD * fields = mysql_fetch_fields( resultset ) ;
  for( int i = 0 ; i < numFields ; i++ )
  {
    printf( "%25s", fields[i].name ) ;
  }

  printf( "\n" ) ;
  // print all results
  while( (row = mysql_fetch_row( resultset )) )
  {
    // row is 2d array of char
    // underlying type is char **
    for ( int i = 0; i < numFields ; i++ )
      printf( "%5s", row[ i ] ) ;
    
    puts( "" ) ;    // next row
  }
  
  mysql_free_result( resultset );  // Now free the result
  mysql_close( conn ) ;  // And close down.
  return 0;
}
