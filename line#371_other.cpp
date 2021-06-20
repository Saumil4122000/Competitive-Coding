#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N);

int find(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    return find(parent[i]);
}
void make_set(int i)
{
    parent[i] = i;
    size[i] = 1;
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        size[a] += size[b];
        parent[b] = a;
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find(u);
        int y = find(v);
        if (x != y)
        {
            Union(u, v);
            cost += w;
        }
        else
        {
            continue;
        }
    }
    cout<<cost;
}