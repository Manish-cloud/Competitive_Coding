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

ll solveI(ll n, vi coins){

    ll value[10000000]={0};

    vi solution (n+1,0);    // Used to construct solution

    for(int i=1; i<=n; i++){
        value[i] = INT_MAX;
        for (auto c : coins) {
            if (i-c >= 0 and value[i-c]+1 < value[i]) {
                value[i] = value[i-c]+1;
                solution[i] = c;
            }
        }
    }

    if (value[n]!=INT_MAX) {
        cout << "Answer using Iterative procedure : " << value[n] << endl;
        cout << "Coins used to form solution : ";
        while (n > 0) {
            cout << solution[n] << " ";
            n -= solution[n];
        }
        cout << endl;
    }
    else
        return -1;
    return 0;
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

        ll res;
        res = solveI(n, coins);
        if (res!=0)
            cout<<"Not possible to form Answer"<<endl;

        coins.clear();
        ready.reset();
        fill(value, value+100000000, 0);
    }
    return 0;
}