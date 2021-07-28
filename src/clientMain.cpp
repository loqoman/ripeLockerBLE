// Personal/Programming/Projects/ripeLockerBLE
// Darwin Clark
//   for RipeLocker LLC

// GOAL: Have this file be less than 100 lines

// [X] Scan for the other BLE feather and see it 
// [X] Send a custom message between the feathers
// --- Server --- 
#include <Arduino.h>
#include <bluefruit.h>
#include "clientLib.h"
#include "messageLib.h"

#define DEVICE "client"

BLEClientUart clientUart;

Message testMsg(millis());
void setup() {
	// Do nothing :)
	Serial.begin(115200);
	setupScanner();

	// The enum is really just a 
	testMsg.type = Message::messageType::KEEPALIVE;
	testMsg.payload = 2;

	Serial.println(testMsg.encodeToWire(millis()));
	String testDecode = testMsg.encodeToWire(millis());
	Message postWireMessage = Message::decodeFromWire(testDecode); 
	Serial.println(postWireMessage.encodeToWire(millis())); 
}



void loop() {
	// Do nothing :)
}

