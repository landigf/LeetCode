class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> counter;
        for(char c: s){
            ++counter[c];
        }
        int res = 0;
        bool oneOdd = false;
        for(auto pair: counter){
            char c = pair.first;
            int count = pair.second;
            res += count/2;
            if(count%2) oneOdd = true;
        }
        return (oneOdd) ? res*2+1 : res*2;
    }
};