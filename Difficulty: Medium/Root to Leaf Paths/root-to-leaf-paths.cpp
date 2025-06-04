/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  bool preorder(Node* root ,vector<int>&ans, vector<vector<int>>&res){
      if(root == nullptr) return true;
       ans.push_back(root->data);
       bool lh =preorder(root->left,ans,res);
       bool rh = preorder(root->right,ans,res);
       if(lh == true && rh == true){
           res.push_back(ans);
           ans.pop_back();
           return false;
       }
       ans.pop_back();
       return false;
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>res;
        vector<int>ans;
        preorder(root,ans,res);
        return res ;
        
    }
};