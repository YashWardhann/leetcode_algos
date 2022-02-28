class Solution {
public:
    
    void print(int* arr, const size_t size) {
        for (auto i = 0; i < size; ++i) {
            std::cout << arr[i] << ',';
        }
        std::cout << std::endl;
    }
    
    int numDecodings(string s) {
        const size_t n = s.length();
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        // Leading zero check 
        if (s[0] == '0') {
            return 0;
        }
        
        for (int i = 2; i <= n; ++i) {
            // Decode character as group
            int group = (s[i-1]-'0') + 10*(s[i-2]-'0');
            // Decode it as a single character 
            if ( s[i-1] != '0' ) {
                dp[i] = dp[i-1];
                if (s[i-2] != '0' && group > 0 && group <= 26) {
                    dp[i] += dp[i-2];
                }    
            
            } else {
                // If we encounter 0, then we can only decode it as a group
                dp[i] = (group > 0 && group < 26) ? dp[i-2] : dp[i] = 0;
            }
            
        }
        return dp[n];
    }
};
