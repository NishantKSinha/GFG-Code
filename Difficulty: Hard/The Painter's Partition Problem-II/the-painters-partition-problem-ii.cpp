//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
long long check(int arr[],long long mid,int n){
    long long paint = 1;
    long long sum = 0 ;
    for(int i = 0 ; i < n;i++){
        if(sum + arr[i] <= mid) sum = sum + arr[i];
        else{
            paint++;
            sum = arr[i];
        }
    }
    return paint;
}
class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
     long long max = -1;
     for(int i = 0 ; i < n ; i++){
         if(max < arr[i]) max = arr[i];
     }
     long long low = max;
     
    long long sum = 0;
     for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
     }
     long long high = sum;
    
    while(low<=high){
        long long mid = (low+high)/2;
        long long count = check(arr,mid,n);
        if(count > k) low = mid+1;
        else{
          
           high = mid - 1;
        }
    }
    return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends