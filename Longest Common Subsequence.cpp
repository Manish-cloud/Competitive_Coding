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
ll computeLongestCommonSubsequence(string & a, string & b, vector<vector<int>> & arr){

    for (int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }
    return arr[a.size()][b.size()];
}

ll LCS_Recursion(string & a, string & b, vector<vector<int>> & table, vector<vector<bool>>& ready, int i, int j) {
    /*
    if (i==0 or j==0)                             // if i=0 or j=0
        return 0;
    if (a[i-1]==b[j-1])                             // if i,j > 0 and a[i] == b[j]
        return 1 + LCS_Recursion(a,b, table, ready, i-1, j-1);
    else                                            // if i,j > 0 and a[i] != b[j]
        return max(LCS_Recursion(a, b, table, ready, i, j-1), LCS_Recursion(a, b, table, ready, i-1, j));
    */

    if (i == 0 or j == 0)                                   // if i=0 or j=0
        return 0;
    if (ready[i - 1][j - 1])                                // DP concept
        return table[i - 1][j - 1];
    if (a[i - 1] == b[j - 1]) {                             // if i,j > 0 and a[i] == b[j]
        table[i-1][j-1] = 1 + LCS_Recursion(a, b, table, ready, i - 1, j - 1);          // Memoization
        ready[i-1][j-1] = true;
        return table[i-1][j-1];
    } else {                                                // if i,j > 0 and a[i] != b[j]
        table[i-1][j-1] = max(LCS_Recursion(a, b, table, ready, i, j - 1), LCS_Recursion(a, b, table, ready, i - 1, j));  // Memoization
        ready[i-1][j-1] = true;
        return table[i-1][j-1];
    }
}

int main(){
    int n,val;
    int tc;
    string a, b;

    cin>>tc;
    while(tc--){
        cout<<"Enter first String   : ";
        cin>>a;
        cout<<"Enter Second String  : ";
        cin>>b;

        // 2D vector creation
        vector<int> col(b.size()+1,0);
        vector <vector<int>> table(a.size()+1, col);

        vector<bool> bsCol(b.size()+1, false);
        vector<vector<bool>> ready(a.size()+1, bsCol);

        cout<<"Length of LCS : "<<computeLongestCommonSubsequence(a, b, table)<<endl;
        cout<<"Length of LCS : "<<LCS_Recursion(a, b, table, ready, a.size(), b.size())<<endl;
    }
    return 0;
}