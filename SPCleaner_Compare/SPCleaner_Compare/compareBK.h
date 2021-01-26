#include "iostream"
#include "algorithm"
#include "fstream"
#include "String"
using namespace std;

#ifndef __compareBK_H__
#define __compareBK_H__

class compareBK
{
private:
	int(*inBK_re)[5]; 
	int sumlength;
	int *numSP_re; 
	int *arrSum_re;
public: 
	compareBK(int(*inBK_re_m)[5], int *numSP_re_m);
	void choose(int check);
	void compare(const int *chooseF, int length, int check=0);
	void print();
	~compareBK();
};

compareBK::compareBK(int(*inBK_re_m)[5], int *numSP_re_m)
{
	inBK_re = inBK_re_m;
	numSP_re = numSP_re_m;
}
void compareBK::choose(int check)
{
	int choose[17];
	string line;

	int i = 0;
	int numEOF = 0;									//classifiedBK�� �ִ� �� +1��ŭ ����.

	if (check == 0)
	{
		return;
	}
	std::ifstream choosed("choose.txt");
	getline(choosed, line);
	choosed.close();

	size_t location = line.find(",");
	size_t location_2 = 0;
	while (1)
	{
		if (location != string::npos)
		{
			string line_m = line.substr(location_2, location);
			location_2 = location + 1;
			location = line.find(",", location + 1);
			choose[i] = atoi(line_m.c_str());
			cout << choose[i] << endl;
			i++;

		}
		else if (location == string::npos)
		{
			string line_m = line.substr(location_2, line.length() - location_2);
			choose[i] = atoi(line_m.c_str());
			cout << choose[i] << endl;
			break;
		}
	}

	i++;
	choose[i] = 18;
	sort(choose, choose + i);													//������ ���ڵ��� ���� +1��ŭ�� ���� choose�� ������ ���ĵ�.

	if (choose[0] != 0)
	{
		compare(choose, i);
		compare(0, 0, 1);
	}
}
void compareBK::compare(const int *chooseF, int length, int check)
{
	int k, j, p;
	j = 0;
	//length�� ������ ����� ������ ����.
	if (check == 0)
	{
		int *arrSum;
		for (p = 0; p < length; p++)
		{
			for (k = 0; k < 5; k++)
			{
				int i = inBK_re[chooseF[p] - 1][k];
				if (i == 0)
					break;
				j++;
			}
		}

		sumlength = j;
		arrSum = new int[sumlength];

		k = 0;
		for (p = 0; p < length; p++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (inBK_re[chooseF[p] - 1][i] == 0)
				{
					break;
				}
				arrSum[k] = inBK_re[chooseF[p] - 1][i];
				k++;
			}
		}
		sort(arrSum, arrSum + sumlength);

		for (int i = 0; i < sumlength - 1; i++)
		{
			k = arrSum[i];
			j = arrSum[i + 1];

			if (k == j)
			{
				for (int a = i; a < sumlength - 1; a++)
				{
					arrSum[a] = arrSum[a + 1];
				}
				sumlength--;
				i--;
			}
		}

		arrSum_re = new int[sumlength];

		for (int i = 0; i < sumlength; i++)
		{
			arrSum_re[i] = arrSum[i];
		}

		delete[] arrSum;

	}
	else
	{
		for (int i = 0; i < 17; i++)
		{
			k = numSP_re[i];
			for (p = 0; p < sumlength; p++)
			{
				j = arrSum_re[p];
				j--;
				if (k == 1 && i == j)
				{
					numSP_re[i] = 0;
				}
			}
		}
	}
}
void compareBK::print()
{
	std::ofstream deinstall;
	deinstall.open("deinstall.txt");

	deinstall << "���� �� �������α׷� ���" << endl;

	char SPname[46];
	int a = 0;

	int line = 1;
	std::ifstream SPlist("SPlist.txt");
	int j = 0;

	for (int i = 0; i < 17; i++)
	{
		int k = numSP_re[i];

		if (k == 1)
		{
			for (j; j < i; j++)
			{
				SPlist.getline(SPname, sizeof(char) * 46);
			}
			SPlist.getline(SPname, sizeof(char) * 46);
			deinstall << line << " : " << SPname << endl;
			j++;
			line++;
		}
	}


	if (j != 17)
	{
		for (j; j < 17; j++)
			SPlist.getline(SPname, sizeof(char) * 46);
	}

	for (int i = 17; i < 21; i++)
	{
		int k = numSP_re[i];

		if (k == 1)
		{
			for (j; j < i; j++)
			{
				SPlist.getline(SPname, sizeof(char) * 46);
			}
			SPlist.getline(SPname, sizeof(char) * 46);
			deinstall << line << " : " << SPname << endl;
			j++;
			line++;
		}
	}
	deinstall << endl;
	deinstall.close();

}
compareBK::~compareBK()
{
	delete[] arrSum_re;
}
#endif