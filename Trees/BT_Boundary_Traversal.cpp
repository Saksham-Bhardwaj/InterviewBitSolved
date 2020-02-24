/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void leftBound(TreeNode* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(root->left){
        res.push_back(root->val);
        return leftBound(root->left, res);
    }
    if(root->right){
        res.push_back(root->val);
        return leftBound(root->right, res);
    }
}
void rightBound(TreeNode* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(root->right){
        res.push_back(root->val);
        return rightBound(root->right, res);
    }
    if(root->left){
        res.push_back(root->val);
        return rightBound(root->left, res);
    }
    
}

void leavesBound(TreeNode* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(!root->right && !root->left){
        res.push_back(root->val);
    }
    leavesBound(root->left,res);
    leavesBound(root->right,res);
    
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> res,right;
    if(A==NULL){
        return res;
    }
    
    if(!A->left && !A->right){
        res.push_back(A->val);
        return res;
    }
    res.push_back(A->val);
    leftBound(A->left,res);
    leavesBound(A,res);
    int i = res.size();  // to store where right boundry will start for reversal
    rightBound(A->right,res);
    reverse(res.begin()+i,res.end());  // we need right boundry in bottom up manner
    return res;
    
}
