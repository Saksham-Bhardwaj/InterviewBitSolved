//BALANCED BINARY TREE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int heightOfTree(TreeNode* root, bool &res ){
    if(root==NULL){
        return 1;
    }
    int lh = heightOfTree(root->left,res)+1;
    int rh = heightOfTree(root->right,res)+1;
    if(abs(lh-rh)>1){
        res = false;
    }
    return max(lh,rh);
}

int Solution::isBalanced(TreeNode *root){
    bool res = true;
    heightOfTree(root,res);
    if(res){
        return 1;
    }
    return 0;
}
