/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int ans=0;

   pair<int,int>s(struct TreeNode *root)
   {
      if(root==NULL)
      return {0,0};

     pair<int,int>x=s(root->left);
     pair<int,int>y=s(root->right);

     int sum=root->val+x.first+y.first;
     int c=1+x.second+y.second;

     if(root->val==sum/c)
     {
        ans++;
     }

return {sum,c};


   }


    int averageOfSubtree(TreeNode* root) {

   
     s(root);
     return ans;



        
    }
};