/*
 * Example usage of the Q macros . "
 *
 * */
#include "q_macros.h"


int main()
{

	/* Creates a 64-bit fixed-point variable variable with 16 bits fot the integer part and 47 bits for the fractional part.
	 * Sets initial value to 12345.6f. */
	fix64_t vara = Q47(1245.6f);

	/* Creates a 32-bit fixed-point variable variable with 1 bit fot the integer part and 30 bits for the fractional part.
	 * Sets initial value to 1.2f. */
	fix32_t varb = Q30(1.2f);

	/* Creates a 16-bit fixed-point variable variable with 3 bits fot the integer part and 12 bits for the fractional part.
	* Sets initial value to 1.2f. */
	fix16_t varc = Q12(1.2f);

	/* Creates a 16-bit fixed-point variable variable with 0 bits fot the integer part and 7 bits for the fractional part.
		* Sets initial value to 0.1f. */
	fix8_t  vard = Q7(0.1f);

}
