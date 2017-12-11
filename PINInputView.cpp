#include "stdafx.h"
#include "PINInputView.h"
#include <cstdlib>
#include <iostream>


PINInputView::PINInputView(int* pin, const int pin_size)
{
	char putItHere[5];

	generateSingleInput("Please enter PIN", putItHere, pin_size);
	putItHere[4] = '\0';
	*pin = atoi(putItHere);
}


PINInputView::~PINInputView()
{
}
