
bool dfs(vector<bool> &vis, vector<bool> &order, int i, map<int, vector<int>> &m)
{
    vis[i] = true;
    order[i] = true;
    for (auto x : m[i])
    {
        if (vis[x] == false && dfs(vis, order, x, m))
        {
            return true;
        }
        else if (order[x] == true)
            return true;
    }
    order[i] = false;
    return false;
}
int Solution::solve(int A, vector<vector<int>> &B)
{

    vector<bool> vis(A + 1, false);
    vector<bool> order(A + 1, false);
    map<int, vector<int>> m;
    for (auto it : B)
    {
        m[it[0]].push_back(it[1]);
    }
    for (int i = 1; i <= A; i++)
    {
        if (vis[i] == false)
        {
            bool c = dfs(vis, order, i, m);
            if (c)
                return true;
        }
    }
    return false;
}
