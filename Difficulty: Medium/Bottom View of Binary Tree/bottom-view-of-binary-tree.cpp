// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
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
    ans.push_back(std::prev(i.second.end())->second.back());
}
        return ans;
    }
};