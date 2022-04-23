#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define INF 0x3f3f3f3f

const int mod = 1e9+7;
const int mxN = 1e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct UnionFind{
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
    bool Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        if (x == y) return false;
        if (sz[x] > sz[y]) swap(x, y);
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    UnionFind UF;
    UF.init();

    int group=n, mxsz=1;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        if (UF.Union(a, b))
            cout << --group;
        else
            cout << group;
        cout << ' ';
        if (UF.sz[UF.Find(a)] > mxsz) {
            cout << UF.sz[UF.Find(a)];
            mxsz = UF.sz[UF.Find(a)];
        } else
            cout << mxsz;
        cout << '\n';
    }

    return 0;
}
/*

*/
