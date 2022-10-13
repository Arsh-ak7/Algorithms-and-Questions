int trap(vector<int>& h) 
{
    int n=h.size(), ans=0;
    vector<int> left(n), right(n);
    left[0]=h[0];
    right[n-1]=h[n-1];
    for(int i=1; i<n; ++i)
        left[i]=max(h[i], left[i-1]);
    for(int i=n-2; i>=0; --i)
        right[i]=max(h[i], right[i+1]);
    for(int i=1; i<n-1; ++i)
        ans+=min(left[i], right[i])-h[i];
    return ans;
}