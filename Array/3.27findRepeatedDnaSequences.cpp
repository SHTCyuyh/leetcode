#include <stdio.h>
#include <vector>
#include <string>
#include<unordered_map>
#include <assert.h>
#include<unordered_set>
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
    vector<string> findRepeatedDnaSequences(string s) {
         int n = s.length();
    //记录出现过的子串
    unordered_set<string> seen;
    //记录那些重复出现多次的子串
    //注意要用哈希集合，防止记录重复的结果
    unordered_set<string> res;

    for(int i = 0; i + 10 <= n; i++) {
        string subStr = s.substr(i, 10);
        if(seen.count(subStr)) {
            //之前出现过，找到一个重复的
            res.insert(subStr);
        } else {
            //之前没出现过，加入集合
            seen.insert(subStr);
        }
    }
    return vector<string>(res.begin(), res.end());
    }
};