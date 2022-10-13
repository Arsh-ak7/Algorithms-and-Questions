int solve_dp(vector<int>& nums1, vector<int>& nums2)
{
    int ans=0, n=nums1.size(), m=nums2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n+1; ++i)
    {
        for(int j=0; j<m+1; ++j)
        {
            if(i==0 ||j==0)
                dp[i][j]=0;
            else if(nums1[i-1]==nums2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans, dp[i][j]);
            }
            else
                dp[i][j]=0;  
        }
    }
    return ans;
}
int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int n, int m, int &ans, vector<vector<int>>& v)
{
    if(i>=n || j>=m) return ans;
    if(v[i][j]!=-1)
        return v[i][j];
    int temp=ans;
    if(nums1[i]==nums2[j])
        temp=solve(nums1, nums2, i+1, j+1, n, m, ans+1, v);
    int a=solve(nums1, nums2, i+1, j, n, m, 0, v), b=solve(nums1, nums2, i, j+1, n, m, 0, v);
    return v[i][j]=max(temp, max(a, b));
}
int findLength(vector<int>& nums1, vector<int>& nums2) {
    // int ans=0, n=nums1.size(), m=nums2.size();
    // vector<vector<int>> v(n, vector<int>(m, -1));
    // solve(nums1, nums2, 0, 0, ans, v);
    // return ans;
    return solve_dp(nums1, nums2);
}