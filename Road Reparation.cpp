#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

// index 0
ll treenode[mxN * 4];
ll a[mxN];

void update(int pos, int val, int l, int r, int v) {
    if (l==r) {
        treenode[v] = val;
        return;
    }

    int mid=(l+r)/2;
    if (pos<=mid)
        update(pos, val, l, mid, v*2);
    else
        update(pos, val, mid+1, r, v*2+1);
    treenode[v]=treenode[v*2]+treenode[v*2+1];
}

ll query(int L, int R, int l, int r, int v) {
    if (l==L && r==R) {
        return treenode[v];
    }

    int mid=(l+r)/2;
    if (R<=mid)
        return query(L, R, l, mid, v*2);
    else if (L>mid)
        return query(L, R, mid+1, r, v*2+1);
    else
        return query(L, mid, l, mid, v*2) + query(mid+1, R, mid+1, r, v*2+1);

}

void build(int l, int r, int v) {
    if (r==l) {
        treenode[v] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l, mid, v*2);
    build(mid+1, r, v*2+1);
    treenode[v]=treenode[v*2]+treenode[v*2+1]; // pull
}

// USD

struct Edge{
    int u, v, w;
};

ll p[mxN], sz[mxN];
vector<Edge> adj;

ll Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}

bool Union (int a, int b) {
    int fa=Find(a), fb=Find(b);
    if (fa==fb) return false;

    if (sz[fa]>sz[fb]) {
        sz[fa]+=sz[fb];
        p[fb]=fa;
    } else {
        sz[fb]+=sz[fa];
        p[fa]=fb;
    }
    return true;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<mxN; i++) p[i]=i;

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj.pb({a, b, w});
        adj.pb({b, a, w});
    }

    sort(adj.begin(), adj.end(), cmp);

    ll ans=0;
    for (auto k : adj) {
        if (Union(k.v, k.u)) {
            ans += k.w;
        }
    }



    if (Find(1)!=Find(n)) {cout << "IMPOSSIBLE"; return 0;}
    cout << ans;

    return 0;
}

/*
*/