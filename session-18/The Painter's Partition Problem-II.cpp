#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
class Solution {
public:

    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long curr = 0;
        int painters = 1;

        for (int len : arr) {
            if (curr + len <= maxTime) {
                curr += len;
            } else {
                painters++;
                curr = len;
            }
        }

        return painters <= k;
    }

    long long minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
