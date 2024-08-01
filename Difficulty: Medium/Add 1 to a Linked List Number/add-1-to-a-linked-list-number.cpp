//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution {
  public:
   
    int addhelper(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = addhelper(temp->next);
        temp->data += carry;
        if(temp->data <10) return 0;
        else{
            temp->data = 0;
            return 1;
        }
    }
    Node* addOne(Node* head) {
    //USE OF RECURSION GIVES BACKTRACKING WHICH REMOVE THE PROBLEM OF REVERSAL SO TC REDUCE     
    //WE USE BACKTRACKING TO MINIMISE TC FROM O(3N) TO O(N)BUT SC INCREASEFROM O(1)->O(N)
        
        int carry = addhelper(head);
         
         if(carry == 1){
             Node* newnode = new Node(1);
             newnode->next = head;
             head = newnode;
         }
         return head;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends