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

        ll res = computeLongestCommonSubsequence(a, b, table);
        cout<<"Length of LCS : "<<res<<endl;

        if(res){
            string ans="";
            int i=a.size(), j=b.size();
            while(res){
                if(a[i-1] == b[j-1]){
                    ans.append(1,a[i-1]);
                    res--;
                    i--;
                    j--;
                }
                else{
                    if (table[i][j-1] > table[i-1][j])
                        j--;
                    else
                        i--;
                }
            }
            reverse(ans.begin(), ans.end());
            cout<<"LCS is :=> "<<ans<<endl;
        }
    }
    return 0;
}