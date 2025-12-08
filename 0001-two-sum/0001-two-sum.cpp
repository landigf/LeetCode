class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res(2);
        for(int i = 0; i < nums.size(); ++i){
            if (m.contains(nums[i])){
                res[0] = m[nums[i]];
                res[1] = i;
                return res;
            };
            m[target-nums[i]] = i;
        }
        return res;
    }
};