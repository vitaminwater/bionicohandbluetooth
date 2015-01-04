#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>


// the setup routine runs once when you press reset:
void setup() {    
  // Init. and start BLE library.
  ble_begin();
 
  // Enable serial debug
  Serial1.begin(115200);
 
}

char data_in;
// the loop routine runs over and over again forever:
void loop() {
  
  if ( ble_available() )
  {
    while ( ble_available() ) {
      Serial1.write(ble_read());
    }
  }
  
  if ( Serial1.available() )
  {
    
    while ( Serial1.available() )
    ble_write( Serial1.read() );
  }
  
  ble_do_events();
 
}
