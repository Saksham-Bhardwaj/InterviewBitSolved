#define ll long long int
#define pb push_back

bool myComp(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        if(a[1]==b[1]){
            if(a[2]==b[2]){
                return a[3]<b[3];
            }else{
                return a[2]<b[2];
            }
        }else{
            return a[1]<b[1];
        }
    }else{
        return a[0]<b[0];
    }
}

vector<int> Solution::equal(vector<int> &A) {
    ll sum1=0,sum2=0;
    int n = A.size();
    vector<int> ans;
    if(n==0){
        return ans;
    }
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = A[i]+A[j];
            if(mp.find(sum)!=mp.end()){
                if(mp[sum].second!=i && mp[sum].first!=i && mp[sum].second<j){
                    vector<int> res;
                    res.pb(mp[sum].first);
                    res.pb(mp[sum].second);
                    res.pb(i);
                    res.pb(j);
                    if(ans.size()==0){
                        ans = res;
                    }else{
                        if(!myComp(ans,res)){
                            ans = res;
                        }
                    }
                }
            }else{
                mp[sum]= make_pair(i,j);
            }
        }
    }
    return ans;
}
