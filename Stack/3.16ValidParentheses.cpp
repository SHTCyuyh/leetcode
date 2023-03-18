#include<stack>
#include<string>
using namespace std; 

class Solution {
public:
    bool isValid(string s) {
    stack<char> left;
    for(char c : s){
        if (c == '(' || c == '{' || c == '[') 
            left.push(c);
        else
            if (!left.empty() && leftOf(c) == left.top()) 
                left.pop();
            else
                return false;

    }
    return left.empty();
    }
    char leftOf(char c){
        if (c == ')') return '(';
        if (c == '}') return '{';
        return '[';
    }
};

