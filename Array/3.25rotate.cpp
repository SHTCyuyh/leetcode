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
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // cout<< n<<endl;
        // vector<vector<int>> res;
        matrix = changematrix(matrix);
        matrix = changematrix2(matrix);
        // return res;
    }
private:
    vector<vector<int>> changematrix(vector<vector<int>>& matrix){
        int n = matrix.size();
        // cout<< n<<endl;
        for (int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }      
        }
        return matrix;
    }

    vector<vector<int>> changematrix2(vector<vector<int>>& matrix){
        int n = matrix.size();
        // cout<< n<<endl;

            for(int i = 0;i<n;i++){
                int left = 0, right = n-1;
                while(left<right){
                    int temp = matrix[i][left];
                    matrix[i][left] = matrix[i][right];
                    matrix[i][right] = temp;
                    left++;
                    right--;
            }
        }
        return matrix;
    }

    
};