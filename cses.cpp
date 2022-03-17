#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    char c[n][n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> c[i][j];
    if (c[0][0]=='*' || c[n-1][n-1]=='*') {cout << 0; return 0;}

    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<n; i++) {
        if (c[i][0] == '*') break;
        dp[i][0] = 1;
    }

    for (int i=0; i<n; i++) {
        if (c[0][i] == '*') break;
        dp[0][i] = 1;
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (c[i][j] == '*') continue;

            if (c[i-1][j] == '.')
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;

            if (c[i][j-1] == '.')
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */

    cout << dp[n-1][n-1];

    return 0;
}
/*
10
.*......*.
...*...*..
......*...
...*.*....
....*.....
..*..*....
..*.......
....*..*..
*........*
....*.....
*/
