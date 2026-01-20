class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string res = dominoes;
        int lastL = -1, lastR = -1;
        for(int i = 0; i < n; ++i){
            if(dominoes[i] == '.') {
                if(lastR != -1) res[i] = 'R';
            }
            else if(dominoes[i] == 'L'){
                if(lastR != -1){
                    if((i-lastR+1) % 2) res[(lastR+i)/2] = '.';
                    for(int j = i; j > (lastR+i)/2; --j) res[j] = 'L';
                } else {
                    for(int j = i; j > lastL; --j) res[j] = 'L';
                }
                lastL = i;
                lastR = -1;
            } else {
                lastR = i;
            }
        }
        return res;
    }
};