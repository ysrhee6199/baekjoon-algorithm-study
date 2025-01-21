#include <bits/stdc++.h>
using namespace std;

int t;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int final_ret = 0;

    vector<int> a,b;
    for(int i = 0; i<t ; i++) {
        cin >> n >> m;
        vector<int> a(n),b(m);

        for(int j =0; j<n; j++) {
            cin >> a[j];
        }

        for(int k = 0; k<m; k++) {
            cin >> b[k];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        final_ret = 0;
        for(int j = 0; j<a.size(); j++) {
            int lo = 0;
            int hi = b.size()-1;
            int ret = 0;
            int val_ = a[j];
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(b[mid] > val_ ) {
                    hi = mid - 1;
                }
                else if(b[mid] == val_ ) {
                    hi = mid -1;
                }
                else if (b[mid] < val_ ){
                    ret = mid + 1;
                    lo = mid + 1;
                }
            }

            final_ret += ret;

        }

        cout << final_ret << "\n";



    }

    return 0;
}