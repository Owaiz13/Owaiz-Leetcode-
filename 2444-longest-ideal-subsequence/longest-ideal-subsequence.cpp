class Solution {
private:
    int dp[100000][27];
    int f(int idx,int prevChar,string &s,int k) {
        // base cases
        if(idx < 0) return 0;
        if(dp[idx][prevChar] != -1) return dp[idx][prevChar];

        char ch = prevChar + 'a';
        int take = 0;
        if(prevChar == 26 or abs(ch-s[idx]) <= k) take = 1 + f(idx-1,s[idx]-'a',s,k);
        int notTake = f(idx-1,prevChar,s,k);

        return dp[idx][prevChar] = max(take,notTake);
    }
public:
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return f(n-1,26,s,k);
    }
};