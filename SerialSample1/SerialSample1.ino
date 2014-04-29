/**
 * Arduino Serial Sample
 * Serial Echoback & LED Test
 */

#define P13 13
#define SPEED 115200

void setup()  {
	pinMode(P13, OUTPUT);  
	Serial.begin(SPEED);
}
 
void loop() {
	if ( Serial.available() ) {
		int c = Serial.read();
		// echo back
		Serial.write( c );
        if ( c == 0x30 ) {
			// LED off if "0"
			digitalWrite(P13, LOW); 
        } else if ( c == 0x31 ) {
			// LED on if "1"
			digitalWrite(P13, HIGH); 
        }
	}    
}
