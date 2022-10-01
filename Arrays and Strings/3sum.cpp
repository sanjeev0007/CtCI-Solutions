vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        
        for(int i=0;i<n;++i)
        {
            int target=-v[i];
            int front=i+1;
            int back=n-1;
            if(target<0)
                break;
            while(front<back)
            {
                int sum=v[front]+v[back];
                if(sum>target)
                    back--;
                else if(sum<target)
                    front++;
                else
                {
                    vector<int>triplet(3,0);
                    
                    triplet[1]=v[front];
                    triplet[2]=v[back];
                    triplet[0]=v[i];
                    ans.push_back(triplet);
                    while(front<back && v[front]==triplet[1])
                        front++;
                    while(front<back && v[back]==triplet[2])
                        back--;
                    
                }
                while(i+1<v.size() && v[i]==v[i+1])
                    i++;
            }
                
                
        }
        return ans;
    }
    
