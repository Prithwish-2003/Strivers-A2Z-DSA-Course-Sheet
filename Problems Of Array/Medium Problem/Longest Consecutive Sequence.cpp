Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109



//better case//Coding Ninjas Question
T.C = 0(N)+0(Nlog(N))

int longestSuccessiveElements(vector<int>&a) {
    int Last_smaller=INT_MIN;
    int count=0;
    int longest=1;

    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]-1==Last_smaller){
            count+=1;
            Last_smaller=a[i];
        }
        else if(a[i]!=Last_smaller){
            count=1;
            Last_smaller=a[i];
        }
        longest=max(longest,count);
    }
    return longest;
}


//Optimal Aproach
T.C=0(N)//because in avg case unordered set T.C = 0(1)
//so 1st loop ar jono 0(N)+0(N)(2nd loop & 3 rd loop(3 rd loop all time run hobe na))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
if(n==0){
    return 0;
}
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int longest = INT_MIN;
        int count =0;

        for(auto it : s){
            if(s.find(it-1)==s.end()){
               int x=it;
                count=1;
                while(s.find(x+1)!=s.end()){
                    count+=1;
                    x=x+1;
                }
                longest=max(longest,count);
            }
        
        }
        return longest;
    }
};
