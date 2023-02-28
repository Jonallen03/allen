#include<DYPR01.h>
#include<Wire.h>
DYPR01 DR;
byte addr;
void setup(){
  Serial1.begin(115200);
  Wire.begin();
  int address = DR.Search();     //retrive an address of a device
  addr = address;
  Serial1.print("The address of the device is 0x");
  if (address < 16){
    Serial1.print("0");}
  Serial1.println(address, HEX);   //show the address from UART.

}
void loop()
{
  uint16_t distance = 0;
  distance = DR.Distance(0x74);
  char  out_txt[ 32 ] = { 0 };           
  sprintf( out_txt,"distance : %d mm \r\n", distance );    
  Serial1.println( out_txt );//print final value from the second distance sensor    
  delay(800); 


}
