#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 5;
const double EPS = 1e-7;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

struct point {
    double x, y;

    point operator * (int a) {return {a * x, a * y};}
    point operator / (int a) {return {x / a, y / a};}
    point operator + (point b){return {x + b.x, y + b.y};}
    point operator - (point b){return {x - b.x, y - b.y};}

    double operator * (point b){return x * b.x + y * b.y;}
    double operator ^ (point b){return x * b.y - y * b.x;}

    bool operator < (point b){
        return x == b.x ? y < b.y : x < b.x;
    }
};

typedef point pt;

int sign(double a){
    if(abs(a) < EPS) return 0;
    else return (a > 0 ? 1 : -1);
}

int ori(point a, point b, point c){
    return sign((b-a)^(c-a));
}

void solve() {
    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    if (ori(c, a, b) == 0) {
        cout << "TOUCH\n";
        return;
    }

    if (ori(c, a, b) < 0) {
        cout << "RIGHT\n";
    }
    else {
        cout << "LEFT\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while (T--)
        solve();

    return 0;
}
