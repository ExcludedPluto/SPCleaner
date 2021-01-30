#include <string>
#include <vector>

using namespace std;
#ifndef __classify_H__
#define __classify_H__

class classify
{
private:
	char ThereBK[17][9];
	int *numSP_re;
	int (*inBK_re)[5];
	vector<string>& classifiedBK;
public:
	classify(int *numSP_re_m, int(*inBK_re_m)[5], vector<string>& classifiedBK);
	bool checkBK();
};
classify::classify(int *numSP_re_m, int(*inBK_re_m)[5], vector<string>& classifiedBK_m) : classifiedBK(classifiedBK_m)
{
	numSP_re = numSP_re_m;
	inBK_re = inBK_re_m;
}
bool classify::checkBK()
{
	int i = 0;

	if (numSP_re[3] == 1)
	{
		if (numSP_re[1] == 1)
		{
			classifiedBK.push_back(std::to_string(i + 1) + " : 산업은행");
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 4;
			i++;
		}
		if (numSP_re[12] == 1)
		{
			if (numSP_re[1] == 1 && numSP_re[13] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 우리은행");
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 4;
				inBK_re[i][2] = 13;
				inBK_re[i][3] = 14;
				i++;
			}
			if (numSP_re[8] == 1 && numSP_re[15] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 전북은행");
				inBK_re[i][0] = 4;
				inBK_re[i][1] = 9;
				inBK_re[i][2] = 13;
				inBK_re[i][3] = 16;
				i++;
			}
		}
	}

	if (numSP_re[6] == 1)
	{
		classifiedBK.push_back(std::to_string(i + 1) + " : 제주은행");
		inBK_re[i][0] = 7;
		i++;

		if (numSP_re[2] == 1)
		{
			classifiedBK.push_back(std::to_string(i + 1) + " : 광주은행");
			inBK_re[i][0] = 3;
			inBK_re[i][1] = 7;
			i++;
		}

		if (numSP_re[1] == 1)
		{
			if (numSP_re[8] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 제일은행");
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 9;
				i++;

				if (numSP_re[4] == 1 && numSP_re[15] == 1)
				{
					classifiedBK.push_back(std::to_string(i + 1) + " : 수협은행");
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 5;
					inBK_re[i][2] = 7;
					inBK_re[i][3] = 9;
					inBK_re[i][4] = 16;
					i++;
				}
				else if (numSP_re[10] == 1 && numSP_re[15] == 1)
				{
					classifiedBK.push_back(std::to_string(i + 1) + " : 부산은행");
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 7;
					inBK_re[i][2] = 9;
					inBK_re[i][3] = 11;
					inBK_re[i][4] = 16;
					i++;
				}
			}

			if (numSP_re[15] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 신한은행");
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 16;
				i++;
			}
		}
		else if (numSP_re[15] == 1)
		{
			if (numSP_re[7] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 농협");
				inBK_re[i][0] = 2;
				inBK_re[i][1] = 7;
				inBK_re[i][2] = 8;
				inBK_re[i][3] = 16;
				i++;
			}
		}
	}

	if (numSP_re[16] == 1)
	{
		if (numSP_re[1] == 1)
		{
			classifiedBK.push_back(std::to_string(i + 1) + " : 국민은행");
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 17;
			i++;

			if (numSP_re[15] == 1)
			{
				if (numSP_re[8] == 1)
				{
					classifiedBK.push_back(std::to_string(i + 1) + " : 씨티은행");
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 9;
					inBK_re[i][2] = 16;
					inBK_re[i][3] = 17;
					i++;
				}
				if (numSP_re[5] == 1 && numSP_re[10] == 1)
				{
					classifiedBK.push_back(std::to_string(i + 1) + " : 대구은행");
					inBK_re[i][0] = 2;
					inBK_re[i][1] = 6;
					inBK_re[i][2] = 11;
					inBK_re[i][3] = 16;
					inBK_re[i][4] = 17;
					i++;
				}
			}
		}
		else if (numSP_re[8] == 1)
		{
			if (numSP_re[12] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 경남은행");
				inBK_re[i][0] = 9;
				inBK_re[i][1] = 13;
				inBK_re[i][2] = 17;
				i++;
				if (numSP_re[15] == 1)
				{
					classifiedBK.push_back(std::to_string(i + 1) + " : 기업은행");
					inBK_re[i][0] = 9;
					inBK_re[i][1] = 13;
					inBK_re[i][2] = 16;
					inBK_re[i][3] = 17;
					i++;
				}
			}
			else if (numSP_re[15] == 1)
			{
				classifiedBK.push_back(std::to_string(i + 1) + " : 하나은행");
				inBK_re[i][0] = 9;
				inBK_re[i][1] = 16;
				inBK_re[i][2] = 17;
				i++;
			}
		}
	}

	if (numSP_re[1] == 1 && numSP_re[8] == 1)
	{
		if (numSP_re[11] == 1 && numSP_re[14] == 1)
		{
			classifiedBK.push_back(std::to_string(i + 1) + " : 케이은행");
			inBK_re[i][0] = 2;
			inBK_re[i][1] = 9;
			inBK_re[i][2] = 12;
			inBK_re[i][3] = 15;
		}
	}

	if (i == 0)
	{
		classifiedBK.push_back("현재 존재하는 기관이 없습니다.\n");
		return false;
	}
	return true;
}

#endif
