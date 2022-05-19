#include "e.h"
int C::random_data( vector<C*> &arr, vector<CFactory*> &f){ //просто рандомное заполнение
    int len=rand() % 20+1;
    int Type0=rand() % 2;
    int Type1=rand() % 2;
    #ifdef _type0
    Type0=0;Type1=0;
    #endif
    #ifdef _type1
    Type0=1;Type1=1;
    #endif
    C *r = f[Type0]->create(); //это фабрика создала объект, типы объектов называем 0 и 1, строку а
    for (int i = 0; i <len ; i++) {
        r->a.push_back(rand() % 20+1);
    }
    arr.push_back(r);
    C *p = f[Type1]->create(); //строку б
    for (int i = 0; i <len ; i++) {
        p->a.push_back(rand() % 20+1);
    }
    arr.push_back(p);
    return 1;
}
int C::read_data(const char *file, vector<C*> &arr, vector<CFactory*> &f){ //чтение из файла
    ifstream in(file); string buf;int i=0;
	if(in.is_open()){
		while(getline(in, buf)){
		    i++;
	    	int Type; stringstream ss(buf); char c; long long x;
			if(!buf.empty()){
				if((ss >> Type) && (Type >= 0) && (Type <= 1)) {//не было конкретно прописано как файл выглядит, тут 1 число обязательно 0 или 1 для опредления типа объекта
					C *r = f[Type]->create();
					while(ss >> x){
						r->a.push_back(x);
					}
					while(ss >> c && c == ' ');
					if(!ss.eof()){
							delete r;
							return -3; //если не числа в файле
					}
					arr.push_back(r);
				}
				else{
					return 0; //если не 0 или 1 в начале
				}     
			}
		}
		if (i!=2){
		   return -4;//если в файле больше или меньше 2х строк
		}
		if (arr[0]->a.size()!=arr[1]->a.size()){
		    return -5;//если разный размер
		}
		return 1;
	}
	return -1;//если файла нет
}
void CData0:: output()//виртуальная функция вывода для 1 наследника, тип 0
{
    cout <<"\n";
    auto iter = a.begin(); //испоьзование итератора
    while(iter!=a.end())
    {
        cout << *iter <<" ";
        ++iter;
    }
    cout <<"\n";
}

void CData1:: output()//виртуальная функция вывода для 2 наследника, тип 1
{
    cout <<"\n";
    auto iter = a.begin();//испоьзование итератора
    while(iter!=a.end())  
    {
        cout << *iter <<"\n";
        ++iter;
    }
    cout <<"\n";
}

int C::execute( vector<C*> &arr, vector<CFactory*> &f){
    time_t t1, t2;
    C *r = f[rand() % 2]->create();
    r->a.resize(arr[0]->a.size());
    auto lambda_fun = [](bitset<64> x)->int{ //ЛЯМБДА ФУНКЦИЯ
        size_t i;
        for (i = 0; i < x.size() && !x.test(i); ++i);
        if (i == 65)
            return 0;
        else return i+1;
    };
    
    clock_t start = clock();
    #ifdef _OPENMP
    #pragma omp parallel for //распараллеливание создания с, действует так что одновременно и независимо друг от друга для разных i делается действие в цикле 
    for (size_t i=0;i<arr[0]->a.size();i++){ // для сравнения времени 2 вида одного и того же, с распараллеливанием и без него
        bitset<64> x(arr[0]->a[i]), y(arr[1]->a[i]);
        int z=lambda_fun(x) + lambda_fun(y);
        r->a[i]=z;
        
    }
    clock_t end = clock();
    cout << "parallel time: " << (end - start) << endl;
    #endif
    clock_t start1 = clock();
    for (size_t i=0;i<arr[0]->a.size();i++){
        bitset<64> x(arr[0]->a[i]), y(arr[1]->a[i]);
        int z=lambda_fun(x) + lambda_fun(y);
        r->a[i]=z;
    }
    clock_t end1 = clock();
    cout << "nonparallel time: " << (end1 - start1) << endl;
    arr.push_back(r);
    return 0;
}

int C::out( vector<C*> &arr){
    for (size_t i=0;i<arr.size();i++){ // для сравнения времени 2 вида одного и того же, с распараллеливанием и без него
        for (int n : arr[i]->a){cout<< n<<" ";}
        cout<<"\n";
    }
    return 0;
}
