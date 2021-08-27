#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	phone_number.replace(phone_number.begin(), phone_number.end() - 4, string(phone_number.length() - 4, '*'));
	return phone_number;
}