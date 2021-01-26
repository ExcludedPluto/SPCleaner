#include "cstdio"
#include "iostream"
#include "Search.h"
#include "fstream"

#ifndef __classify_H__
#define __classify_H__

class classify
{
private:
	char ThereBK[17][9];
	int *numSP_re;
	int (*inBK_re)[5];
public:
	classify(int *numSP_re_m, int(*inBK_re_m)[5]);
	int checkBK();
};
classify::classify(int *numSP_re_m, int(*inBK_re_m)[5])
{
	numSP_re = numSP_re_m;
	inBK_re = inBK_re_m;
}
int classify::checkBK()
{
	std::ofstream classify;
	classify.open("classifiedBK.txt");
	int i = 0;
	int k = 1;

	if (numSP_re[3] == 1)
	{
		if (numSP_re[1] == 1)
		{
			classify << k << ": 산업은행" << std::endl;
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 4;
			i++;
			k++;
		}
		if (numSP_re[12] == 1)
		{
			if (numSP_re[1] == 1 && numSP_re[13] == 1)
			{
				classify << k << ": 우리은행" << std::endl;
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 4;
				inBK_re[i][2] = 13;
				inBK_re[i][3] = 14;
				i++;
				k++;
			}
			if (numSP_re[8] == 1 && numSP_re[15] == 1)
			{
				classify << k << ": 전북은행" << std::endl;
				inBK_re[i][0] = 4;
				inBK_re[i][1] = 9;
				inBK_re[i][2] = 13;
				inBK_re[i][3] = 16;
				i++;
				k++;
			}
		}
	}

	if (numSP_re[6] == 1)
	{
		classify << k << ": 제주은행" << std::endl;
		inBK_re[i][0] = 7;
		i++;
		k++;

		if (numSP_re[2] == 1)
		{
			classify << k << ": 광주은행" << std::endl;
			inBK_re[i][0] = 3;
			inBK_re[i][1] = 7;
			i++;
			k++;
		}

		if (numSP_re[1] == 1)
		{
			if (numSP_re[8] == 1)
			{
				classify << k << ": 제일은행" << std::endl;
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 9;
				i++;
				k++;

				if (numSP_re[4] == 1 && numSP_re[15] == 1)
				{
					classify << k << ": 수협은행" << std::endl;
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 5;
					inBK_re[i][2] = 7;
					inBK_re[i][3] = 9;
					inBK_re[i][4] = 16;
					i++;
					k++;
				}
				else if (numSP_re[10] == 1 && numSP_re[15] == 1)
				{
					classify << k << ": 부산은행" << std::endl;
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 7;
					inBK_re[i][2] = 9;
					inBK_re[i][3] = 11;
					inBK_re[i][4] = 16;
					i++;
					k++;
				}
			}

			if (numSP_re[15] == 1)
			{
				classify << k << ": 신한은행" << std::endl;
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 16;
				i++;
				k++;
			}
		}
		else if (numSP_re[15] == 1)
		{
			if (numSP_re[7] == 1)
			{
				classify << k << ": 농협" << std::endl;
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 8;
				inBK_re[i][3] = 16;
				i++;
				k++;
			}
		}
	}

	if (numSP_re[16] == 1)
	{
		if (numSP_re[1] == 1)
		{
			classify << k << ": 국민은행" << std::endl;
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 17;
			i++;
			k++;

			if (numSP_re[15] == 1)
			{
				if (numSP_re[8] == 1)
				{
					classify << k << ": 씨티은행" << std::endl;
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 9;
					inBK_re[i][2] = 16;
					inBK_re[i][3] = 17;
					i++;
					k++;
				}
				if (numSP_re[5] == 1 && numSP_re[10] == 1)
				{
					classify << k << ": 대구은행" << std::endl;
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 6;
					inBK_re[i][2] = 11;
					inBK_re[i][3] = 16;
					inBK_re[i][4] = 17;
					i++;
					k++;
				}
			}
		}
		else if (numSP_re[8] == 1)
		{
			if (numSP_re[12] == 1)
			{
				classify << k << ": 경남은행" << std::endl;
				inBK_re[i][0] = 9;
				inBK_re[i][1] = 13;
				inBK_re[i][2] = 17;
				i++;
				k++;
				if (numSP_re[15] == 1)
				{
					classify << k << ": 기업은행" << std::endl;
					inBK_re[i][0] = 9;
					inBK_re[i][1] = 13;
					inBK_re[i][2] = 16;
					inBK_re[i][3] = 17;
					i++;
					k++;
				}
			}
			else if (numSP_re[15] == 1)
			{
				classify << k << ": 하나은행" << std::endl;
				inBK_re[i][0] = 9;
				inBK_re[i][1] = 16;
				inBK_re[i][2] = 17;
				i++;
				k++;
			}
		}
	}

	if (numSP_re[1] == 1 && numSP_re[8] == 1)
	{
		if (numSP_re[11] == 1 && numSP_re[14] == 1)
		{
			classify << k << ": 케이은행" << std::endl;
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 9;
			inBK_re[i][2] = 12;
			inBK_re[i][3] = 15;
		}
	}

	if (i == 0)
	{
		classify << "현재 존재하는 기관이 없습니다." << std::endl;
		return 0;
	}

	classify.close();
	return 1;
}

#endif
