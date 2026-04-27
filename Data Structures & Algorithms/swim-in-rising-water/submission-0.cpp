class Solution {
public:
    int swimInWater(vector<vector<int>>& arr) 
    {
        int mini = INT_MAX , maxi = INT_MIN;
        for(auto&vec: arr)
        {
            for(auto&ele: vec)
            {
                mini = min(mini,ele);
                maxi = max(maxi,ele);
            }
        }
        int low = mini, high = maxi, ans = maxi;
        auto checkPath = [&](int ele){
            int n = arr.size();
            vector<vector<int>>vis(n, vector<int>(n,0));
            vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
            queue<pair<int,int>>q;
            if(arr[0][0] > ele)
            {
                return false;
            }
            q.push({0,0});
            vis[0][0]=1;
            while(!q.empty())
            {
                int x = q.front().first , y = q.front().second;
                q.pop();
                if(x==n-1 && y==n-1){
                    return true;
                }
                for(int i=0; i<4; i++)
                {
                    int dx = x+dir[i][0] , dy = y+dir[i][1];
                    if(dx>=0 and dx<n and dy>=0 and dy<n and arr[dx][dy]<=ele and !vis[dx][dy])
                    {
                        vis[dx][dy] = 1;
                        q.push({dx,dy});
                    }
                }
            }
            return false;
        };
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(checkPath(mid))
            {
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
