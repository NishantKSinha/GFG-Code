//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  struct Item {
    int value;
    int weight;
};
  bool static comp(Item a, Item b) {
         return (double)a.value / a.weight > (double)b.value / b.weight;
      }
    // Function to get the maximum total value in the knapsack.
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n = val.size();
    std::vector<Item> items(n);

    // Combine value and weight into a single structure
    for (int i = 0; i < n; ++i) {
        items[i] = {val[i], wt[i]};
    }
    sort(items.begin(), items.end(), comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;;
            finalvalue += items[i].value;
         } else {
            int remain = capacity - curWeight;
            finalvalue += (double)items[i].value * remain / items[i].weight;

            break;
         }
      }

      return finalvalue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends