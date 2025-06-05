/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   void find(Node* root, unordered_map<Node*,Node*>&mpp){
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           Node* temp = q.front();
           q.pop();
           if(temp->left){
               mpp[temp->left] = temp;
               q.push(temp->left);
           }
           if(temp->right){
               mpp[temp->right] = temp;
               q.push(temp->right);
           }
       }
   }
   void find1(Node* root , int target, Node* &target1){
       if(root == NULL) return;
       if(root->data == target){
         target1 =root;
         return;
       } 
       
       find1(root->left,target,target1);
       find1(root->right,target,target1);
   }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>mpp;
        find(root,mpp);
        Node* target1 ;;
        find1(root,target,target1);;
        
        queue<Node*>q;
        q.push(target1);
        int time =0;
        unordered_map<Node*,bool>visited;
        visited[q.front()] = true;
        while(!q.empty()){
            time++;
            int size = q.size();
            while(size != 0){
                Node* temp = q.front();
                q.pop();
                if((temp->left) && visited.find(temp->left) == visited.end()){
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if((temp->left) && visited.find(temp->left) == visited.end()){
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if((temp->right) && visited.find(temp->right) == visited.end()){
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if((mpp[temp]) && visited.find(mpp[temp]) == visited.end()){
                    visited[mpp[temp]] = true;
                    q.push(mpp[temp]);
                }
                size--;
            }
        }
        
        return time-1;
    }
};