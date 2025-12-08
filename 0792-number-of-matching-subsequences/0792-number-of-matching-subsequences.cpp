class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> charToIdx;
        for(int i = 0; i < s.size(); ++i){
            charToIdx[s[i]].push_back(i);
        }
        int res = 0;
        for(string word: words){
            int lastIdxInS = -1;
            bool matched = true;
            for(char c: word){
                if(charToIdx.find(c) == charToIdx.end()) {
                    matched = false;
                    continue;
                }
                if(lastIdxInS == -1){
                    lastIdxInS = charToIdx[c][0]+1;
                    continue;
                }
                // find an index higher than lastIdxInS that matches
                auto it = lower_bound(charToIdx[c].begin(), charToIdx[c].end(), lastIdxInS);
                if(it == charToIdx[c].end()) {
                    matched = false;
                    continue;
                }
                lastIdxInS = *it + 1;
            }
            if(matched) ++res;
        }
        return res;
    }
};