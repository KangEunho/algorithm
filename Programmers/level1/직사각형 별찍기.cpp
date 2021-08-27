#include <iostream>

using namespace std;

int main(void) {
	int a;
	int b;
	cin >> a >> b;
	for (int i = 0; i < b; ++i)
	{
		string s(a, '*');
		cout << s << endl;
	}
	return 0;
}