You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
 

Constraints:

bloomDay.length == n
1 <= n <= 105
1 <= bloomDay[i] <= 109
1 <= m <= 106
1 <= k <= n

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int day;
        //if (m*k>n) return -1; (runtime error aschilo...because int value overflow kore jachilo)
        int max_day=INT_MIN;int min_day=0;
        int mid;
        for(int i=0;i<n;i++){
          max_day=max(bloomDay[i],max_day);
        }
        
        while(min_day<=max_day){
            if(m>n/k){
                day=-1;
                break;
            }
            if(m*k==n) {day= max_day;break;}
            mid=min_day+(max_day-min_day)/2;
          int x =  check(bloomDay,mid,m,k);
            if(x<m) min_day=mid+1;
            else if(x==m){
                day= mid;
                max_day=mid-1;
            }
            else max_day=mid-1;
            
    }
        return day;
        }
public:
    int check(vector<int>&bloomDay,int mid,int m,int k){
        int co=0;int m1=0;
        for(int i=0;i<bloomDay.size();i++){
            if (bloomDay[i]<=mid){
                co+=1;
            if(co==k) {
                m1+=1;
                co=0;}
            if(m1>=m) break;
                }
            else co=0;
        }
        return m1;
        
    }
};
