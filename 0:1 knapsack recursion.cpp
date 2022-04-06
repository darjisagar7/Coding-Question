#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int n, int W){
    if (n==0 || W==0){
        return 0;
    }
    
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
    } else if(wt[n-1] > W) {
        return knapsack(wt, val, n-1, W);
    }
}

int main() {
	// your code goes here
	// Input weight array     Eg: wt  = [1,3,4,5]
	// Input value array      Eg: val = [1,4,5,7]
	// Input maximum weight   Eg: W   = 7
	// Output                         = 9
	
	int n, W, x, y;
	vector<int> wt, val;
	cin>>n;
	for(int i=0; i<n; i++) {
	    cin>>x>>y;
	    wt.push_back(x);
	    val.push_back(y);
	}
	cin>>W;
	cout<<knapsack(wt, val, n, W);
	return 0;
}
