%module calculator

%{
#include "calculator.h"
%}

// Rename the accessors to Ruby convention.
%rename("name") Calculator::GetName();
%rename("name=") Calculator::SetName(char*);
%include "calculator.h"
