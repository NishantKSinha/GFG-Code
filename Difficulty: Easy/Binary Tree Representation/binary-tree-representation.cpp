// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
  public:

    void create_tree(node* root0, vector<int>& vec) {
        // Your code goes here
        if (vec.size() <= 1) return; // Only root exists

          queue<node*> q;
          q.push(root0);

    int i = 1; // Start from second element in vec
    while (!q.empty() && i < vec.size()) {
        node* curr = q.front();
        q.pop();

        // Assign left child
        if (i < vec.size()) {
        curr->left = newNode(vec[i++]);
        q.push(curr->left);
        }

        // Assign right child if available
        if (i < vec.size()) {
            curr->right = newNode(vec[i++]);
            q.push(curr->right);
        }
    }
    }
};