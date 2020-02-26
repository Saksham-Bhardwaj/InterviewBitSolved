bool validMove(int i, int j , int n , int m){
    return (i>=0 && j>=0 && i<n && j<m );
}

void DFS(vector<vector<char>> &Ar, int i, int j){
    Ar[i][j] = 'Y';
    if(validMove(i-1,j,Ar.size(),Ar[0].size()) && Ar[i-1][j]=='O'){
        DFS(Ar,i-1,j);
    }
    if(validMove(i,j-1,Ar.size(),Ar[0].size()) && Ar[i][j-1]=='O'){
        DFS(Ar,i,j-1);
    }
    if(validMove(i+1,j,Ar.size(),Ar[0].size()) && Ar[i+1][j]=='O'){
        DFS(Ar,i+1,j);
    }
    if(validMove(i,j+1,Ar.size(),Ar[0].size()) && Ar[i][j+1]=='O'){
        DFS(Ar,i,j+1);
    }
}


void Solution::solve(vector<vector<char> > &A) {
    int n , m;
    n = A.size();
    if(n==0){
        return;
    }
    m = A[0].size();
    
    for(int i=0;i<m;i++){
        if(A[0][i]=='O'){
            DFS(A,0,i);
        }
    }
    for(int i=0;i<m;i++){
        if(A[n-1][i]=='O'){
            DFS(A,n-1,i);
        }
    }
    
    for(int i=0;i<n;i++){
        if(A[i][0]=='O'){
            DFS(A,i,0);
        }
    }
    for(int i=0;i<n;i++){
        if(A[i][m-1]=='O'){
            DFS(A,i,m-1);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O'){
                A[i][j]= 'X';
            }
            else if(A[i][j]=='Y'){
                A[i][j]= 'O';
            }
        }
    }
    
    
}
