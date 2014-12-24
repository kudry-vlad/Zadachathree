#include "stdafx.h"

#define N	5
#define M	6

int gen_random(int rangemin, int rangemax)
{
	return rangemin + rand() % (rangemax - rangemin + 1);
}

int main()
{
	//	заполняем поле
	bool square[N][M];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			square[i][j] = (bool)gen_random(0, 1);
		}
	}
	
	char s[15];
	std::string r_col[N];
	std::string r_row[M];

	// считем по столбцам
	int counter = 0;
	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (square[j][i])	counter++;
			else if (counter)
			{
				if (flag)	r_row[i] += ",";
				sprintf_s(s, "%d", counter);
				r_row[i] += s;
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)	r_row[i] += ",";
			sprintf_s(s, "%d", counter);
			r_row[i] += s;
			counter = 0;
		}
		else if (flag == false)
			r_row[i] += "0";
		flag = false;
	}
	//	считаем по строкам
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (square[i][j])	counter++;
			else if (counter)
			{
				if (flag)	r_col[i] += ",";
				sprintf_s(s, "%d", counter);
				r_col[i] += s;
				flag = true;
				counter = 0;
			}
		}
		if (counter)
		{
			if (flag)	r_col[i] += ",";
			sprintf_s(s, "%d", counter);
			r_col[i] += s;
			counter = 0;
		}
		else if (flag == false)
			r_col[i] += "0";
		flag = false;
	}


	//	Выведем реузльтат
		//	Результат по столбцам
	std::cout << "\t";
	for (int i = 0; i < M; i++)
		std::cout << r_row[i] << "\t";
	std::cout << std::endl;
		//	Результат по строкам
	for (int i = 0; i < N; i++)
	{
		std::cout << r_col[i] << "\t";
		for (int j = 0; j < M; j++)
			std::cout << square[i][j] << "\t";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
