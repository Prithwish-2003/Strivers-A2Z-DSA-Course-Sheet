Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

Ans:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1,n2;
    n1=nums1.size();
        n2=nums2.size();
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
     if(n1==0)
        return (n2%2==0)?(nums2[n2/2]+nums2[n2/2-1])/2.0:nums2[n2/2];
    
    if(n2==0)
        return (n1%2==0)?(nums1[n1/2]+nums1[n1/2-1])/2.0:nums1[n1/2];
        int low=0;
        int high=n1;
       // int cut1,cut2,low1,low2,ri1,ri2;
        while(low<=high){
          int   cut1=low+(high-low)/2;
       
 int cut2 = (n1+n2+1)/2-cut1;
int left1= (cut1==0)?INT_MIN:nums1[cut1-1];
int left2= (cut2==0)?INT_MIN:nums2[cut2-1];
            
            
int ri1= (cut1==n1)?INT_MAX:nums1[cut1];
int ri2= (cut2==n2)?INT_MAX:nums2[cut2];
if(left1<=ri2&&left2<=ri1){
    if((n1+n2)%2==0){
        return (max(left1,left2)+min(ri1,ri2))/2.0;
    }
    else return max(left1,left2);
}
         else if(left1>ri2) high=cut1-1;
            else low=cut1+1 ;
        }
        return 0.0;
    }
};


// নিচের কোড টা  leetcode এর solution থেকে copy paste kora
/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
                   // ** Intuition  **
        // I have to find out correct left half and correct right half
          // i.e : // 7 ,  || 12 , 14 , 15  --> parition it
                  //  1 , 2 , 3 , 4 , || 9 , 11  --> parition it
                  // Now just findout max(left1,left2), min(right1,right2)
        
        
        // Initilaization of some neccessary variables
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
         
      if(n1>n2)  return findMedianSortedArrays(nums2,nums1);
        
     // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
     // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
        // This mean that this formula gonna work in both condition
        int partition=(n+1)/2; 
        
    
    // Edge Case
    if(n1==0)
        return (n2%2==0)?(nums2[n2/2]+nums2[n2/2-1])/2.0:nums2[n2/2];
    
    if(n2==0)
        return (n1%2==0)?(nums1[n1/2]+nums1[n1/2-1])/2.0:nums1[n1/2];
    
    // Now do Partioning
    int left1=0;
    int right1=n1;
    int cut1,cut2;
    int l1,r1,l2,r2;
    
    do
    {   
        //Findout 'cut1' and 'cut2'
        cut1=(left1+right1)/2;
        cut2=partition-cut1;
   
        // Calculation for l1
        l1=cut1==0?INT_MIN:nums1[cut1-1];
        
        // Calculation for l2
        l2=cut2==0?INT_MIN:nums2[cut2-1];
        
        // Calculation for r1
        r1=cut1>=n1?INT_MAX:nums1[cut1];
        
        // Calculation for r2
        r2=cut2>=n2?INT_MAX:nums2[cut2];
        
        if(l1<=r2&&l2<=r1)
             // Return Result
             return (n%2==0)?(max(l1,l2)+min(r1,r2))/2.0:max(l1,l2);
        else
            
        if(l1>r2)
            right1=cut1-1;
        else
             left1=cut1+1;
       
       
    }while(left1<=right1);
        
             
    return 0.0;
    }
};*/
