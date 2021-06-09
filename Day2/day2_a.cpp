class Solution {
public:
    struct dir
    {
        int R, C;
        char D;
        dir(int a,int b, char x)
        {
            R = a;
            C = b;
            D = x;
        };
    };
    
    int invert(dir &path)
    {
        if(path.D == 'U')
            path = dir(1, -1, 'D');
        else
            path = dir(-1, 1, 'U');
        return 0;
    }
    
    bool valid(int r1, int c1, int R, int C)
    {
        if(r1>=0 && r1<R && c1>=0 &&c1<C)
        {
            return true;
        }
        return false;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<int> result;
        queue<pair<int,int>> Q;
        dir path(-1, 1, 'U');
        Q.push(make_pair(0,0));
        while(! Q.empty())
        {
            pair<int,int> cur = Q.front();
            Q.pop();
            result.push_back(mat[cur.first][cur.second]);
            int r1 = cur.first + path.R, c1 = cur.second + path.C;
            if(valid(r1, c1, R, C))
            {
                Q.push(make_pair(r1, c1));
            }
            else
            {
                if(path.D == 'U')
                {
                    r1 = cur.first;
                    c1 = cur.second + 1;
                    if(valid(r1, c1, R, C))
                    {
                        Q.push(make_pair(r1, c1));
                    }
                    else
                    {
                        r1 = cur.first +1;
                        c1 = cur.second;
                        if(valid(r1, c1, R, C))
                            Q.push(make_pair(r1, c1));
                    }
                }
                if(path.D == 'D')
                {
                    r1 = cur.first + 1;
                    c1 = cur.second;
                    if(valid(r1, c1, R, C))
                    {
                        Q.push(make_pair(r1, c1));
                    }
                    else
                    {
                        r1 = cur.first;
                        c1 = cur.second + 1;
                        if(valid(r1, c1, R, C))
                            Q.push(make_pair(r1, c1));
                    }
                }
                invert(path); 
            }
        }
        return result;
    }
};