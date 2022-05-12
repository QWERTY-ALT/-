#include "e.h"

int main(void)
{
    setlocale (LC_ALL, "ru");
    int input, err;
    vector<CFactory *> f = {new CFactoryCData0(), new CFactoryCData1()}; //вектор фабрик
	vector <C*> arr;//вектор элементов класса, их будет в итоге 3, элемент для последовательности а, б, с
    cout << "Способ ввода входных данных:\n"
    << "1. Из файла.\n"
    << "2. Генерировать рандомно." << endl;
    cin >> input;
    
    switch (input) {
        case 1:
	        err=C::read_data("1.txt", arr, f);
            break;
        case 2:
	        err=C::random_data( arr, f);
            break;
        default:
            cout << "Введено некорректное число." << endl;
            return -1;
    }


    switch (err) {
        case 0:
            cout << "Некорректный класс" << endl;
            delete f[0]; //это очистка фабрик и векторов
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return 0;
        case -1:
            cout << "Ошибка чтения файла" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -1;
        case -3:
            cout << "Файл содержит некорректные данные" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -3;
        case -4:
            cout << "Число последовательностей в файле некорректно" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }

            return -4;
        case -5:
            cout << "Последовательности разной длины" << endl;
            delete f[0];
		    delete f[1];
		    f[0]=f[1]=NULL;
	        for(size_t i = 0; i < arr.size(); i++){
		      delete arr[i];
		      arr[i] = NULL;
	       }
            return -5;
    }
    cout << "Последовательность А: ";
 //   arr[0]->output(); //пока закоменчен вывод (такой потому что разный для разных наследников)
    cout << "Последовательность B: "; // так как для проверки распараллеливания в рандомном вводе стоит огромное число, если раскоментить будет минут 10 выводить
 //   arr[1]->output();
    C::execute( arr, f);
    cout << "Последовательность C: ";
//    arr[2]->output();
}
