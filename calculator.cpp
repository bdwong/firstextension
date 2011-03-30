//calculator.cpp
#include <string.h>
#include "calculator.h"

//private:
//  char m_szName[100];

  Calculator::Calculator()
  {
    memset(m_szName, 0, sizeof(m_szName));
  }
  
  Calculator::~Calculator()
  {
  }
  
  //Members
  char* Calculator::GetName()
  {
    return m_szName;
  }
  
  void Calculator::SetName(char *szNewName)
  {
    strncpy(m_szName, szNewName, sizeof(m_szName)-1);
    m_szName[sizeof(m_szName)-1]='\0';
  }
  
  double Calculator::Add(double first, double second)
  {
    return first + second;
  }
  
  double Calculator::Multiply(double first, double second)
  {
    return first * second;
  }
  
  double Calculator::Divide(double dividend, double divisor)
  {
    return dividend / divisor;
  }
  
  double Calculator::Subtract(double minuend, double subtrahend)
  {
  	return minuend - subtrahend;
  }
  