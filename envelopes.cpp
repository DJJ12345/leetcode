class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if ( !envelopes.size()) return 0;
        int res = 1;
        vector<int> ans(envelopes.size(),1);
        sort (envelopes.begin(),envelopes.end(),cmp);
        for (int i = 1; i < envelopes.size(); i++){
            for (int j = 0; j < i; j++)
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    ans[i] = max(ans[i],ans[j]+1);
                }
             res=max(res,ans[i]);
        }
        return res;
    }
static bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
        if (a.first < b.first) return 1;
        else if (a.first > b.first ) return 0;
        else {
            if (a.second < b.second ) return 1;
            else return 0;
        }
    }
};
