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

ll minimumCost(int numV, vector<vector<int>> & weightTable){
    vi dp(numV+1,0);
    ll minPathCost;
    int cost;
    for (int i=numV-1;i>0;i--){
        minPathCost=INT_MAX;
        for (int j=i+1;j<=numV;j++){
            minPathCost=min((ll)minPathCost, (ll)weightTable[i][j]+dp[j]);
        }
        dp[i]=minPathCost;
    }

    return dp[1];
}

int main(){

    int tc, numOfVer, numOfEdges, v1, v2, w;
    cin>>tc;
    while(tc--){

        cout<<"Enter number of Vertex present in graph : ";
        cin>>numOfVer;
        cout<<"Enter number of Edges present in graph : ";
        cin>>numOfEdges;

        // 2D vector creation
        vector<int> col(numOfVer+1, INT_MAX);
        vector <vector<int>> edgeWeight(numOfVer+1, col);

        while(numOfEdges--){
            cout<<"Enter edge (in increasing order) : ";
            cin>>v1>>v2;
            cout<<"Enter weight : ";
            cin>>w;
            edgeWeight[v1][v2]=w;
        }

        ll res = minimumCost(numOfVer ,edgeWeight);
        cout<<"Result : "<<res<<endl;
    }
    return 0;
}