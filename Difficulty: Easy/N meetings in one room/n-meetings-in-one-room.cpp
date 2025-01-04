//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct meeting {
    int start;     // Job ID
    int end;   // Deadline of job
    int pos; // Profit if job is completed before or on the deadline
};

class Solution {
  public:
   static bool comparison(meeting a, meeting b) {
        if (a.end < b.end) {
        return true; // a comes before b
    } else if (a.end > b.end) {
        return false; // b comes before a
    } else {
        // If end times are equal, compare positions
        return a.pos < b.pos;
    }
    }
int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size(); // Number of jobs
        vector<int> position(n); // Declare position array
        // Create a vector of meeting structs
        vector<meeting> meet;
        for (int i = 0; i < n; ++i) {
            meet.push_back({start[i], end[i], position[i] = i+1}); //we can write directly 
                                                    //i+1 too instead of vector declaration
        }
               
         sort(meet.begin(), meet.end(), comparison);
         
         vector < int > answer;
          int limit = meet[0].end;
      answer.push_back(meet[0].pos);
      int count = 1;

      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
            count++;
         }
      } 
      return count;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends