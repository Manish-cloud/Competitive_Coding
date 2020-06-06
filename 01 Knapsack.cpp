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

ll maxProfit( vector<pair<int, int>> & weightProfitMat, int capacity, int numOfObj){

    vector<int> col(capacity+1,0);
    vector<vector<int>> dp(numOfObj+1, col);

    // Must
    sort(weightProfitMat.begin(),weightProfitMat.end());

    for(int i=1; i<=numOfObj; i++){
        for(int j=1; j<=capacity; j++){
            if (j >= weightProfitMat[i].first and ( ( dp[i-1][j - weightProfitMat[i].first] + weightProfitMat[i].second ) > dp[i-1][j] )){
                dp[i][j] = dp[i-1][j - weightProfitMat[i].first] + weightProfitMat[i].second;
            } else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[numOfObj][capacity];
}

int main(){
    int tc, capacity, numOfObj;
    cin>>tc;

    while(tc--){
        cout << "Enter capacity of knapsack : ";
        cin >> capacity;
        cout << "Enter number of objects : ";
        cin >> numOfObj;

        vector <pair<int, int>> weightProfitMat(numOfObj+1);

        for (int i=1; i<=numOfObj; i++){
            cout << "Enter object weight and profit : ";
            cin>>weightProfitMat[i].first;
            cin>>weightProfitMat[i].second;
        }
        cout<<"Result : "<<maxProfit(weightProfitMat, capacity, numOfObj)<<endl;
    }
    return 0;
}