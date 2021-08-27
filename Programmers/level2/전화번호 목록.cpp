#include <string>
#include <vector>

using namespace std;
bool compare(string& str1, string& str2)
{
	const int length = min(str1.length(), str2.length());
	for (int ii = 0; ii < length; ++ii)
	{
		if (str1[ii] != str2[ii])
		{
			return false;
		}
	}

	return true;
}
bool solution(vector<string> phone_book) {

	bool answer = true;
	int size = phone_book.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (compare(phone_book[i], phone_book[j]))
			{
				return false;
			}
		}
	}

	return true;
}