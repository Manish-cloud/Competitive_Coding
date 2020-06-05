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

bitset<100000000> ready;
ll value[100000000] = {0};
vi coins={};

ll solveR(ll x){
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (ready[x]) return value[x];  // DP concept
    ll best = INT_MAX;
    for (auto c : coins) {
        best = min(best, solveR(x-c)+1);
    }
    value[x] = best;        // memoization
    ready[x] = 1;
    return best;
}

ll solveI(ll n, vi coins){
    ll value[10000000]={0};
    for(int i=1; i<=n; i++){
        value[i] = INT_MAX;
        for (auto c : coins) {
            if (i-c >= 0){
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }
    return value[n];
}

int main(){
    int n,val;
    int tc;
    
    cin>>tc;
    while(tc--){
        cin >> n;
        while (n--) {
            cin >> val;
            coins.push_back(val);
        }
        cin>>n;
        ll res = solveR(n);
        if (res!=INT_MAX)
            cout << "Answer using recursive procedure : " << res << endl;
        else
            cout<<"Not possibble to form Answer"<<endl;
        
        res = solveI(n, coins);
        if (res!=INT_MAX)
            cout << "Answer using Iterative procedure : " << res << endl;
        else
            cout<<"Not possibble to form Answer"<<endl;
            
        coins.clear();
        ready.reset();
        fill(value, value+100000000, 0);
    }
    return 0;
}