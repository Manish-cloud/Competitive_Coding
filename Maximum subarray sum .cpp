/*
 * Author: Manish
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(0);
using namespace std;

typedef long long ll;
const ll Mod = 1000000007;

int main() {

    fastio;
    int tc;
    int n;

    cin>>tc;

    while(tc--) {

        cin >> n;
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int best, sum;
        /* Approach 1 : Brute Force approach
         * Compute Sum for all possible subarray.
         * Time Complexity : O(n^3)
         */
        best = 0, sum = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a; b < n; b++) {
                int sum = 0;
                for (int k = a; k <= b; k++) {
                    sum += array[k];
                }
                best = max(best, sum);
            }
        }

        /* Approach 2 : Optimization in Brute Force approach
         * Time Complexity : O(n^2)
         */
        best = 0, sum = 0;
        for (int a = 0; a < n; a++){
            int sum=0;
            for (int b = a; b < n; b++){
                sum += array[b];
                best=max(best,sum);
            }
        }

        /* Approach 3 : Kadane's algorithm
         *   The idea is to calculate, for each array position, the maximum sum of a subarray that ends at that position.
         *   After this, the answer for the problem is the maximum of those sums.
         *   Consider the sub-problem of finding the maximum-sum subarray that ends at position k.
         *   There are two possibilities:
         *      1. The subarray only contains the element at position k.
         *      2. The subarray consists of a subarray that ends at position k−1, followed by the element at position k.
         *
         * Time Complexity : O(n)
         */
        best = 0, sum = 0;
        for (int a = 0; a<n; a++){
            sum = max(array[a], sum+array[a]);
            best = max(best, sum);
        }

        cout << best << "\n";
    }
    return 0;
}