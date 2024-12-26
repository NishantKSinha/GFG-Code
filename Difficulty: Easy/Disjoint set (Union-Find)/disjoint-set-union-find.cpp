//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends


/*Complete the functions below*/
/*int find(int A[],int X)
{
       //add code here
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
}*/
int find(int par[],int u)
{
       //add code here
       if(par[u]==u) return u;
       else return par[u] = find(par,par[u]);
}
void unionSet(int par[],int u,int v)
{
	//add code here.
	
	int par_u = find(par,u);
    int par_v = find(par,v);
    if(par_u==par_v) return;
    else par[par_u] = par_v;
}