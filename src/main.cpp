#include <Arduino.h>

#include "../lib/DDR_board_lib/board_data/board_pins.hpp"
#include "../lib/DDR_board_lib/motor/motor.hpp"
#include "../lib/DDR_board_lib/gyro/gyro.hpp"
#include "../lib/DDR_connection_lib/udp/udp_tx.hpp"
#include "../lib/DDR_connection_lib/udp/udp_rx.hpp"


// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}