class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<n+1;i++){
            char ch1=words[i-1][0];
            char ch2=words[i-1][words[i-1].size()-1];
            if((ch1=='a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u') && (ch2=='a' || ch2=='e' || ch2=='i' || ch2=='o' || ch2=='u')){
                prefix[i]=prefix[i-1]+1;
            }else{
                prefix[i]=prefix[i-1]+0;
            }
        }

        int m=queries.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int res=prefix[r+1]-prefix[l];
            ans.push_back(res);
        }

        return ans;
    }
};