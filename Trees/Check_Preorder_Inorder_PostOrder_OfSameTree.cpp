
//Check if given Preorder, Inorder and Postorder traversals are of same tree

int searchInd(vector<int> &inOrd,int start, int end ,int val)
{
    for(int i=start;i<=end;i++){
        if(inOrd[i]==val){
            return i;
        }
    }
    return -1;
}

TreeNode* constructBT(vector<int> &inOrd, vector<int> &postOrd , int start, int end, int& postInd){
    if(start>end){
        return NULL;
    }
    
    TreeNode* node = new TreeNode(postOrd[postInd--]);
    if(start==end){
        return node;
    }
    int index = searchInd(inOrd,start,end,node->val);
    if(index==-1){
        return NULL;
    }
    node->right = constructBT(inOrd,postOrd,index+1,end,postInd);
    node->left = constructBT(inOrd,postOrd,start,index-1,postInd);
    return node;
    
} 
void preOrd(TreeNode* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    res.push_back(root->val);
    preOrd(root->left,res);
    preOrd(root->right,res);
    return;
}

bool compPre(vector<int> &pre, vector<int> &preT){
    for(int i=0;i<pre.size();i++){
        if(preT[i]!=pre[i]){
            return false;
        }
    }
    return true;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    if(A.size()!=B.size() && B.size()!=C.size()){
        return 0;
    }
    int p = B.size()-1;
    TreeNode* root =constructBT(B,C,0,B.size()-1,p);
    vector<int> pre;
    preOrd(root,pre);
    if(compPre(pre,A)){
        return 1;
    }
    return 0;
    
}
