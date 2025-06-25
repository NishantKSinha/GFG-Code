/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Nodeval {
    public:
        int maxval,minval,maxsize;
        Nodeval(int maxval,int minval,int maxsize){
            this->maxval = maxval;
            this->minval = minval;
            this->maxsize = maxsize;
        }
};
class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Nodeval post(Node* root ){
        
        if(root == NULL )return Nodeval(INT_MIN,INT_MAX,0);
        
        Nodeval left = post(root->left);
        Nodeval right = post(root->right);
        
        if(left.maxval < root->data && right.minval > root->data){
            return Nodeval(max(right.maxval,root->data),min(left.minval,root->data),
                           left.maxsize+right.maxsize+1);
        }
          return Nodeval(INT_MAX,INT_MIN,max(left.maxsize,right.maxsize));
    }
    int largestBst(Node *root) {
        // Your code here
       return post(root).maxsize;
    }
};