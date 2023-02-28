#include"DYPR01.h"
#include"Arduino.h"
#include"Wire.h"
int DYPR01::Search()      //Only return an address of one device  at a time.    
{
  
  byte error,address;
  for(address = 1; address < 127; address++) {
   
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      return address;       
    }
    else if (error == 4) { 
      return 0;    //0 means Unknown error
  }
}
}
uint16_t DYPR01::Distance(byte addr)
{
    this->Address = addr;
    static uint8_t  recv_buf[ 10 ] = { 0 };
    static uint16_t len = 0;    
    Wire.beginTransmission(addr);    //initialise the  distance sensor, ready for transmition
    Wire.write(byte(0x10)); 
    Wire.write(byte(0xB0));
    Wire.endTransmission();
    delay(40);
    Wire.beginTransmission(addr); 
    Wire.write(byte(0x02));
    Wire.endTransmission(0);//stop transmition with slave,but keep the connection active.    
    Wire.requestFrom(addr, 2);
    while(Wire.available()) 
      {
        recv_buf[len++] = Wire.read(); 
       
      }
   if ( len >= 2 )
    {
      len = 0;               
      uint16_t distance   = recv_buf[ 0 ] << 8 | recv_buf[ 1 ];//calculate the distance
      return distance;              
   }  
}
