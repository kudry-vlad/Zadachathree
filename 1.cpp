//Представлением натурального числа N в Фибоначчиевой системе счисления называется набор целых значений-цифр (Dn, Dn-1, …, D2), 
//для которого N=DnFn+Dn-1Fn-1+…+D3F3+D2F2, где Di=0 или Di=1, Fi - числа Фибоначчи: F1=F2=1, Fn+2=Fn+Fn+1. 
//К примеру, 20=113+08+15+03+12+01=101010. Во входном файле in.txt содержится последовательность натуральных чисел, например:
//20 7 26 17 9
//Перевести все заданные целые числа в Фибоначчиевую систему счисления и вывести результат в выходной файл out.txt, например:
//101010 1010 1001000 100101 10001

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::locale;
using std::string;


int main()
{
	locale::global(locale(""));

	int n;
	std::vector<int> F;
	F.push_back(1);
	F.push_back(2);
	string r;

	std::ofstream ofs("c://out.txt");
	std::ifstream ifs("c://in.txt");
	if (!ifs)
	{
		cout << "Ошибка при открытии файла." << endl;
	}
	else
	{
		while (true)
		{
			ifs >> n;
			if (!ifs.good()) break;
			r.clear();
			while (*(F.rbegin()) < n) F.push_back(*(F.rbegin()) + *(F.rbegin() + 1));
			std::vector<int>::reverse_iterator i = F.rbegin();
			while (*i > n) ++i;
			for (; i != F.rend(); ++i)
			{
				int ttt = *i;
				if (n - *i >= 0)
				{
					n -= *i;
					r += '1';
				}
				else r += '0';
			}
			ofs << r << endl;
			cout << r << endl;
		}

	}

	ofs.close();

	cout << endl;
	system("pause");
	return 0;
}
