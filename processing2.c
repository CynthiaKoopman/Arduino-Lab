#Processing 2

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
int temperature;

void setup () {
// List all the available serial ports
// Open the port you are using at the rate you want :
frameRate (1) ; // 1 frame per second
String server = "10.50.202.242" ; // database details
String user = "user08" ;
String pass = "user08" ;
String database = "user08" ;
db = new MySQL(this , server , database , user , pass) ;
myPort = new Serial ( this , "COM14" , 9600);
myPort.clear () ;
// Throw out the first reading , in case we started reading
// in the middle of a string from the sender .
//myString = myPort . readStringUntil ( '\n' ) ;
myString = null;
}

 
void draw () {
if ( db.connect () ) { // get data from database
db.query ("SELECT temperature FROM temperature" ) ;
while ( db.next()) {
temperature = db.getInt("temperature" ) ; // get the ingeter value of thecolumn "temperature"
println (temperature) ;
myPort.write(temperature); // send data to the arduino
}
}
}
