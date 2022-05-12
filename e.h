#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <time.h>
using namespace std;
class CFactory; //это фабрика, про нее не было прописано в задании, но создавать объекты класса с помощью нее легче, для этого она вообще и создана
class C{//сам класс
    public:
	vector<long long> a;
	virtual ~C(){a.clear();} //деструктор для уничтожения объектов
	virtual void output()=0;//виртуальная функция, для основоного класса нельзя использовать только для наследников
    static int read_data(const char *file, vector<C*> &arr, vector<CFactory*> &f);
    static int random_data( vector<C*> &arr, vector<CFactory*> &f);
    static int execute(vector<C*> &arr, vector<CFactory*> &f);
    

};
size_t first_1_position(bitset<64> x);
class CFactory
{public:
	virtual C* create()=0;
	virtual ~CFactory(){} 
};

class CData0: public C // 1 наследник, прописываем в нем в не конструткторы класса и виртуальную функцию
{public:
	CData0():C(){}
	CData0(const C &b):C(b){}
	void output();
};

class CData1: public C// 2 наследник, прописываем в нем в не конструткторы класса и виртуальную функцию
{public:
	CData1():C(){}
	CData1(const C &b):C(b){}
	void output();
};                    

class CFactoryCData0:public CFactory //штуки для фабрики (просто 1 строкой создают наследников)
{public:
	virtual C* create(){
		CData0 *t = new CData0();
		return t; 
 	}
};
class CFactoryCData1:public CFactory//штуки для фабрики
{public:
	virtual C* create(){
		CData1 *t = new CData1();
		return t; 
	}
};