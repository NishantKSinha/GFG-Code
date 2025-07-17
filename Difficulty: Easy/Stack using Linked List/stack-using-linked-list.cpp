class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here == top pint to null
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
        
    }

    int pop() {
        
        // code here
        if(top == NULL) return -1;
        StackNode* temp = top;
        top = top->next;
        int ans = temp->data;
        delete temp;
        return ans;
    }

    MyStack() { top = NULL; }
};