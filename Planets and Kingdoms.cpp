#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 1e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
vi adj[mxN], adj_t[mxN], order, id(mxN);
bool vis[mxN];

void dfs1(int u) {
    if (!vis[u]) {
        vis[u]=1;
        for (auto e : adj[u])
            if (!vis[e]) dfs1(e);
    }
    order.pb(u);
}

void dfs2(int u, int component) {
    if (!vis[u]) {
        vis[u]=1;
        for (auto e : adj_t[u])
           if (!vis[e]) dfs2(e, component);
    }

    id[u] = component;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj_t[b].pb(a);
    }

    for (int i=0; i<n; i++) {
        if (!vis[i+1])
            dfs1(i+1);
    }

    memset(vis, 0, sizeof(vis));

    int component = 0;

    for (int u=n-1; u>=0; u--) {
        if (!vis[order[u]]) {
            component++;
            dfs2(order[u], component);
        }
    }

    cout << component << '\n';

    for(int i=1; i<=n; i++)
        cout << id[i] << ' ';

    return 0;
}
/*
5 6
1 2
2 3
3 1
3 4
4 5
5 4

*/
