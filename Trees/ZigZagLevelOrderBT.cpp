//ZIGZAG LEVEL ORDER TRAVERSAL BT

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> levelOrderZigZag(TreeNode* root){
    vector<vector<int>> res;
    if(root==NULL){
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    int i =0; // for direction
    q.push(NULL);
    vector<int> level;
    while(q.empty()==0 && !(q.size()==1 && q.front()==NULL))
    {
        TreeNode* node = q.front();
        q.pop();
        if(node==NULL){
            q.push(NULL);
            if(i%2!=0){
                reverse(level.begin(),level.end());
            }
            res.push_back(level);
            level.erase(level.begin(),level.end());
            i++;
        }else{
            level.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    if(i%2!=0){
        reverse(level.begin(),level.end());
    }
    res.push_back(level);
    return res;
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    return levelOrderZigZag(A);
}
