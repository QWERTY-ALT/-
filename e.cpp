#include "e.h"
int C::random_data( vector<C*> &arr, vector<CFactory*> &f){ //просто рандомное заполнение
    srand(time(nullptr));
 //   int len=rand() % 20+1;
    int len=10000000; //это чтобы openmp протестить
    C *r = f[rand() % 2]->create(); //это фабрика создала объект, типы объектов называем 0 и 1, строку а
    for (int i = 0; i <len ; i++) {
        r->a.push_back(rand() % 20+1);
    }
    arr.push_back(r);
    C *p = f[rand() % 2]->create(); //строку б
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
				if((ss >> Type) && (Type >= 0) && (Type <= 1)) {//не было конкретно прописано как файл выгл€дит, тут 1 число об€зательно 0 или 1 дл€ опредлени€ типа объекта
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
void CData0:: output()//виртуальна€ функци€ вывода дл€ 1 наследника, тип 0
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

void CData1:: output()//виртуальна€ функци€ вывода дл€ 2 наследника, тип 1
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
    auto lambda_fun = [](bitset<64> x)->int{ //ЋяћЅƒј ‘”Ќ ÷»я
        size_t i;
        for (i = 0; i < x.size() && !x.test(i); ++i);
        if (i == 65)
            return 0;
        else return i+1;
    };
    
    time(&t1);
    #pragma omp parallel for //распараллеливание создани€ с, действует так что одновременно и независимо друг от друга дл€ разных i делаетс€ действие в цикле 
    for (size_t i=0;i<arr[0]->a.size();i++){ // дл€ сравнени€ времени 2 вида одного и того же, с распараллеливанием и без него
        bitset<64> x(arr[0]->a[i]), y(arr[1]->a[i]);
        int z=lambda_fun(x) + lambda_fun(y);
        r->a[i]=z;
    }
    time(&t2);
    cout << "parallel time: " << t2-t1 << endl;
    time(&t1);
    for (size_t i=0;i<arr[0]->a.size();i++){
        bitset<64> x(arr[0]->a[i]), y(arr[1]->a[i]);
        int z=lambda_fun(x) + lambda_fun(y);
        r->a[i]=z;
    }
    time(&t2);
    cout << "nonparallel time: " << t2-t1 << endl;
    arr.push_back(r);
    return 0;
}
