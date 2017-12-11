#pragma once
#include "InputView.h"

class PINInputView :
	public InputView
{
public:
	PINInputView(int * pin, int pin_size);
	~PINInputView();
};

