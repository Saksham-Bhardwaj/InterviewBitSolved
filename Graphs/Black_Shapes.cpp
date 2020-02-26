bool isValid(int i, int j , int n , int m){
    return (i>=0 && j>=0 && i<n && j<m);
}

void DFS(vector<string> &A , int i, int j){
    A[i][j]= 'O';
    if(isValid(i,j-1, A.size(),A[0].size()) && A[i][j-1]=='X'){
        DFS(A,i,j-1);
    }
    if(isValid(i,j+1, A.size(),A[0].size()) && A[i][j+1]=='X'){
        DFS(A,i,j+1);
    }
    if(isValid(i-1,j, A.size(),A[0].size()) && A[i-1][j]=='X'){
        DFS(A,i-1,j);
    }
    if(isValid(i+1,j, A.size(),A[0].size()) && A[i+1][j]=='X'){
        DFS(A,i+1,j);
    }
    return;
}


int Solution::black(vector<string> &A) {
    int count = 0;
    int n = A.size();
    if(n==0){
        return count;
    }
    int m = A[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='X'){
                count++;
                DFS(A,i,j);
            }
        }
    }
    return count;
}
