#include <string>
#include <vector>

using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> left = { 0,3 };
	pair<int, int> right = { 2,3 };
	pair<int, int> numIndex[10];
	numIndex[0] = { 1, 3 };
	numIndex[1] = { 0, 0 };
	numIndex[2] = { 1, 0 };
	numIndex[3] = { 2, 0 };
	numIndex[4] = { 0, 1 };
	numIndex[5] = { 1, 1 };
	numIndex[6] = { 2, 1 };
	numIndex[7] = { 0, 2 };
	numIndex[8] = { 1, 2 };
	numIndex[9] = { 2, 2 };

	pair<int, int>* leftOrRight;
	for (int number : numbers)
	{
		if (number == 1 || number == 4 || number == 7)
			leftOrRight = &left;
		else if (number == 3 || number == 6 || number == 9)
			leftOrRight = &right;
		else
		{
			int leftDist = dist(left, numIndex[number]);
			int rightDist = dist(right, numIndex[number]);
			if (leftDist < rightDist)
				leftOrRight = &left;
			else if (leftDist > rightDist)
				leftOrRight = &right;
			else
				leftOrRight = hand == "left" ? &left : &right;
		}

		*leftOrRight = numIndex[number];
		answer.push_back(leftOrRight == &left ? 'L' : 'R');
	}
	return answer;
}