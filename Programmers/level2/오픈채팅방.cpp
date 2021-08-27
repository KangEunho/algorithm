#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> map;
	for (int i = 0; i < record.size(); ++i)
	{
		stringstream ss(record[i]);
		string str = record[i];
		vector<string> message;
		while (ss >> str)
		{
			message.push_back(str);
		}
		if (message[0] == "Enter" || message[0] == "Change")
			map[message[1]] = message[2];
	}

	for (int i = 0; i < record.size(); ++i)
	{
		stringstream ss(record[i]);
		string str = record[i];
		vector<string> message;
		while (ss >> str)
		{
			message.push_back(str);
		}
		if (message[0] == "Enter")
			answer.push_back(map[message[1]] + "님이 들어왔습니다.");
		else if (message[0] == "Leave")
			answer.push_back(map[message[1]] + "님이 나갔습니다.");
	}
	return answer;
}