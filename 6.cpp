//Во входном файле in.txt заданы целые числа в диапазоне от 1 до 3999, например:
//112 24 9 3517 438 56
//Вывести те же числа в выходной файл out.txt, используя римскую систему счисления, например:
//CXII XXIV IX MMMDXVII CDXXXVIII LVI
//Напоминание. В римской системе счисления I=1, IV=4, V=5, IX=9, X=10, L=50, C=100, D=500, M=100

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::locale;
using std::string;


int main()
{
	locale::global(locale(""));

	unsigned a[9] = { 1000, 200, 100, 50, 10, 9, 5, 4, 1 };
	string r[9] = { "M", "D", "C", "L", "X", "IX", "V", "IV", "I" };
	unsigned n;
	string s;
	std::ifstream ifs("d:\\in.txt");
	std::ofstream ofs("d:\\out.txt");
	while (!ifs.eof())
	{
		s.clear();
		ifs >> n;
		cout << n;
		for (unsigned i = 0; i < 9; ++i)
		{
			unsigned c = n / a[i];
			for (unsigned j = 0; j < c; ++j) s += r[i];
			n %= a[i];
		}
		ofs << s << endl;
		cout << " = " << s << endl;
	}

	ifs.close();
	ofs.close();

	cout << endl;
	system("pause");
	return 0;
}
