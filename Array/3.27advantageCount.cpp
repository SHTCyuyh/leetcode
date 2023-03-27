#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
// private:
//         struct cmp{
//         template<typename T, typename U>
//         bool operator()(T const& left, U const &right) {
//             if (left.second < right.second) return true;
//             return false;
//         }
//         };
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // auto cmp = [](int left, int right){return (left)}
        auto cmp = [](pair<int,int> left, pair<int,int> right){return (left.second) < (right.second);};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> mq(cmp);

        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> mq;
        vector<int> res(nums1.size());
        for(int i=0; i< nums2.size();i++) {
            pair<int,int> a(i,nums2[i]);
            mq.push(a);
        };
        int left = 0, right = nums1.size()-1;
        sort(nums1.begin(), nums1.end());
        while(!mq.empty()){
            auto [i, val] = mq.top();
            cout<<i<< val<< endl;
            mq.pop();
            if(val <nums1[right]){
                res[i] = nums1[right];
                right--; 
            }else{
                res[i] = nums1[left];
                left++;
            }
        }
        return res;
    }
};