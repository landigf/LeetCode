class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0,1);
        int maksSize = 1;
        vector<vector<bool>> memo(s.length(), vector<bool> (s.length(), false));
        for(int i = 0; i < s.length(); ++i){
            memo[0][i] = true;
            if(i+1!=s.length()){
                if(s[i] == s[i+1]) {
                    memo[1][i] = true;
                    if(maksSize != 2) res = s.substr(i,2);
                    maksSize = 2;
                }
            }
        }
        for(int size = 2; size < s.length(); ++size){
            for(int start = 0; start < s.length()-size; ++start){
                //cout << s[start] << "->" <<s[start+size]<<", size: "<<size<<"\n";
                if(s[start] == s[start+size] && memo[size-2][start+1]){
                    memo[size][start] = true;
                    //cout << "true\n";
                    if(size+1 > maksSize){
                        maksSize = size;
                        res = s.substr(start,size+1);
                    }
                }
            }
        }
        return res;
    }
};