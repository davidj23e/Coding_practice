#include<bits/stdc++.h>
using namespace std;

struct node
{
    int row, col, wt;
    node(int a,int b,vector<vector<int>>& mat)
    {
        row  = a;
        col = b;
        wt = mat[row][col];
    };
};
int valid(int r1,int c1, int R,int C)
{
    if((r1>=0 && r1<R) && (c1>=0 && c1<C))
        return 1;
    return 0;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    vector<vector<int>> dir{{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    int R = mat.size(), C = mat[0].size();
    vector<vector<int>> distance(R, vector<int>(C, INT_MAX-1));
    queue<node> Q;
    for(int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            if(mat[i][j] == 0)
            {
                distance[i][j] = 0;
                Q.push(node(i, j, distance));

            }
        }
    }
    while(! Q.empty())
    {
        node N = Q.front();
        Q.pop();
        for(vector<int> D: dir)
        {
            int r1 = N.row + D[0], c1 = N.col + D[1];
            if (valid(r1, c1, R,C))
            {
                int val = distance[r1][c1];
                if(val > (N.wt + 1))
                {
                    distance[r1][c1] = N.wt + 1;
                    Q.push(node(r1, c1, distance));
                }
            }
        }
    }
    return distance;
}
int main()
{
    vector<vector<int>> ques{{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
    for(int i=0;i < ques.size();i ++)
    {
        for(int j=0; j< ques[0].size(); j++)
        {
            cout << ques[i][j] << "\t";
        }
        cout << endl;
    }
    vector<vector<int>> out = updateMatrix(ques);
    cout << "\n OUTPUT" << endl;
    for(int i=0;i < ques.size();i ++)
    {
        for(int j=0; j< ques[0].size(); j++)
        {
            cout << out[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}