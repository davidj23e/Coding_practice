class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <= 1 || prerequisites.size() == 0)
            return true;
        vector<vector<int>> radj(numCourses, vector<int>());
        vector<int> ctr(numCourses, 0);
        
        for(vector<int> edge: prerequisites)
        {
            int a = edge[0], b = edge[1];
            radj[b].push_back(a);
            ctr[a]++;
        }
        
        queue<int> leaves;
        
        for(int idx = 0; idx < numCourses; idx++)
        {
            if(ctr[idx] < 1)
                leaves.push(idx);
        }
        
        int total = numCourses;
        while(!leaves.empty())
        {
            total -= 1;
            int leaf = leaves.front();
            leaves.pop();
            for(int node: radj[leaf])
            {
                ctr[node]--;
                if(ctr[node] == 0)
                    leaves.push(node);
            }
        }
        if(total)
            return false;
        return true;

        
    }
};