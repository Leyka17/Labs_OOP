#include<iostream>
class Module
{
private:
	int _num;
	int _modul;

public:
	//exeptions
	class Wrongmodul
	{
	public:int _modul;
		   Wrongmodul(int modul) :_modul{ modul } {}
	};

	class DivisionbyZero {};

	class DiffrentModuls
	{
	public: int _modul1; 
			int _modul2;
			DiffrentModuls(int modul1, int modul2) :_modul1{ modul1 }, _modul2{ modul2 } {}
			
	};

	//ctors
	explicit Module(int _num = 0, int _modul = 1);//нет неявного присвоения нельзя module=8,7

	//copy ctor

	Module(const Module&other);

	//del ctor
	~Module();

//Getter and setter

	int GetNum()const;
	int GetModul()const;
	void SetNum(const int&value);
	void SetModul(const int &value);
//functions

	int FindModul()const;
	int FindModulForInt(int val, int modul)const;
//operators
	Module&operator=(Module&&other);//for move itemsfor copy items

    Module& operator = (const Module& other);//for copy items
	
	

};

Module operator+(const Module&leftOperand, const Module &rightOperand);
Module operator+(const Module& leftOperand, const int& rightOperand);
Module  operator+(const int& leftOperand, const Module& rightOperand);

Module operator-(const Module&leftOperand, const Module &rightOperand);
Module operator-(const Module& leftOperand, const int& rightOperand);
Module  operator-(const int& leftOperand, const Module& rightOperand);

Module operator/(const Module&leftOperand, const Module &rightOperand);
Module operator/(const Module& leftOperand, const int& rightOperand);
Module  operator/(const int& leftOperand, const Module& rightOperand);

Module operator*(const Module&leftOperand, const Module &rightOperand);
Module operator*(const Module& leftOperand, const int& rightOperand);
Module operator*(const int& leftOperand, const Module& rightOperand);

bool operator==(const Module& leftOperand, const Module&rightOperand);
bool operator==(const Module& leftOperand,const int& rightOperand);
bool operator==(const int& leftOperand, const Module&rightOperand);

bool operator!=(const Module& leftOperand, const Module&rightOperand);
bool operator!=(const Module& leftOperand, const int& rightOperand);
bool operator!=(const int& leftOperand, const Module&rightOperand);

bool operator>(const Module& leftOperand, const Module&rightOperand);
bool operator>(const Module& leftOperand, const int& rightOperand);
bool operator>(const int& leftOperand, const Module&rightOperand);

bool operator<(const Module& leftOperand, const Module&rightOperand);
bool operator<(const Module& leftOperand, const int& rightOperand);
bool operator<(const int& leftOperand, const Module&rightOperand);

bool operator>=(const Module& leftOperand, const Module&rightOperand);
bool operator>=(const Module& leftOperand, const int& rightOperand);
bool operator>=(const int& leftOperand, const Module&rightOperand);

bool operator<=(const Module& leftOperand, const Module&rightOperand);
bool operator<=(const Module& leftOperand, const int& rightOperand);
bool operator<=(const int& leftOperand, const Module&rightOperand);


std::ostream& operator << (std::ostream& stream, const Module& toOutput);
std::istream& operator >> (std::istream& stream, Module& toInput);