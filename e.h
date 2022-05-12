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
class CFactory; //��� �������, ��� ��� �� ���� ��������� � �������, �� ��������� ������� ������ � ������� ��� �����, ��� ����� ��� ������ � �������
class C{//��� �����
    public:
	vector<long long> a;
	virtual ~C(){a.clear();} //���������� ��� ����������� ��������
	virtual void output()=0;//����������� �������, ��� ���������� ������ ������ ������������ ������ ��� �����������
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

class CData0: public C // 1 ���������, ����������� � ��� � �� ������������� ������ � ����������� �������
{public:
	CData0():C(){}
	CData0(const C &b):C(b){}
	void output();
};

class CData1: public C// 2 ���������, ����������� � ��� � �� ������������� ������ � ����������� �������
{public:
	CData1():C(){}
	CData1(const C &b):C(b){}
	void output();
};                    

class CFactoryCData0:public CFactory //����� ��� ������� (������ 1 ������� ������� �����������)
{public:
	virtual C* create(){
		CData0 *t = new CData0();
		return t; 
 	}
};
class CFactoryCData1:public CFactory//����� ��� �������
{public:
	virtual C* create(){
		CData1 *t = new CData1();
		return t; 
	}
};