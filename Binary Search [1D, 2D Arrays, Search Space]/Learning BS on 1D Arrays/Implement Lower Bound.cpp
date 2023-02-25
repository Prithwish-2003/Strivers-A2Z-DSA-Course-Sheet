Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

Example 1:

Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less 
than 0 is found. So output 
is "-1".
Example 2:

Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based 
indexing).
  
  class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    long long findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long s=0;long long e=n-1;
        while (s<e){
            
            long long m=s+(e-s)/2;
            if (v[0]>x) return -1;
            if (x>v[n-1]) return n-1;
            if (v[m]==x) return m;
if (v[m]>x&&v[m-1]<=x) return m-1;
            else if (v[m]>x) e =m-1; 
            else s=m+1;
        }
        //return -1;
        
    }
};
  
