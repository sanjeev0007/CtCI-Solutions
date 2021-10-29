bool validPalindrome(string s) {
        int lo=0,hi=s.size()-1;
        return valid(s,lo,hi,0);
        
    }
bool valid(string s,int lo,int hi,int cnt)
{
    if(cnt>1)
        return false;
    while(lo<hi)
    {


        if(s[lo]==s[hi])
        {
            lo++;
            hi--;
        }
        else
            return valid(s,lo+1,hi,cnt+1)||valid(s,lo,hi-1,cnt+1);
    }
    return true;
}
