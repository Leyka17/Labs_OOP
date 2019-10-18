#include<iostream>
#include<string.h>
#include"Long.h"

//ctors
Long::Long()
{
	_valueInStr[0] = '0';
}

Long::Long(const char* value)
{
	if (CheckBelong64Bit(value))
	{
		if (strlen(value) == 0)
			_valueInStr[0] = '0';
		for (size_t i = 0; i < strlen(value); ++i)
		{
			_valueInStr[i] = value[i];

		}

	}
	else
		throw Not_64bit_value(value);
		
}
Long::Long(const Long&other)
{
	for (size_t i = 0; i < strlen(other._valueInStr); ++i)
	{
		_valueInStr[i] = other._valueInStr[i];
	}

}

Long::~Long() {}

//Getter and Setter

char*Long::GetValue()
{
	return _valueInStr;
}

void Long::SetValue(const char*othervalue)
{
	if (CheckBelong64Bit(othervalue))
	{
		if (strlen(othervalue) == 0)
			_valueInStr[0] = '0';
		else
		{
			for (size_t i = 0; i < strlen(othervalue); ++i)
			{
				_valueInStr[i] = othervalue[i];
			}
			_valueInStr[strlen(othervalue)] = '\0';
			return;
		}
	}
	throw Not_64bit_value(othervalue);
	

}

//functions
bool Long::CheckisDidgit(const char* value)const
{
	for (int i = 0; i < strlen(value); ++i)
	{
		if (isalpha(value[i]))
		{
			return false;
		}
	}
	return true;
}
bool Long::CheckLen(const char*value) const
{
	if (strlen(value) > 20)
		return false;
	else
		return 	true;
}

bool Long::CheckBelong64Bit(const char*value)const
{
	if (CheckLen(value))
	{
		if(CheckisDidgit(value))
		{ 
		bool flag = true;
		if (strlen(value) == 20)
		{
			for (int i = 0; i < 20; ++i)
			{
				if (((value[i]) - '0') < (_MaxSize[i] - '0'))
				{
					break;
				}
				if (((value[i]) - '0') > (_MaxSize[i] - '0'))
				{
					flag = false;
					break;
				}

			}
		}
		return flag;
	}
		}
	return false;
}

char* Long::Reverse(char*value)
{
	int count = strlen(value) / 2;
	for (int i = 0; i <count; i++)
	{
		char tmp='\0';
		tmp = value[i];
		value[i] = value[strlen(value) - i-1];
		value[strlen(value) - i - 1] = tmp;
	}

	return value;
}

Long& Long::IntToStr(int value)
{
	Long Result;
	char Value[20]{ '\0' };
	int i = 0;
	while (value>0)
	{
		char c= static_cast<char>((value % 10));
		Value[i] = c;
		value /= 10;
	}
	Result.SetValue(Value);
	return Result;
}

//operators
Long& Long::operator=(const char*other)
{
	if (CheckBelong64Bit(other))
	{
		if (strlen(other) == 0)
		{
			_valueInStr[0] = '0';
			_valueInStr[1] = '\0';
		}
		else
		{
			for (size_t i = 0; i < strlen(other); ++i)
			{
				_valueInStr[i] = other[i];
			}

			_valueInStr[strlen(other)] = '\0';
		}
		return *this;
	}
	throw Not_64bit_value(other);
}

Long& Long::operator=(const Long&other)
{
	for (size_t i = 0; i < strlen(other._valueInStr); ++i)
	{
		_valueInStr[i] = other._valueInStr[i];
	}
	_valueInStr[strlen(other._valueInStr)] = '\0';
	return *this;
}



bool Long ::operator==(const char* othervalue)const
{
	if (CheckBelong64Bit(othervalue))
	{
		if (strlen(_valueInStr) == strlen(othervalue))
		{
			bool flag = true;
			for (size_t i = 0; i < strlen(othervalue); ++i)
			{
				if (_valueInStr[i] != othervalue[i])
				{
					flag = false;
					break;
				}
			}
			return flag;
		}
		return false;
	}
	throw Not_64bit_value(othervalue);
	return false;
}

bool Long::operator==( const Long&value)const
{
	if (strlen(_valueInStr) == strlen(value._valueInStr))
	{
		bool flag = true;
		for (size_t i = 0; i < strlen(_valueInStr); ++i)
		{
			if (_valueInStr[i] != value._valueInStr[i])
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	return false;
}


bool Long ::operator!=(const char* othervalue)const
{
	return !(_valueInStr == othervalue);
}

bool Long::operator!=(const  Long&value)const
{
	return !((*this)== value._valueInStr);
}


Long operator+(  Long leftOperand,  Long rightOperand)
{ 
	Long tmp;
	Long Result;
	char result[21] = { '\0' };
	leftOperand.Reverse(leftOperand.GetValue());
	rightOperand.Reverse(rightOperand.GetValue());
	if (strlen(leftOperand.GetValue()) < strlen(rightOperand.GetValue()))
	{
		tmp=leftOperand;
		leftOperand = rightOperand;
		rightOperand = tmp;
	}
	int dec = 0;
	for (size_t i = 0;i<strlen(leftOperand.GetValue());++i)
	{
		int sum = 0;
		char rightOper;
		if (i >= strlen(rightOperand.GetValue()))
			rightOper = '0';
		else
			rightOper = rightOperand.GetValue()[i];
		sum = leftOperand.GetValue()[i] - '0' + rightOper - '0' + dec;
		if (sum > 9)
		{
			result[i] = (sum % 10) + '0';
			dec = 1;
		}
		else
		{
			result[i] = sum + '0';
			dec = 0;
		}
	}
	if (dec == 1)
		if (strlen(leftOperand.GetValue()) <= 20)
			result[strlen(leftOperand.GetValue())] =' 1';
	leftOperand.Reverse(result);
	Result.SetValue(result);
	return Result;
}


Long operator-(Long leftOperand, Long rightOperand)
{
	Long Result;
	char result[21] = { '\0' };
	if (leftOperand < rightOperand)
	{
		throw  Long::A_less_B(leftOperand.GetValue(), rightOperand.GetValue());
	}
	leftOperand.Reverse(leftOperand.GetValue());
	rightOperand.Reverse(rightOperand.GetValue());
	int dec = 0;
	for (size_t i = 0; i < strlen(leftOperand.GetValue()); ++i)
	{
		int sub = 0;
		char rightOper;
		if (i >= strlen(rightOperand.GetValue()))
			rightOper = '0';
		else
			rightOper = rightOperand.GetValue()[i];
		sub = (leftOperand.GetValue()[i] - '0') - (rightOper - '0') + dec;
		if (sub < 0)
		{
			result[i] = 10+sub+ '0';
			dec = -1;
		}
		else
		{
			result[i] = sub + '0';
			dec = 0;
		}
	}
	int i = strlen(leftOperand.GetValue());
	while (((i-1)!= 0) && (result[i - 1] == '0'))
	{
		result[i - 1] = '\0';
		--i;
	}
	leftOperand.Reverse(result);
	Result.SetValue(result);
	return Result;

}

Long operator*(Long leftOperand, Long rightOperand)
{
	Long Result;
	Long tmp;
	Long iter("0");
	Long Up("1");
	if (leftOperand < rightOperand)
	{
		tmp = leftOperand;
		leftOperand = rightOperand;
		rightOperand = tmp;
	}
	
	while(iter<rightOperand)
	{
		Result = Result + leftOperand;
		iter = iter + Up;
		if (!Result.CheckBelong64Bit(Result.GetValue()))
			throw Long::Not_64bit_value(Result.GetValue());
	}

	
	return Result;
}

Long operator/(Long leftOperand, Long rightOperand)
{
	Long Up=("1");
	Long Result;
	Long CheckNull;
	if(rightOperand=="0")
	{ 
		throw Long::DivisionbyZero();
	}
	if (leftOperand < rightOperand)
		return Result;
	bool flag = true;
	while (flag)
	{
		leftOperand = leftOperand - rightOperand;
		Result = Result + Up;
		if (leftOperand < rightOperand)
			flag=false;
		
	}
	return Result;
}

Long operator % (Long leftOperand, Long rightOperand)
{
	if ((rightOperand == "0")||(rightOperand=="1"))
	{
		throw Long::WrongModul();
	}
	Long Result = leftOperand - (leftOperand / rightOperand)*rightOperand;
	return Result;
}


bool operator>( Long&leftOperand,  Long&rightOperand)
{
	bool flag = false;
	if (strlen(leftOperand.GetValue())==(strlen(rightOperand.GetValue())))
	{
		for (int i = 0; i < strlen(leftOperand.GetValue()); ++i)
		{
			if (((leftOperand.GetValue()[i])-'0') > ((rightOperand.GetValue()[i])-'0'))
			{
				flag = true;
				break;
			}
			if (((leftOperand.GetValue()[i])-'0') < ((rightOperand.GetValue()[i]))-'0')
			{
				break;
			}
		}
		return flag;
	}
	if((strlen(leftOperand.GetValue()) > strlen(rightOperand.GetValue())))
	      return true;
	if ((strlen(leftOperand.GetValue()) < strlen(rightOperand.GetValue())))
		return false;
}

bool operator <( Long&leftOperand, Long&rightOperand)
{
	if (leftOperand == rightOperand)
		return false;
	else
		return !(leftOperand > rightOperand);
}

bool operator>=( Long&leftOperand, Long&rightOperand)
{
	if ((leftOperand == rightOperand) || (leftOperand > rightOperand))
		return true;
	else
		return false;
}

bool operator<=( Long&leftOperand,  Long&rightOperand)
{
	if ((leftOperand == rightOperand) || (leftOperand < rightOperand))
		return true;
	else
		return false;
}


std::ostream& operator << (std::ostream& stream,  Long toOutput)
{
	if (strlen(toOutput.GetValue()) == 0)
		return stream << 0 << std::endl;
	return stream << toOutput.GetValue() <<  std::endl;
}

std::istream& operator >> (std::istream& stream, Long& toInput)
{
	char value[21] = { '\0' };
	stream >>value;

	toInput.SetValue(value);
	
	return stream;
}
