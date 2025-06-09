/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

Node* find(Node* root , int input, Node* &ans) {
    if (root == NULL) return NULL;

    if (root->data == input) {
        ans = root;
        return root;
    }

    Node* lh = NULL;
    Node* rh = NULL;

    if (root->data > input) {
        ans = root;
        if (root->left)
            lh = find(root->left, input, ans);
        else
            return ans;
    } else if (root->data < input) {
        if (root->right)
            rh = find(root->right, input, ans);
        else
            return NULL;
    }

    if (rh != NULL && lh == NULL) ans = rh;
    if (rh == NULL && lh != NULL) ans = lh;

    return ans;
}

int findCeil(Node* root, int input) {
    Node* ans = NULL;
    find(root, input, ans);
    return ans ? ans->data : -1;
}
