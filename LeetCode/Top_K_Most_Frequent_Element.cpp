//https://leetcode.com/problems/top-k-frequent-elements/

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> ump;
    for(int i=0;i<nums.size();i++){
        ump[nums[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    for(auto i=ump.begin();i!=ump.end();++i){
        pq.push({(*i).second,(*i).first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> res;
    while(pq.size()>0){
        pair<int,int> p = pq.top();
        pq.pop();
        res.push_back(p.second);
    }
    return res;
}