class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> prefix(n+1,0);

        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+(s[i-1]-'0');
        }
        int zeros=0;

        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            int l=i+1;
            int r=n;

            int ones=prefix[r]-prefix[l];
            ans=max(ans,ones+zeros);

        }

        return ans;
    }
};