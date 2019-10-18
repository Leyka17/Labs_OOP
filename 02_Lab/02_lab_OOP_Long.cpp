/*
♥Лейченко Кира Андреевна M8О-201
♥Вариант 13
♥
Создать класс Long для работы с целыми беззнаковыми числами из 64 бит. Число должно быть представлено двумя полями unsigned int. Должны быть реализованы арифметические операции, присутствующие в С++, и сравнения.
Операции необходимо реализовать в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа Long.
*/


#include<iostream>
#include<string.h>
#include"Long.h"

int main()
{
	try
	{
		Long leftOperand;
		Long rightOperand;
		char*x = new char[3]{ '\0' };

		char*y = new char[3]{ '\0' };

		char*examp = new char[3]{ '\0' };

		char operation = '\0';
		std::cout << "It class for work with unsigned 64Bit value" << std::endl;
		bool flag = true;
		while (flag)
		{
			std::cout << "Please write argument X and Y" << std::endl;
			std::cout << "X=";
			std::cin >> (x);
			leftOperand.SetValue(x);
			std::cout << "Y=";
			std::cin >> (y);
			rightOperand.SetValue(y);
			std::cout << "Write operation(example: X+Y)" << std::endl << "Z=";
			std::cin >> (examp);
			Long Result;
			Long tmpL;
			Long tmpR;

			if (tolower(*examp) == 'y')
			{
				tmpL = rightOperand;
			}
			if (tolower(*examp) == 'x')
			{
				tmpL = leftOperand;
			}
			++examp;
			char Mycase = *examp;
			++examp;
			if (tolower(*examp) == 'y')
			{
				tmpR = rightOperand;
			}
			if (tolower(*examp) == 'x')
			{
				tmpR = leftOperand;
			}

			switch (Mycase)
			{
			case'+':
			{
				std::cout << "Z=" << (tmpL + tmpR);
				break;
			}
			case'-':
			{
				std::cout << "Z=" << (tmpL - tmpR);
				break;
			}
			case'*':
			{
				std::cout << "Z=" << (tmpL * tmpR);
				break;
			}
			case'/':
			{
				std::cout << "Z=" << (tmpL / tmpR);
				break;
			}
			case'%':
			{
				std::cout << "Z=" << (tmpL %tmpR);
				break;
			}
			}
			char exit;
			std::cout << "Exit?(0/1)" << std::endl;
			std::cin >> exit;
			if (exit == '0')
			{
				flag = false;
			}
		}

		
	}
	catch (Long::WrongModul )
	{
		std::cout << "You write incorrect modul: "  << std::endl;
	}
	catch (Long::Not_64bit_value value)
	{
		std::cout << "It is not 64 bit value" << std::endl << "Value: " << value._value << std::endl;
	}
	catch (Long::DivisionbyZero)
	{
		std::cout << "Division by zero, becouse rightOperand==0" << std::endl;
	}
	catch (Long::A_less_B value)
	{
		std::cout << value._value1 << "<" << value._value2 <<" I can't do it"<< std::endl;
	}

	system("pause");

	
	return 0;

}