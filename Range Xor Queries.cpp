#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

// Segment tree
ll treenode[mxN * 4], a[mxN];

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
    treenode[v] = min(treenode[v*2], treenode[v*2+1]);
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
        return query(L, mid, l, mid, v*2) ^ query(mid+1, R, mid+1, r, v*2+1);

}

void build(int l, int r, int v) {
    if (r==l) {
        treenode[v] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l, mid, v*2);
    build(mid+1, r, v*2+1);
    treenode[v]= treenode[v*2] ^ treenode[v*2+1]; // pull
}

struct Union_Find {
    int p[mxN], sz[mxN];
    void init() {
        for (int i=0; i<mxN; i++) {
            sz[i] = 1; p[i] = i;
        }
    }
    int Find(int x) {
        if (p[x] == x) return x;
        return p[x] = Find(p[x]);
    }
    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        p[x] = y;
        sz[y] += sz[x];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];

    build(1, n, 1);

    while (q--) {
        int a, b; cin >> a >> b;
        cout << query(a, b, 1, n, 1) << "\n";
    }


    return 0;
}

/*
*/
