class Solution {
public:
    bool checkValid(int i, int j,int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        bool checkgood = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    checkgood = true;
                }
            }
        }
        if(!checkgood){
            return 0;
        }
        int level = 0;
        bool flag;
        while(!q.empty()){
            int sz = q.size();
            flag = false;
            for(int i=0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                // i , j-1
                if(checkValid(p.first, p.second-1,n,m) && grid[p.first][p.second-1]==1){
                    grid[p.first][p.second-1] = 2;
                    q.push(make_pair(p.first, p.second-1));
                    flag = true;
                }
                // i , j+1
                if(checkValid(p.first, p.second+1,n,m) && grid[p.first][p.second+1]==1){
                    grid[p.first][p.second+1] = 2;
                    q.push(make_pair(p.first, p.second+1));
                    flag = true;
                }
                // i-1 , j
                if(checkValid(p.first-1, p.second,n,m) && grid[p.first-1][p.second]==1){
                    grid[p.first-1][p.second] = 2;
                    q.push(make_pair(p.first-1, p.second));
                    flag = true;
                }
                // i+1 , j
                if(checkValid(p.first+1, p.second,n,m) && grid[p.first+1][p.second]==1){
                    grid[p.first+1][p.second] = 2;
                    q.push(make_pair(p.first+1, p.second));
                    flag = true;
                }
            }
            if(flag){
               level++; 
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return level;
    }
};