#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e5+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    ll prefix=0, ans=0;
    map<ll, int> sum;
    sum[0]=1;
    for (int k : a) {
        prefix += k;

        ans += sum[prefix - target];
        sum[prefix]++;
    }

    cout << ans;

    return 0;
}
/*
5 7
2 4 1 2 7

*/
