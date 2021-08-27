#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<long long> num;
	vector<char> oper;
	set<char> used_oper;

	int j = 0;
	for (int i = 0; i < expression.size(); ++i)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			num.push_back(stoi(expression.substr(j, i - j)));
			used_oper.insert(expression[i]);
			oper.push_back(expression[i]);
			j = i + 1;
		}
	}
	num.push_back(stoi(expression.substr(j, expression.size() - j)));
	vector<char> v_used_oper(used_oper.begin(), used_oper.end());
	sort(v_used_oper.begin(), v_used_oper.end());

	do
	{
		vector<long long> tempNum(num);
		vector<char> tempOper(oper);
		for (int i = 0; i < v_used_oper.size(); ++i)
		{
			for (int j = 0; j < tempOper.size();)
			{
				if (tempOper[j] == v_used_oper[i])
				{
					if (tempOper[j] == '+')
						tempNum[j] += tempNum[j + 1];
					else if (tempOper[j] == '-')
						tempNum[j] -= tempNum[j + 1];
					else if (tempOper[j] == '*')
						tempNum[j] *= tempNum[j + 1];

					tempNum.erase(tempNum.begin() + j + 1);
					tempOper.erase(tempOper.begin() + j);
				}
				else ++j;
			}
		}
		answer = max(answer, abs(tempNum[0]));
	} while (next_permutation(v_used_oper.begin(), v_used_oper.end()));

	return answer;
}