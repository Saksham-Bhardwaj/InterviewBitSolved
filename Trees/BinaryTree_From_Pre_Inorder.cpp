//Construct Binary Tree From Inorder And Preorder
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* constructBT(vector<int> &in, vector<int> &pre, int start, int end, int &pInd ,unordered_map<int, int>& mp){
    if(start>end){
        return NULL;
    }
    
    TreeNode* node = new TreeNode(pre[pInd++]);
    if(start==end){
        return node;
    }
    int ind = mp[node->val];
    node->left = constructBT(in,pre,start,ind-1,pInd,mp);
    node->right = constructBT(in,pre,ind+1,end,pInd,mp);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int pInd = 0;
    
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[B[i]]= i;
    }
    TreeNode* root = constructBT(B,A,0,n-1,pInd,mp);
    return root;
}
