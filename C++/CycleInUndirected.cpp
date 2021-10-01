
bool isCycle(unordered_map<int, vector<int>> &m, vector<bool> &vis, int i, int parent)
{
    vis[i] = true;
    for (auto val : m[i])
    {
        if (vis[val] == false)
        {
            if (isCycle(m, vis, val, i))
            {
                return true;
            }
        }
        else if (val != parent)
            return true;
    }
    return false;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    unordered_map<int, vector<int>> m;
    for (auto it : B)
    {
        m[it[0]].push_back(it[1]);
        m[it[1]].push_back(it[0]);
    }
    vector<bool> vis(A + 1, false);
    for (int i = 1; i <= A; i++)
    {
        if (vis[i] == false)
        {
            if (isCycle(m, vis, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}
