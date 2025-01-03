//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job {
    int id;     // Job ID
    int dead;   // Deadline of job
    int profit; // Profit if job is completed before or on the deadline
};

class Solution {
public:
    // Custom comparison function to sort jobs by profit in decreasing order
    static bool comparison(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobSequencing(vector<int>& id, vector<int>& deadline, vector<int>& profit) {
        int n = id.size(); // Number of jobs

        // Create a vector of Job structs
        vector<Job> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({id[i], deadline[i], profit[i]});
        }

        // Sort jobs by profit in decreasing order
        sort(jobs.begin(), jobs.end(), comparison);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (const auto& job : jobs) {
            maxDeadline = max(maxDeadline, job.dead);
        }

        // Create a slot array to track assigned slots (-1 means unassigned)
        vector<int> slot(maxDeadline + 1, -1);

        // Variables to count the number of jobs done and total profit
        int countJobs = 0, jobProfit = 0;
  // Assign jobs to available slots
        for (int i = 0; i < n; ++i) {
            // Find the latest available slot before the job's deadline
            for (int j = jobs[i].dead; j > 0; --j) {
                if (slot[j] == -1) { // If slot is available
                    slot[j] = jobs[i].id; // Assign the job to this slot
                    countJobs++;
                    jobProfit += jobs[i].profit;
                    break; // Exit after assigning the job
                }
            }
        }

        return {countJobs, jobProfit}; // Return the result
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends