#include <bits/stdc++.h>

using namespace std;

const int mxN = 505;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0,  1, 1};

vector<int> adj[mxN];
vector<vector<ll>> capacity;
vector<int> parent;

ll BFS(int s, int t) {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, 1e18});

    while (q.size()) {
        int cur = q.front().F;
        ll flow = q.front().S;
        q.pop();

        for (auto next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll max_flow (int s, int t) {
    ll flow = 0;
    ll new_flow;

    while (new_flow = BFS(s, t)) {
        int cur = t;
        while (cur != s) {
            int pre = parent[cur];
            capacity[pre][cur] -= new_flow;
            capacity[cur][pre] += new_flow;
            cur = pre;
        }
        flow += new_flow;
    }

    return flow;
}

int main()
{
    int n, m;
    cin >> n >> m;
    capacity.resize(n+1, vector<ll>(n+1));
    parent.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin >> a >> b >> w;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] += w;
    }

    cout << max_flow(1, n) << '\n';

    return 0;
}
