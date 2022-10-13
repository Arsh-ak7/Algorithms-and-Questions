string longestPalindrome(string s) {
    int n=s.size(), len=1, a=0, b=0;
    for(int i=0; i<n; ++i)
    {
        int l=i-1, r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1>len)
            {
                len=r-l+1;
                a=l;
                b=r;
            }
            l--;
            r++;
        }
        
        l=i-1, r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1>len)
            {
                len=r-l+1;
                a=l;
                b=r;
            }
            l--;
            r++;
        }
    }
    return s.substr(a, b-a+1);
}