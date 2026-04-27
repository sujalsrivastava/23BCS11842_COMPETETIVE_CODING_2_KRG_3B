class Solution {
  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            bool valid = true;
            
            for (int i = 0; i < n; i++) {
                
                if (mask & (1 << i)) {
                    if (i > 0 && arr[i] == arr[i - 1] && !(mask & (1 << (i - 1)))) {
                        valid = false;
                        break;
                    }
                    
                    subset.push_back(arr[i]);
                }
            }
            
            if (valid) ans.push_back(subset);
        }
        
        return ans;
    }
};
