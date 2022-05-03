#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9+7;
const int mxN = 1e3+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char a[mxN][mxN];
ll dp[mxN][mxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i-1][j-1] == '*')
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
            else
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1] << '\n';
    }

    return 0;
}
/*
4
4 5 1 3
*/
