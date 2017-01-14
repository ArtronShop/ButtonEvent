#include "ButtonEvent.h"

/*
  Codeing By IOXhop : www.ioxhop.com
  Sonthaya Nongnuch : www.fb.me/maxthai
*/

ButtonEvent::ButtonEvent(int pin, pull_type p) {
	_pin = pin;
	_pull = (p == INTERNAL_PULL_UP || p == PULL_UP ? 1 : 0);
	_lastStatus = (_pull == 0 ? 0 : 1);
	pinMode(pin, (p == INTERNAL_PULL_UP ? INPUT_PULLUP : INPUT));
}

void ButtonEvent::on(event e, void (*fn)(void)) {
	switch (e) {
		case UP:
			_event_UP = fn;
			break;
		case DOWN:
			_event_DOWN = fn;
			break;
		case CLICK:
			_event_CLICK = fn;
			break;
		case LONG_CLICK:
			_event_LONG_CLICK = fn;
			break;
	}
}

void ButtonEvent::loop() {
	int Status = digitalRead(_pin);
	if (Status == (_pull == 0 ? 1 : 0) && _lastStatus == (_pull == 0 ? 0 : 1)) {
		_startDown = millis();
		_event_DOWN();
	} else if (Status == (_pull == 0 ? 0 : 1) && _lastStatus == (_pull == 0 ? 1 : 0)) {
		_event_UP();
		if (millis() - _startDown > 2000) _event_LONG_CLICK();
		else if (millis() - _startDown > 50) _event_CLICK();
	}
	_lastStatus = Status;
}