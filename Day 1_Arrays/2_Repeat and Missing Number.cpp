// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        // code here
        int *ans = new int[2];
        
        int x = 0;
        
        for(int i = 0; i < n; i++)
            x ^= a[i];
        
        for(int i = 1; i <= n; i++)
            x ^= i;
        
        int rsb = x & -x;
        int c = 0;
        int d = 0;
        
        for(int i = 0; i < n; i++)
        {
            if((a[i] & rsb) == 0)
                c ^= a[i];
            else
                d ^= a[i];
        }
        
        for(int i = 1; i <= n; i++)
        {
            if((i & rsb) == 0)
                c ^= i;
            else
                d ^= i;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] == c)
            {
                ans[0] = c;
                ans[1] = d;
                break;
            }
            else if(a[i] == d)
            {
                ans[0] = d;
                ans[1] = c;
                break;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends


//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1





//https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++)
            ans = ans ^ nums[i];
        
        for(int i = 0; i <= nums.size(); i++)
            ans = ans ^ i;
        
        return ans;
    }
};
