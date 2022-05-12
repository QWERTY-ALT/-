#include "e.h"

int main(void)
{
    setlocale (LC_ALL, "ru");
    int input, err;
    vector<CFactory *> f = {new CFactoryCData0(), new CFactoryCData1()}; //������ ������
	vector <C*> arr;//������ ��������� ������, �� ����� � ����� 3, ������� ��� ������������������ �, �, �
    cout << "������ ����� ������� ������:\n"
    << "1. �� �����.\n"
    << "2. ������������ ��������." << endl;
    cin >> input;
    
    switch (input) {
        case 1:
	        err=C::read_data("1.txt", arr, f);
            break;
        case 2:
	        err=C::random_data( arr, f);
            break;
        default:
            cout << "������� ������������ �����." << endl;
            return -1;
    }


    switch (err) {
        case 0:
            cout << "������������ �����" << endl;
            delete f[0]; //��� ������� ������ � ��������
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return 0;
        case -1:
            cout << "������ ������ �����" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -1;
        case -3:
            cout << "���� �������� ������������ ������" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -3;
        case -4:
            cout << "����� ������������������� � ����� �����������" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }

            return -4;
        case -5:
            cout << "������������������ ������ �����" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -5;
    }
    cout << "������������������ �: ";
 //   arr[0]->output(); //���� ���������� ����� (����� ������ ��� ������ ��� ������ �����������)
    cout << "������������������ B: "; // ��� ��� ��� �������� ����������������� � ��������� ����� ����� �������� �����, ���� ������������ ����� ����� 10 ��������
 //   arr[1]->output();
    C::execute( arr, f);
    cout << "������������������ C: ";
//    arr[2]->output();
}