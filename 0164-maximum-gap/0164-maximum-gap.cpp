#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        auto [lo_it, hi_it] = minmax_element(nums.begin(), nums.end());
        int lo = *lo_it;
        int hi = *hi_it;
        if (lo == hi) return 0;

        int bucketSize  = max(1, (hi - lo) / (n - 1));
        int bucketCount = (hi - lo) / bucketSize + 1;

        vector<int> bmin(bucketCount, INT_MAX);
        vector<int> bmax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int x : nums) {
            int idx = (x - lo) / bucketSize;
            used[idx] = true;
            bmin[idx] = min(bmin[idx], x);
            bmax[idx] = max(bmax[idx], x);
        }

        int ans = 0;
        int prevMax = lo;

        for (int i = 0; i < bucketCount; ++i) {
            if (!used[i]) continue;
            ans = max(ans, bmin[i] - prevMax);
            prevMax = bmax[i];
        }

        return ans;
    }
};
