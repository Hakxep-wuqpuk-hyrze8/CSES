#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int ans, par[mxN];
bool vis[mxN];
vector<int> adj[mxN];

void dfs (int node, int parent) {
    for (auto e : adj[node]) {
        if (e != parent)
            dfs(e, node);
    }

    if (!vis[parent] && !vis[node] && parent) {
        ans++;
        vis[parent] = vis[node] = 1;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}

/*
10
5 8
4 6
9 1
10 4
1 3
2 3
7 9
6 2
5 10

5
*/
