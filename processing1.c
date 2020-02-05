#Processing 1

import processing.serial.*;
import de.bezier.data.sql.*;
int strtoint;
int temp ;
int std;
float tmpfloat;
int stdfloat;
String myString = null ;
Serial myPort ; // The serial port
MySQL db ; // database

void setup () {
// List all the available serial ports
// Open the port you are using at the rate you want :
frameRate (1) ; // 1 frame per second
String server = "10.50.202.242" ; // database details
String user = "user08" ;
String pass = "user08" ;
String database = "user08" ;
db = new MySQL(this , server , database , user , pass) ;
myPort = new Serial ( this , "COM8" , 9600);
myPort.clear () ;
// Throw out the first reading , in case we started reading
// in the middle of a string from the sender .
myString = myPort.readStringUntil ( '\n' ) ;
myString = null;
}
void draw () {
while ( myPort.available () > 0) { // process the string
myString = myPort.readStringUntil ( '\n' ) ;
if ( myString != null ) { // if received string is non empty
String [] myStringListA = split (myString, 'C');
String [] myStringListTemp = split (myStringListA[0], ':');
String [] myStringListSTD = split ( myStringListA[1] , ':' ) ; // split the String into two substrings separated by ':'
tmpfloat = float (myStringListTemp[1]) ; // convert string to float
temp = int ( tmpfloat ) ; // convert float to int
stdfloat = 1;//float (myStringListSTD[1]) ; // convert string to float
println ( temp ) ;
println (tmpfloat);
println ( stdfloat ) ;

if ( db.connect () ) { // insert values into database
db.query ("INSERT INTO temperature ( did , date_column , time_column , temperature ) VALUES (%d ,CURRENT_DATE () , CURRENT_TIME (), %f)", stdfloat, tmpfloat ) ;
}
}
}
}
