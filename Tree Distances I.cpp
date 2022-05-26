#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

vector<int> in(mxN), out(mxN);
vector<int> adj[mxN];

void dfs1 (int u, int p) {
    in[u] = 0;

    for (auto e : adj[u]) {
        if (e == p)
            continue;

        dfs1(e, u);

        in[u] = max(in[u], 1 + in[e]);
    }
}

void dfs2 (int u, int p) {
    int mx1 = -1, mx2 = -1;

    for (auto e : adj[u]) {
        if (e == p)
            continue;

        if (mx1 <= in[e]) {
            mx2 = mx1;
            mx1 = in[e];
        } else if (mx2 < in[e]){
            mx2 = in[e];
        }
    }

    for (auto e : adj[u]) {
        if (e == p)
            continue;

        int longest = mx1;

        if (mx1 == in[e])
            longest = mx2;

        out[e] = 1 + max(out[u], longest + 1);

        dfs2 (e, u);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs1 (1, 0);

    dfs2 (1, 0);

    for (int i=1; i<=n; i++) {
        cout << max(in[i], out[i]) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T=1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*
*/
