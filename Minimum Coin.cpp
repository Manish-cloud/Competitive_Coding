/*
 * Author: Manish
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(0);
using namespace std;

#define M 32
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
typedef vector<tuple<int, int, int>> vt;
typedef set<int> si;
const ll Mod = 1000000007;

bitset <100000000> ready;
ll value[100000000];
vi coins = {2,4,100};

ll solve(ll x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (ready[x]) return value[x];  // DP concept
    ll best = INT_MAX;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }

    value[x] = best;        // memoization
    ready[x] = 1;

    return best;
}

int main(){
    fastio;
    int tc,n,val;

    ll res=solve(10000000);
    cout << "Answer : " << res;

    return 0;
}   