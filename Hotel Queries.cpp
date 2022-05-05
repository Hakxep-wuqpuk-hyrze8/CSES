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
ll treenode[mxN * 4], a[mxN], tag[mxN * 4];

void push(int l, int r, int v) {
    treenode[v] += tag[v];
    if (l==r)
        return tag[v]=0, void();
    tag[v*2] += tag[v];
    tag[v*2+1] += tag[v];
    tag[v] = 0;
}

void pull(int l, int r, int v) {
    if (l==r)
        return;
    int mid=(l+r)/2;
    push(l, mid, v*2);
    push(mid+1, r, v*2+1);
    treenode[v] = max(treenode[v*2], treenode[v*2+1]);
}

void update(int L, int R, ll val, int l, int r, int v) {
    push(l, r, v);
    if (l==L && r==R) {
        tag[v] += val;
        push(l, r, v);
        return;
    }

    int mid=(l+r)/2;
    if (R<=mid)
        update(L, R, val, l, mid, v*2);
    else if (L>mid)
        update(L, R, val, mid+1, r, v*2+1);
    else update(L, mid, val, l, mid, v*2), update(mid+1, R, val, mid+1, r, v*2+1);
    pull(l, r, v);
}

void query(int val, int l, int r, int v) {
    if (l==r) {
        treenode[v] -= val;
        cout << l << ' ';
        return;
    }

    int mid=(l+r)/2;
    if (treenode[v*2] >= val) {
        query(val, l, mid, v*2);
    } else if (treenode[v*2+1] >= val) {
        query(val, mid+1, r, v*2+1);
    }

    treenode[v] = max(treenode[v*2], treenode[v*2+1]);
}

void build(int l, int r, int v) {
    if (r==l) {
        treenode[v] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l, mid, v*2);
    build(mid+1, r, v*2+1);
    treenode[v] = max(treenode[v*2], treenode[v*2+1]);
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
    for (int i=1; i<=n ; i++) cin >> a[i];
    build(1, n, 1);

    while (q--) {
        int val;
        cin >> val;
        if (treenode[1] < val) {cout << 0 << ' '; continue;}

        query(val, 1, n, 1);
    }

    return 0;
}

/*
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

*/
