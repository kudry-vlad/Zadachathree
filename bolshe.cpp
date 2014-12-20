#include "stdafx.h"

#define N	5

int gen_random(int rangemin, int rangemax)
{
	return rangemin + rand() % (rangemax - rangemin + 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool square[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			square[i][j] = (bool)gen_random(0, 1);
		}
	}

	int counter = 0;
	bool flag = false;
	std::cout << "\t";
	// считем по столбцам
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (square[j][i])
			{
				counter++;
			}
			else if (counter)
			{
				if (flag)
				{
					std::cout << ", " << counter;
				}
				else
				{
					std::cout << counter;
				}
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)
			{
				std::cout << ", " << counter;
			}
			else
			{
				std::cout << counter;
			}
			counter = 0;
		}
		else if (flag == false)
		{
			std::cout << "0";
		}
		flag = false;
		std::cout << "\t";
	}
	std::cout << std::endl;
	//	считаем по строкам
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (square[i][j])
			{
				counter++;
			}
			else if (counter)
			{
				if (flag)
				{
					std::cout << ", " << counter;
				}
				else
				{
					std::cout << counter;
				}
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)
			{
				std::cout << ", " << counter;
			}
			else
			{
				std::cout << counter;
			}
			counter = 0;
		}
		else if (flag == false)
		{
			std::cout << "0";
		}
		flag = false;
		std::cout << "\t";
		//	попутно выводим значения массива
		for (int j = 0; j < N; j++)
		{
			std::cout << square[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
