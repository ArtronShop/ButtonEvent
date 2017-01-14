#include "Arduino.h"

/*
  Codeing By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : www.fb.me/maxthai
*/

class ButtonEvent {
	protected:
		int _pin = 2;
		bool _pull = 0; // 0 is pull-down , 1 is pull-up
		int _lastStatus = 0;
		void (*_event_UP)(void) = []() { /* Empty */ };
		void (*_event_DOWN)(void) = []() { /* Empty */ };
		void (*_event_CLICK)(void) = []() { /* Empty */ };
		void (*_event_LONG_CLICK)(void) = []() { /* Empty */ };
		unsigned long _startDown = 0;

	public:
		enum {
			PULL_DOWN,
			PULL_UP,
			INTERNAL_PULL_UP
		} typedef pull_type;
    
		enum {
			UP,
			DOWN,
			CLICK,
			LONG_CLICK
		} typedef event;
    
		ButtonEvent(int pin, pull_type p) ;
		void on(event e, void (*fn)(void)) ;
		void loop() ;

}
;
