#include <stdio.h>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        Difference df(nums);
        for (auto &booking: bookings){
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            df.increament(i,j,val);
        }
        return df.result();
    }
private:
    class Difference{
        vector<int> diff;
    public:
        Difference(vector<int> &nums){
            assert(nums.size()>0);
            diff = vector<int>(nums.size());
            diff[0] = nums[0];
            for (int i=1; i<nums.size(); i++){
                diff[i] = nums[i] - nums[i-1];
            }
        }
        void increament(int i, int j, int val){
            diff[i] += val;
            if (j+1 < diff.size()) {
                diff[j+1] -= val;
            }
        }
        vector<int> result(){
            vector<int> res(diff.size());
            res[0] = diff[0];
            for (int i=1; i<diff.size(); i++){
                res[i] = res[i-1] + diff[i];
            }
            return res;
        }
    };
};