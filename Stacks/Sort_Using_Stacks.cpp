vector<int> Solution::solve(vector<int> &A) {
    stack<int> s1 ,s2;
    vector<int> res;
    for(int i=0;i<A.size();i++){
        s1.push(A[i]);
    }
    
    int n = s1.size();
    
    while(!s1.empty()){
        if(s2.empty()){
            s2.push(s1.top());
            s1.pop();
            
        }
        while(!s1.empty() && s1.top()<s2.top()){
            s2.push(s1.top());
            s1.pop();
        }
        if(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            while(!s2.empty() && s2.top()<temp){
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(temp);
        }
    }
    while(!s2.empty()){
        res.push_back(s2.top());
        s2.pop();
    }
    return res;
}
