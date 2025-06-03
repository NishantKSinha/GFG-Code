/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int,map<int,vector<int>>>mpp;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            Node *temp = p.first;
            int vert = p.second.first, lev = p.second.second;
            mpp[vert][lev].push_back(temp->data);
            q.pop();
            if(temp->left) q.push({temp->left,{vert-1,lev+1}});
            if(temp->right) q.push({temp->right,{vert+1,lev+1}});
        }
       for (auto& i : mpp) {
    auto& j = *i.second.begin(); // topmost level for vertical
    ans.push_back(j.second[0]);  // first node at that level
}
        return ans;
    }
};