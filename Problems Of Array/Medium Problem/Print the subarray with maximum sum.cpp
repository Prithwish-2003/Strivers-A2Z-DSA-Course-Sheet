Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and print the sub array with max sum.

For Input: 
5
1 2 3 -2 5
Your Output: 
The Sub Array with max sum is [1 2 3 -2 5 ]
9

T.C =0(N)
S.C =0(1)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
    long long maxi=INT_MIN,sum=0;
    int start=0,ansstart=-1,ansend=-1;
    for (int i=0;i<n;i++){
       if(sum==0) start=i; 
        sum+=arr[i];
        // if(maxi<sum) {
        maxi=max(maxi,sum);
        ansstart=start;
        ansend=i;
        if(sum<0){
            sum=0;
        }
    }
   cout<<"The Sub Array with max sum is [";
        for(int i=ansstart;i<=ansend;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]\n";
        return maxi;
    
    
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
