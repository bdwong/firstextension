// Calculator demo class
//

class Calculator
{
public:
  Calculator();
  ~Calculator();
  
  //Members
  char* GetName();		// Not Unicode. Investigate string and wstring class.
  void SetName(char*);
  double Add(double first, double second);
  double Multiply(double first, double second);
  double Divide(double dividend, double divisor);
  double Subtract(double minuend, double subtrahend);
  
private:
  char m_szName[100];
};
