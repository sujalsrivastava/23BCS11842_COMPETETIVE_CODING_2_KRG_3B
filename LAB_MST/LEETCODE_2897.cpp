class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(32, 0);
        for(int x : nums){
            for(int b = 0; b < 32; b++){
                if(x & (1 << b)) cnt[b]++;
            }
        }

        long long ans = 0;
        while(k--){
            long long val = 0;

            for(int b = 0; b < 32; b++){
                if(cnt[b] > 0){
                    val |= (1LL << b);
                    cnt[b]--;
                }
            }
            ans = (ans + val * val) % MOD;
        }

        return ans;
    }
};
