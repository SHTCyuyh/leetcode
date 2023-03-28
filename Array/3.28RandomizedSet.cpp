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

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> val2index;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(val2index.count(val)){
            return false;
        }
        val2index[val] = nums.size();
        nums.push_back(val);
        return true; 
    }
    
    bool remove(int val) {
        if(!val2index.count(val)){
            return false;
        }
        int index = val2index[val];
        val2index[nums.back()] = index;
        swap(nums.back(), nums[index]);
        nums.pop_back();
        val2index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
