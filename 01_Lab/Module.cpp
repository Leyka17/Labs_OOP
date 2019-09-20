#include"Module.h"
#include <iostream>
#include<algorithm>
#include<cmath>


//ctors
Module::Module(int num, int modul) :_num {num}
{

	if (modul <=0)
	{
		throw Wrongmodul(modul);//raise exeption
	}
	_modul = modul;
}


//copy ctor
Module::Module(const Module&other)
{
	*this = other;
}


//del ctor
Module::~Module()
{

}

//Getter and Setter
int Module::GetModul()const
{
	return _modul;
}

int Module::GetNum()const
{
	return _num;
}

 void Module::SetModul(const int &modul)
 {
	if (modul<= 0)
	{
		throw Wrongmodul(modul);
	}
	_modul =modul;
 }

 void Module::SetNum(const int &num)
 {
	_num = num;
 }


 //functions
 int Module::FindModul()const
 {
	 return abs( _num - (_num / _modul)*_modul);
 }

 int Module::FindModulForInt(int num, int modul)const
 {
	 if (modul <= 0)
	 {
		 throw Wrongmodul(modul);
	 }
	 return abs( num - (num / modul)*modul);
	 
 }


 //operators which belong to class
Module& Module::operator=(const Module &other)
 {
	 _num = other.GetNum();
	 _modul = other.GetModul();
	 return *this;
 }


 //Принимаем не константную ссылку, так как объект other должен изменить значение
Module& Module::operator=( Module &&other)
 {
	 std::swap(_num, other._num);
	 std::swap(_modul, other._modul);
	 return *this;
 }

 

 Module operator+(const Module& leftOperand, const Module& rightOperand)
 {
	 if (leftOperand.GetModul() == rightOperand.GetModul())
	 {
		 Module temporary;
		 temporary.SetNum(leftOperand.GetNum() + rightOperand.GetNum());
		 temporary.SetModul(leftOperand.GetModul());
		 return temporary;
	 }
	 throw Module::DiffrentModuls(leftOperand.GetModul(),rightOperand.GetModul());
 }

 Module  operator+(const int& leftOperand, const Module& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum(leftOperand + rightOperand.GetNum());
	 temporary.SetModul(rightOperand.GetModul());
	 return temporary;
 }

 Module operator+(const Module& leftOperand, const int& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum(leftOperand.GetNum()+ rightOperand);
	 temporary.SetModul( leftOperand.GetModul());
	 return temporary;
 }


 Module operator-(const Module& leftOperand, const Module& rightOperand)
 {
	 if (leftOperand.GetModul() == rightOperand.GetModul())
	 {
		 Module temporary;
		 temporary.SetNum( leftOperand.GetNum() - rightOperand.GetNum());
		 temporary.SetModul (leftOperand.GetModul());
		 return temporary;
	 }
	 throw Module::DiffrentModuls(leftOperand.GetModul(), rightOperand.GetModul());
 }

 Module operator-(const Module& leftOperand, const int& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum ( leftOperand.GetNum() - rightOperand);
	 temporary.SetModul(leftOperand.GetModul());
	 return temporary;
 }

 Module  operator-(const int& leftOperand, const Module& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum (leftOperand - rightOperand.GetNum());
	 temporary.SetModul (rightOperand.GetModul());
	 return temporary;
 }


 Module operator/(const Module& leftOperand, const Module& rightOperand)
 {
	 if (rightOperand.GetNum())
	 {
		 if (leftOperand.GetModul() == rightOperand.GetModul())
		 {
			 Module temporary;
			 temporary.SetNum(leftOperand.GetNum() / rightOperand.GetNum());
			 temporary.SetModul(leftOperand.GetModul());
			 return temporary;

		 }
		 throw Module::DiffrentModuls(leftOperand.GetModul(), rightOperand.GetModul());
	 }
	 throw Module::DivisionbyZero();
 }

 Module operator/(const Module& leftOperand, const int& rightOperand)
 {
	 if(rightOperand)
		 {
			 Module temporary;
			 temporary.SetNum(leftOperand.GetNum() /rightOperand);
			 temporary.SetModul ( leftOperand.GetModul());
			 return temporary;
		 }
	 throw Module::DivisionbyZero();
 }
 Module  operator/(const int& leftOperand, const Module& rightOperand)
 {
	 if(rightOperand.GetNum())
	 {
		 Module temporary;
		 temporary.SetNum(leftOperand / rightOperand.GetNum());
		 temporary.SetModul(rightOperand.GetModul());
		 return temporary;
	 }
	 throw Module::DivisionbyZero();
 }


 Module operator*(const Module& leftOperand, const Module& rightOperand)
 {
	 if (leftOperand.GetModul() == rightOperand.GetModul())
	 {
		 Module temporary;
		 temporary.SetNum( leftOperand.GetNum() * rightOperand.GetNum());
		 temporary.SetModul(leftOperand.GetModul());
		 return temporary;
	 }
	 throw Module::DiffrentModuls(leftOperand.GetModul(), rightOperand.GetModul());
 }

 Module operator*(const Module& leftOperand, const int& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum(leftOperand.GetNum() * rightOperand);
	 temporary.SetModul( leftOperand.GetModul());
	 return temporary;
 }

 Module  operator*(const int& leftOperand, const Module& rightOperand)
 {
	 Module temporary;
	 temporary.SetNum( leftOperand * rightOperand.GetNum());
	 temporary.SetModul( rightOperand.GetModul());
	 return temporary;
 }


 bool operator==(const Module& leftOperand, const Module& rightOperand)
 {
	 if((leftOperand.GetModul()==rightOperand.GetModul())&&(leftOperand.FindModul()==rightOperand.FindModul()))
	      return true;
     return false;
 }
  bool operator==(const int& leftOperand, const Module& rightOperand)
 {
	 if(rightOperand.FindModulForInt(leftOperand,rightOperand.GetModul())==rightOperand.FindModul())
		 return true;
     return false;
 }

 bool operator==(const Module& leftOperand, const int& rightOperand)
 {
	 if (leftOperand.FindModul() == leftOperand.FindModulForInt(rightOperand,leftOperand.GetModul()))
		 return true;
	 return false;
 }


  bool operator!=(const Module& leftOperand, const Module& rightOperand)
 {
	 return !(leftOperand == rightOperand);
 }

   bool operator!=(const int& leftOperand, const Module& rightOperand)
 {
	 return !(leftOperand == rightOperand);
 }

  bool operator!=(const Module& leftOperand, const int& rightOperand)
 {
	 return !(leftOperand == rightOperand);
 }


 bool operator>(const Module& leftOperand, const Module&rightOperand)
 {
	 if (leftOperand.GetModul() == rightOperand.GetModul())
	 {
		 if (leftOperand.FindModul() > rightOperand.FindModul())
			 return true;
		 return false;
	 }
	 throw Module::DiffrentModuls(leftOperand.GetModul(), rightOperand.GetModul());
 }

 bool operator>(const Module& leftOperand, const int& rightOperand)
 {
	 if (leftOperand.FindModul() > leftOperand.FindModulForInt(rightOperand,leftOperand.GetModul()))
		 return true;
	 return false;
 }

 bool operator>(const int& leftOperand, const Module&rightOperand)
 {
	 if (  rightOperand.FindModulForInt(leftOperand, rightOperand.GetModul()) > rightOperand.FindModul())
		 return true;
	 return false;
 }


 bool operator<(const Module& leftOperand, const Module&rightOperand)
 {
	 if (leftOperand.GetModul() == rightOperand.GetModul())
	 {
		 if (leftOperand.FindModul() < rightOperand.FindModul())
			 return true;
		 return false;
	 }
	 throw Module::DiffrentModuls(leftOperand.GetModul(), rightOperand.GetModul());
 }

 bool operator<(const Module& leftOperand, const int& rightOperand)
 {
	 if (leftOperand.FindModul() < leftOperand.FindModulForInt(rightOperand,leftOperand.GetModul()))
		 return true;
	 return false;
 }

 bool operator<(const int& leftOperand, const Module&rightOperand)
 {
	 if ( rightOperand.FindModulForInt(leftOperand,rightOperand.GetModul())<rightOperand.FindModul())
		 return true;
	 return false;
 }

 bool operator>=(const Module& leftOperand, const Module&rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand > rightOperand))
		 return true;
	 return false;
 }

 bool operator>=(const Module& leftOperand, const int& rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand > rightOperand))
		 return true;
	 return false;
 }

 bool operator>=(const int& leftOperand, const Module&rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand > rightOperand))
		 return true;
	 return false;
 }


 bool operator<=(const Module& leftOperand, const Module&rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand < rightOperand))
		 return true;
	 return false;
 }

 bool operator<=(const Module& leftOperand, const int& rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand < rightOperand))
		 return true;
	 return false;
 }

 bool operator<=(const int& leftOperand, const Module&rightOperand)
 {
	 if ((leftOperand == rightOperand) || (leftOperand < rightOperand))
		 return true;
	 return false;
 }


 std::ostream& operator << (std::ostream& stream, const Module& toOutput)
 {
	 return stream << " Value: " << toOutput.GetNum() << ' ' << "Module: " << toOutput.GetModul() <<' ' <<
		" Modulo value: "<<toOutput.FindModul()<<std::endl;
 }

 std::istream& operator >> (std::istream& stream, Module& toInput)
 {
	 int num;
	 int modul;
	 stream >> num >> modul;

	 toInput.SetNum(num);
	 toInput.SetModul(modul);
	 return stream;
 }

