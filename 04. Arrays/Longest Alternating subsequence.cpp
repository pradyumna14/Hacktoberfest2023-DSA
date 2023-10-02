#include <iostream>
#include <vector>

using namespace std;

int longestAlternatingSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
        return n;
    }

    int up = 1;  // Length of the longest alternating subsequence ending with an 'up' element
    int down = 1;  // Length of the longest alternating subsequence ending with a 'down' element

    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }

    return max(up, down);
}

int main() {
    vector<int> nums = {1, 5, 4};
    int result = longestAlternatingSubsequence(nums);
    cout << "Length of the longest alternating subsequence: " << result << endl;
    return 0;
}
