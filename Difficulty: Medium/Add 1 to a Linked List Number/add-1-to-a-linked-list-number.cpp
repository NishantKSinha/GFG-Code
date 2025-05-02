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
  Node* reverse(Node* head){
      Node* prev = NULL;
      Node* temp = head;
      Node* forward = head ->next;
      while(forward != NULL){
          temp->next = prev;
          prev = temp;
          temp = forward;
          forward = forward->next;
      }
      temp->next = prev;
       return temp;
  }
    Node* addOne(Node* head) { //reverse->add->reverse
        // Your Code here
       Node* newhead =  reverse(head);
        Node* temp = newhead;
        int carry = 1;
        while(temp != NULL){
            temp->data = temp->data +carry;
            if(temp -> data < 10){
                carry = 0;
                break;
            }
            temp->data = 0;
            carry =1;
            temp = temp->next;
        }
        if(carry == 1) {
         Node* newnode = new Node(1);
         Node* newhead2 = reverse(newhead);
         newnode->next = newhead2;
         return newnode;
        }
        Node* newhead1 = reverse(newhead);
        return newhead1;
        // return head of list after adding one
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
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends