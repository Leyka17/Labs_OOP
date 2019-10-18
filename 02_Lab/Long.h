#pragma once
#include<string.h>
class Long
{
private:
	char _valueInStr[21] = { '\0' };//20=max size unint 64b
	const char _MaxSize[21] = "18446744073709551615";
public:
	//exeptions
	class Not_64bit_value:std::exception
	{
	public:const char* _value;
		   Not_64bit_value(const char* value) : _value{ value } {}
	};

	class DivisionbyZero :std::exception {};

	class WrongModul{};
	
	class A_less_B :std::exception
	{
	public: const char* _value1;
			const char* _value2;
			A_less_B(const char* value1,const char* value2) :_value1{ value1}, _value2{ value2 } {}

	};


	//ctors
	Long();
	Long(const char* value);

	//copy  ctor
	Long(const Long &other);


	//Del ctor;
	~Long();

	//Getter  and setter
	char* GetValue();
	void SetValue(const char*value);

	//Functions
	bool CheckisDidgit(const char* value)const;
	bool CheckLen(const char*value) const;
	bool CheckBelong64Bit(const char *value)const;
	char* Reverse(char*value);
	Long& IntToStr(int value);
	

	//operators
	Long& operator=(const Long& other);
	Long& operator=(const char*otherValue);


	bool operator == ( const Long &value) const;
	bool operator == (const char*otherValue)const;
	bool operator!=( const Long& other)const;
	bool operator!=(const char*otherValue)const;


};


Long operator+(  Long leftOperand, Long rightOperand);

Long operator-( Long leftOperand, Long rightOperand);

Long operator/( Long leftOperand, Long rightOperand);

Long operator*(Long leftOperand, Long rightOperand);
Long operator%(Long leftOperand, Long rightOperand);


bool operator>(  Long& leftOperand,   Long&rightOperand);

bool operator<( Long& leftOperand,  Long&rightOperand);

bool operator>=( Long& leftOperand,  Long&rightOperand);

bool operator<=(Long& leftOperand,  Long&rightOperand);


std::ostream& operator << (std::ostream& stream,  Long toOutput);
std::istream& operator >> (std::istream& stream, Long& toInput);
