Problem link:
# Link:
https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399/



int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left=0,right=0;
    int maxi=0;
    long long sum=a[0];
    while (right < a.size()) {
    while(left<=right&&sum>k){
       sum-=a[left];
        left++;
       // right=left;

    }
    if(sum==k){
        maxi=max(maxi,right-left+1);
    }
    right++;
    if (right<a.size()) sum+=a[right];
    
    
    }
    return maxi;
}
