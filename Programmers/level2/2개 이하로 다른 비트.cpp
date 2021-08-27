#include "bits/stdc++.h"
using namespace std;
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); ++i) {
        long long n = numbers[i];
        bitset b = bitset<50>(n);

        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == 0) {
                if (i == 0) {
                    b[i] = 1;
                }
                else {
                    b[i] = 1;
                    b[i - 1] = 0;
                }
                break;
            }
        }
        answer.push_back(b.to_ulong());
    }
    return answer;
}