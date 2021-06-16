class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        queue<int> top;
        for(vector<int> edge: prerequisites)
        {
            int a = edge[0], b = edge[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        for(int i=0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                top.push(i);
        }
        
        int total = numCourses;
        vector<int> order;
        
        while(!top.empty())
        {
            int node = top.front();
            order.push_back(node);
            top.pop();
            total--;
            
            for(int idx: adj[node])
            {
                indegree[idx]--;
                if(indegree[idx] == 0)
                    top.push(idx);
            }
        }
        if(total)
            return vector<int>();
        return order;
    }
};