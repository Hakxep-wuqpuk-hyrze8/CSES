#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
const int mxN = 5005;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

ll pre[mxN], dp[mxN][mxN], a[mxN];

ll sol (int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r-1) return max(a[l], a[r]);
    dp[l][r] = a[l] + pre[r+1] - pre[l+1] - sol(l+1, r);
    dp[l][r] = max(a[r] + pre[r] - pre[l] - sol(l, r-1), dp[l][r]);
    return dp[l][r];
}

void solve() {
     int n; cin >> n;
     for (int i=0; i<n; i++)
        cin >> a[i];
     for (int i=1; i<=n ;i++)
        pre[i] = pre[i-1]+a[i-1];

     memset(dp, -1, sizeof(dp));
     cout << sol(0, n-1);
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
