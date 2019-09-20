/*
♥Лейченко Кира Андреевна M8О-201
♥Вариант 5
♥Создать класс Module для работы с целыми числами по модулю N. В классе должно быть два поля: число и N. Реализовать все арифметические операции. Реализовать операции сравнения.
*/

#include"Module.h"

#include<iostream>


int main()
{
	try
	{
		int user_comand;
		bool enterence = true;
		Module Input;
		Module left(1,4), right;
		right = left;
		int a = right.FindModul();
		/*
		std::cout << "This is menu for class Modul" << std::endl;
		while (enterence)
		{
			std::cout << "This is menu for class Modul" << std::endl;
			std::cout <<
				"1.Find modulo value" << std::endl <<
				"2.Operation with class's ojects" << std::endl <<
				"0.Exit" << std::endl;
			std::cout << "Write comand" << std::endl;
			std::cin >> user_comand;
			switch (user_comand)
			{
			case 1:
				std::cout << "Write value and modul separated by space" << std::endl;
				std::cin >> Input;
				std::cout << "Modulo value: " << Input.FindModul() << std::endl;
				break;
			case 2:
			{
				std::cout << "Operation with class's objects" << std::endl <<
					"1.Operation +" << std::endl <<
					"2.Operation -" << std::endl <<
					"3.Operation *" << std::endl <<
					"4.Operation /" << std::endl <<
					"5.Operation >" << std::endl <<
					"6.Operation <" << std::endl <<
					"7.Operation >=" << std::endl <<
					"8.Operation <=" << std::endl <<
					"9.Operation ==" << std::endl <<
					"10.Operation !=" << std::endl <<
					"0.exit" << std::endl;
				std::cin >> user_comand;
				switch (user_comand)
				{
				case 1:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << "A+B= " << (left + right) << std::endl;
					break;
				case 2:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << "A-B= " << (left - right) << std::endl;
					break;

				case 3:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << "A*B= " << (left * right) << std::endl;
					break;
				case 4:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << "A/B= " << (left / right) << std::endl;
					break;
				case 5:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A>B: " << (left > right) << std::endl;
					break;
				case 6:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A<B: " << (left < right) << std::endl;
					break;
				case 7:
					std::cout <<"Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A>=B: " << (left >= right) << std::endl;
					break;
				case 8:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A<=B: " << (left <= right) << std::endl;
					break;
				case 9:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A==B: " << (left == right) << std::endl;
					break;
				case 10:
					std::cout << "Write elemenst whith same modul" << std::endl;
					std::cin >> left;
					std::cin >> right;
					std::cout << " Result A!=B: " << (left != right) << std::endl;
					break;
				}
				break;
			}
			case 0:enterence = false; break;
			}

		}
		std::cout << "Thank you fo using" << std::endl;
		*/
	}
	catch(Module::Wrongmodul modul)
	{
		std::cout << "You write incorrect modul: " << modul._modul<<std::endl;
	}
	catch (Module::DiffrentModuls modul)
	{
		std::cout << "I can't do it,diffrent moduls:" << std::endl << "Modul_1: " << modul._modul1 << std::endl << "Modul_2: " << modul._modul2<<std::endl;
	}
	catch (Module::DivisionbyZero)
	{
		std::cout << "Division by zero, becouse leftOperand==0" << std::endl;
	}

	system("pause");
	return 0;
}
