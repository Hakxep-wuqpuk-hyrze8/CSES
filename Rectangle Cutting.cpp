#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9+7;
const int mxN = 505;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Union_Find{
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


int dp[mxN][mxN];
/*
int solve(int n, int m) {
    if (n==m) return 0;
    if (n==1 || m==1) return max(m, n)-1;
    if (dp[n][m] != 1e9) return dp[n][m];


    for (int i=1; i<max(n, m); i++) {
        if (n>m) {
            if (i<m) dp[n][m] = min(dp[n][m], solve(n, m-i)+solve(n, i)+1);
            dp[n][m] = min(dp[n][m], solve(n-i, m)+solve(i, m)+1);
        }
        if (m>n) {
            if (i<n) dp[n][m] = min(dp[n][m], solve(n-i, m)+solve(i, m)+1);
            dp[n][m] = min(dp[n][m], solve(n, m-i)+solve(n, i)+1);
        }
    }

    return dp[n][m];
}
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<mxN; i++) {
        for (int j=0; j<mxN; j++) {
            if (i==j) dp[i][j]=0;
            else if (i==1 || j==1) dp[i][j]=max(i, j)-1;
            else dp[i][j] = 1e9;
        }
    }

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (dp[i][j]!=1e9) continue;

            for (int k=1; k<i; k++) {
                dp[i][j] = min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
            }
            for (int k=1; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
            }
        }
    }

    cout << dp[n][m];

    return 0;
}
/*
1 0

*/
