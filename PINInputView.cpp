#include "stdafx.h"
#include "PINInputView.h"
#include <cstdlib>
#include <iostream>


PINInputView::PINInputView(int* pin, const int pin_size)
{
	// array to place pin into
	char putItHere[5];

	// make the input and make sure to terminate it
	generateSingleInput("Please enter PIN", putItHere, pin_size);

	// terminate
	putItHere[4] = '\0';

	//  take the string and convert it to an int
	*pin = atoi(putItHere);
}
