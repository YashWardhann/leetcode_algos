class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();     
  
        if (n < 2) return triangle[0][0];
              
        int* dp[n];
        
        dp[0] = new int[1]{ triangle[0][0] };
        int ans = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            dp[i] = new int[i+1];
            for (int j = 0; j < i+1; ++j) {
                int left = (j > 0) ? dp[i-1][j-1] : INT_MAX; 
                int right = (j < i) ? dp[i-1][j] : INT_MAX;
                dp[i][j] = std::min(left, right) + triangle[i][j];
                
                if (i == n-1) {
                    ans = std::min(ans, dp[i][j]);            
                }
            }
        }
        
        return ans;   
    }
};
