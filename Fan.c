#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_PORT  PORTC
#define BUTTON_PIN   PINC
#define BUTTON_DDR   DDRC

#define LED_PORT     PORTB
#define LED_DDR      DDRB

#define DIS_PORT     PORTD
#define DIS_DDR      DDRD

#define BUTTON_1     PC0
#define BUTTON_2     PC1
#define BUTTON_3     PC2
#define BUTTON_4     PC3

#define LED_1        PB0
#define LED_2        PB1
#define LED_3        PB2

#define FAN_1        PB3


enum Mode {
	MODE_1,
	MODE_2,
	MODE_3,
	MODE_0
};

void init() {
	// wejscia
	BUTTON_DDR = 0;
	// pull-up
	BUTTON_PORT = 255;
	// wyjscia
	LED_DDR = 255;
	DIS_DDR = 255;
}

int main() {
	init();
	enum Mode mode = MODE_0;
	
	while (1) {
		// przyciski
		if (!(BUTTON_PIN & (1 << BUTTON_1))) {
			mode = MODE_1;
			} else if (!(BUTTON_PIN & (1 << BUTTON_2))) {
			mode = MODE_2;
			} else if (!(BUTTON_PIN & (1 << BUTTON_3))) {
			mode = MODE_3;
			} else if (!(BUTTON_PIN & (1 << BUTTON_4))) {
			mode = MODE_0;
		}
		// tryby
		switch (mode) {
			case MODE_1:
			DIS_PORT = 0xF9;
			LED_PORT |= (1 << LED_1);
			LED_PORT &= ~(1 << LED_2);
			LED_PORT &= ~(1 << LED_3);
			LED_PORT |= (1 << FAN_1);
			_delay_ms(100);
			LED_PORT &= ~(1 << FAN_1);
			_delay_ms(100);
			break;
			case MODE_2:
			DIS_PORT = 0xA4;
			LED_PORT &= ~(1 << LED_1);
			LED_PORT |= (1 << LED_2);
			LED_PORT &= ~(1 << LED_3);
			LED_PORT |= (1 << FAN_1);
			_delay_ms(10);
			LED_PORT &= ~(1 << FAN_1);
			_delay_ms(10);
			break;
			case MODE_3:
			DIS_PORT = 0xB0;
			LED_PORT &= ~(1 << LED_1);
			LED_PORT &= ~(1 << LED_2);
			LED_PORT |= (1 << LED_3);
			LED_PORT |= (1 << FAN_1);
			break;
			case MODE_0:
			DIS_PORT = 0xC0;
			LED_PORT &= ~(1 << LED_1);
			LED_PORT &= ~(1 << LED_2);
			LED_PORT &= ~(1 << LED_3);
			LED_PORT &= ~(1 << FAN_1);
			break;
			
		}
	}
	
	return 0;
}
