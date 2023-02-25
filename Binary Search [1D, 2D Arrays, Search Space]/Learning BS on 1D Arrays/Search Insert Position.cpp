Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
  
  
  class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0;int j=n-1;int mid,index;
        while(i<=j){
            mid=i+(j-i)/2;
            if(target< nums[0]) {
                index=0;break;
            }
            if(target>nums[n-1]) {
                index=n;break;
            }
          else   if(target<nums[mid] && target>nums[mid-1]) {
              index = mid;
            //  break;
          }
            if (target==nums[mid]){index=mid; break;}
            else if (target<nums[mid]) j=mid-1;
            else i=mid+1;
        }
        return index;
    }
};
