void sortColors(vector<int>& v) {
        int tmp=0;
        int low=0,high=v.size()-1;
        int mid=0;
        while(mid<=high)
        {
            if(v[mid]==0)
            {
                tmp=v[mid];
                v[mid]=v[low];
                v[low]=tmp;
                low++;
                mid++;
            }
            else if(v[mid]==1)
            {
                mid++;
            }
            else if(v[mid]==2)
            {
                tmp=v[mid];
                v[mid]=v[high];
                v[high]=tmp;
                high--;
                // mid++;
                
            }
            
        }
        
    }
