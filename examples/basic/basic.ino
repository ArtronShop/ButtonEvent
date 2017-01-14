#include <ButtonEvent.h>

/* Codeing By IOXhop : www.ioxhop.com
 * Sonthaya Nongnuch : www.fb.me/maxthai 
 */

/* ButtonEvent(int pin, pull_type p)
 *  -> (int) pin - set pin connect to Button switch
 *  -> (pull_type) p - can use PULL_DOWN , PULL_UP or INTERNAL_PULL_UP 
 */

ButtonEvent sw1(8, sw1.PULL_DOWN);

void setup() {
  Serial.begin(9600);
  Serial.println("Start.");

  sw1.on(sw1.UP, []() {          // Button switch not enter.
    Serial.println("Event: Up !");
  });

  sw1.on(sw1.DOWN, []() {       // Button switch enter.
    Serial.println("Event: Down !");
  });

  sw1.on(sw1.CLICK, []() {      // Button switch down and up in >50mS and <2000mS.
    Serial.println("Event: Click !");
  });

  sw1.on(sw1.LONG_CLICK, []() { // Button switch down and up >2000mS.
    Serial.println("Event: Long Click !");
  });
}

void loop() {
  sw1.loop();
}
