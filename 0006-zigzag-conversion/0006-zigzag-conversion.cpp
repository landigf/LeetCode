class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> idx(numRows);
        int cap = numRows*2 - 2;
        for(int i = 0; i < s.size(); ++i){
            int curr = i%cap;
            if(curr < numRows) idx[curr] += s[i];
            else idx[cap - curr] += s[i];
        }

        string res = idx[0];
        for(int i = 1; i < numRows; ++i){
            res += idx[i];
        }
        return res;
    }
};