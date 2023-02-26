Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
  
  //{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int i =0;int mid,y1;
	    y1=-1;
	    int j=n-1;int count;
	    bool flag=true;
	    while(i<=j){
	        mid=i+(j-i)/2;
	        if (arr[mid]==x){
	            y1=mid;
	            break;
	        }
	        else if(arr[mid]>x) j=mid-1;
	        else i=mid+1;
	    }
	    if (y1==-1) {flag = false;// break;
	    }
	 else{   int y=y1; count =1;
	    while (y1>=0&&arr[y1-1]==x) { count+=1;y1--;}
	    
	    while (y<n&&arr[y+1]==x) { count+=1;y++;}
}
	    if (flag) return count;
	    else return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
