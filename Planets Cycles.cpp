#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define INF 0x3f3f3f3f

const int mod = 1e9+7;
const int mxN = 2e5+3;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int ans[mxN], dst[mxN], path;
bool vis[mxN];
queue<int> q;

void dfs(int u) {
    q.push(u);
    if (vis[u]) {
        path+=ans[u];
        return;
    }
    vis[u]=1;
    path++;
    dfs(dst[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        dst[i]=a;
    }

    for (int i=1; i<=n; i++) {
        path=0; int dec=1;
        dfs(i);
        if (vis[i]) {
            while (q.size()) {
                if (q.front() == q.back()) {
                    dec=0;
                }
                ans[q.front()] = path;
                path -= dec;
                q.pop();
            }
        }
        while (q.size()) q.pop();
    }

    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';

    return 0;
}

/*

*/
