class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> idx(numRows);
        int cap = numRows*2 - 2;
        for(int i = 0; i < s.size(); ++i){
            int curr = i%cap;
            cout << s[i] <<" - "<< curr<<"\n";
            if(curr < numRows) idx[curr] += s[i];
            else idx[2*numRows - curr - 2] += s[i];
        }

        string res = idx[0];
        for(int i = 1; i < numRows; ++i){
            res += idx[i];
        }
        return res;
    }
};