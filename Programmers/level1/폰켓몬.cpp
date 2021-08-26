#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> set;
    const int size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        set.insert(nums[i]);
    }
    return min(size / 2, (int)set.size());
}