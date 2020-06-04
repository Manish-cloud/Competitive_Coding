/*
 * Author: Manish
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(0);
using namespace std;

typedef long long ll;
const ll Mod = 1000000007;

bool comp (string a, string b){
    if(a.size() != b.size())
        return a.size()<b.size();
    return a<b;
}

int main() {
    fastio;

    vector<int> v = {1,3,5,2,4};

    //Ascending Order
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Descending Order
    sort(v.rbegin(), v.rend());
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    string str = "ascending";
    sort(str.begin(), str.end());
    cout<<str<<endl;

    vector<pair<int,int>> vecOfPair;
    vecOfPair.push_back({1,5});
    vecOfPair.push_back({2,3});
    vecOfPair.push_back({1,2});
    sort(vecOfPair.begin(), vecOfPair.end());
    for(int i=0; i<vecOfPair.size(); i++){
        cout<<vecOfPair[i].first<<" "<<vecOfPair[i].second<<endl;
    }

    vector<tuple<int,int,int>> vecOfTuple;
    vecOfTuple.push_back({1,5,15});
    vecOfTuple.push_back({2,3,10});
    vecOfTuple.push_back({1,2,1});
    sort(vecOfTuple.begin(), vecOfTuple.end());
    for(int i=0; i<vecOfTuple.size(); i++){
        cout<<get<0>(vecOfTuple[i]) <<" "<< get<1>(vecOfTuple[i]) <<" "<< get<2>(vecOfTuple[i])<<endl;
    }

    vector<string> vecOfString;
    vecOfString.push_back("abcd");
    vecOfString.push_back("abc");
    vecOfString.push_back("abb");
    vecOfString.push_back("abbc");

    sort(vecOfString.begin(), vecOfString.end());
    for (int i=0; i<vecOfString.size(); i++){
        cout<<vecOfString[i]<<endl;
    }

    sort(vecOfString.begin(), vecOfString.end(), comp);
    for (int i=0; i<vecOfString.size(); i++){
        cout<<vecOfString[i]<<endl;
    }

    return 0;
}