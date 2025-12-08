class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for(char c='A';c<='Z';++c)
        {
            int a, b;
            int d = 0;
            for(a=0, b=0; b < s.size(); ++b)
            {
                if(s[b] != c) ++d;

                while(d > k)
                {
                    if(s[a] != c) --d;
                    ++a;
                }

                res = max(res, b-a+1);
            }
        }
        return res;
    }
};