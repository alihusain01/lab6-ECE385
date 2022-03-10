// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{

	unsigned int sum = 0;

	volatile unsigned int *LED_PIO = (unsigned int*)0x70;
	volatile unsigned int *SWITCHES_PIO = (unsigned int*)0x60;
	volatile unsigned int *BUTTONS_PIO = (unsigned int*)0x50;

	while(1 != 2)
	{
		//*LED_PIO = 0x2;
		if(*BUTTONS_PIO == 0x2){ //b10 RESET INSTRUCTIONS
			sum = 0;
			*LED_PIO = 0x0;
		}else if(*BUTTONS_PIO == 0x1){ //b01 ACCUMULATE INSTRUCTIONS
			sum = sum + *SWITCHES_PIO;
			*LED_PIO = *SWITCHES_PIO;
			while(*BUTTONS_PIO == 0x1){
			}
		}

		*LED_PIO = sum;
	}

	return 1;
}
