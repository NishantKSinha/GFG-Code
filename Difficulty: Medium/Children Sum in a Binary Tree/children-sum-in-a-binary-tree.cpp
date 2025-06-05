/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Add your code here
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
             int size = q.size();
            q.pop();
             // Skip leaf nodes
        if (!temp->left && !temp->right)  continue;
            int resultant = temp->data; 
            int sum = 0;
                if(temp->left){
                    q.push(temp->left);
                    sum = sum+temp->left->data;
                }
                if(temp->right){
                    q.push(temp->right);
                    sum = sum+temp->right->data;
                }
            
            if( sum != resultant) return 0;
        }
        return 1;
    }
};