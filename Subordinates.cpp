#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int ans, sz[mxN];
vector<int> adj[mxN];

void dfs (int node, int parent) {
    for (auto e : adj[node]) {
        if (e != parent) {
            dfs(e, node);
        }
    }

    sz[parent] += sz[node]+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        int p; cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }

    dfs(1, 0);

    for (int i=1; i<=n; i++)
        cout << sz[i] << ' ';

    return 0;
}

/*

*/
