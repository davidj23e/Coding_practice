class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int l = arr.size();
        vector<vector<int>> r_adj(l, vector<int>());
        vector<bool> reach(l,false);
        queue<int> Q;
        for(int i = 0; i < l; i++)
        {
            if(arr[i]==0)
                reach[i] = true;
            int val = arr[i];
            if(val+i < l)
            {    
                r_adj[val+i].push_back(i);
                if(arr[val+i] == 0)
                {
                    reach[i] = true;
                    Q.push(i);
                }
            }
            if(i-val > -1)
            {    
                r_adj[i-val].push_back(i);
                if(arr[i-val] == 0)
                {
                    reach[i] = true;
                    Q.push(i);
                }
            }
        }
        while(!Q.empty())
        {
            int elem = Q.front();
            Q.pop();
            if (elem == start)
                return true;
            for(int neighbor: r_adj[elem])
            {
                if(!reach[neighbor])
                {
                    reach[neighbor] = true;
                    Q.push(neighbor);
                }
            }
                
        }
        return false;
    }
};