#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second

const int mod = 1e9+7;
const int mxN = 2e5+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    deque<pair<int, int>> dq;
    dq.push_back({a[0], 1});
    cout << 0 << ' ';
    for (int i=1; i<n; i++) {
        while (dq.size()) {
            if (dq.front().F < a[i]) {
                cout << dq.front().S << ' ';
                dq.push_front({a[i], i+1});
                break;
            } else {
                dq.pop_front();
            }
        }
        if (!dq.size()) {cout << 0 << ' '; dq.push_front({a[i], i+1}) ;}
    }

    return 0;
}

/*
*/
