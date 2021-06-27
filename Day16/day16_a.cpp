class Solution {
public:
    void backtrack(vector<vector<int>> &result, vector<int> elem, int curr, int n, int k)
    {
        if(elem.size() == k)
        {
            result.push_back(elem);
            return;
        }
        for(int i = curr; i <= n ; i++)
        {
            elem.push_back(i);
            backtrack(result, elem, i + 1, n, k);
            elem.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        backtrack(result, vector<int>(), 1, n, k);
        return result;
    }
};