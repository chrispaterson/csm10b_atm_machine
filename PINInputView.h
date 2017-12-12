#pragma once
#include "InputView.h"

class PINInputView :
	public InputView
{
public:

	// constructor takes PIN input
	PINInputView(int * pin, int pin_size);
};

