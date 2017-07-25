#include <iostream>
#include <vector>

using namespace std;

//27.63% 19ms
//time: O(n)
//space: O(n)
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroElements;
        for(int i=0;i<nums.size();i++)
            if(nums[i])
                nonZeroElements.push_back(nums[i]);
        for(int i=0;i<nonZeroElements.size();i++)
            nums[i] = nonZeroElements[i];
        for(int i=nonZeroElements.size();i<nums.size();i++)
            nums[i] = 0;
    }
};

//3.6% 36ms
// time: O(n^2)
//space: O(1)
class SolutionMe{
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = nums.size();
        int nonZeroIndex = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIndex = i;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        nonZeroIndex = j;
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};

//27.63% 19ms
//time: O(n)
//space: O(1)
class SolutionMe2{
public:
    void moveZeroes(vector<int>& nums) {
        //for [0,k)
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[k] = nums[i];
                k++;
            }
        }
        for(int i=k;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};

//43.31% 16ms
//time: O(n)
//space: O(1)
class Solution2{
public:
    void moveZeroes(vector<int>& nums) {
        //for [0,k)
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[k],nums[i]);
                k++;
            }
        }
    }
};

//time: O(n)
//space: O(1)
class Solution{
public:
    void moveZeroes(vector<int>& nums) {
        //for [0,k)
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(i!=k){ //special case
                    swap(nums[k],nums[i]);
                    k++;
                }else k++;
            }
        }
    }
};

int main() {
    int arr[] = {0,1,0,3,12};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
    Solution().moveZeroes(vec);

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    return 0;
}