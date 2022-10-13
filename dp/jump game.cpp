int solve(vector<int>& arr, int d, int ind, vector<int>& v)
{
    int ans=0;
    if(v[ind]!=-1)
        return v[ind];
    for(int i=ind-1; i>=ind-d  && i>=0 && arr[i]<arr[ind]; --i)
            ans=max(ans, solve(arr, d, i, v)+1);
    for(int i=ind+1; i<=ind+d  && i<arr.size() && arr[i]<arr[ind]; ++i)
            ans=max(ans, solve(arr, d, i, v)+1);
    return v[ind]=ans;
}
int maxJumps(vector<int>& arr, int d) {
    int res=0, n=arr.size();
    vector<int> v(n, -1);
    for(int i=0; i<arr.size(); ++i)
        res=max(res, solve(arr, d, i, v));
    return res+1;
}