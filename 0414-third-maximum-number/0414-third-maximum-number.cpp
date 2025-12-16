class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(), greater<int>());
        if(nums.size() <= 2) return nums[0];
        int unique = 1;
        int i;
        for(i = 1; i < nums.size() && unique != 3; ++i){
            if(nums[i] != nums[i-1]) ++unique;
        }
        return (unique == 3) ? nums[i-1] : nums[0];
    }
};