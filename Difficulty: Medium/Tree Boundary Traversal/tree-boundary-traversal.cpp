/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   void left(Node* root , vector<int>& ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return; // don't include leaves
    ans.push_back(root->data);
    if(root->left)
        left(root->left, ans);
    else
        left(root->right, ans); // handle cases where left is NULL but right exists
}
    void leaf(Node* root , vector<int>&ans){
        if(root == nullptr) return ;
        leaf(root->left,ans);
        leaf(root->right,ans);
          if(root->left == nullptr && root->right == nullptr) ans.push_back(root->data);
        
    }
    void right(Node* root , vector<int>& ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return; // don't include leaves
    if(root->right)
        right(root->right, ans);
    else
        right(root->left, ans); // handle cases where right is NULL but left exists
    ans.push_back(root->data); // add after recursion to reverse the order
}
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
       if(!(root->left == NULL && root->right == NULL))  ans.push_back(root->data); //only push root if it's not a leaf
        left(root->left,ans);
        leaf(root,ans);
        right(root->right,ans);
        return ans;
    }
};