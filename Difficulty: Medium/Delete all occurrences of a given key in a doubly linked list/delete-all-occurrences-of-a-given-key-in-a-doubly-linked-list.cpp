//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends

// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        struct Node* temp = *head_ref;
        struct Node* forward = temp->next;
        
        if((*head_ref)->next == NULL&& (*head_ref)->data == x ) {
            delete *head_ref;
        *head_ref = NULL;
        return;
        }
        while(forward != NULL){
            if(temp->data == x && (*head_ref)->data == x){
                temp = forward;
                temp->prev = NULL;
                *head_ref = temp;
                forward = forward->next;
            }
            else if(temp->data == x && (*head_ref)->data != x){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next =NULL;
                temp->prev =NULL;
                delete temp;
                temp = forward;
                forward = forward->next;
            }
           else{ temp = forward;
            forward = forward->next;
           }
        }
        if(temp->data == x){
            temp->prev->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends