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
ll value[100000000]={0};
vi coins = {};

ll solveRecursive(ll x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (ready[x]) return value[x];  // DP concept
    ll best = INT_MAX;
    for (auto c : coins) {
        best = min(best, solveRecursive(x-c)+1);
    }
    value[x] = best;        // memoization
    ready[x] = 1;
    return best;
}

ll solveIterative(ll n){
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
    fastio;
    int tc,n,val;
    cout<<"Enter number of coins : ";
    cin>>n;
    while(n--){
        cin>>val;
        coins.push_back(val);
    }
    cout<<"Enter sum to form : ";
    cin>>n;
    cout << "Answer using recursive procedure : " << solveRecursive(n)<<endl;
    cout << "Answer using Iterative procedure : " << solveIterative(n)<<endl;
    return 0;
}