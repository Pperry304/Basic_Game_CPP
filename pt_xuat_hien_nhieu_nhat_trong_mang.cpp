#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <algorithm>
#define ll long long
#define endl "\n"
#define ___TruongChinh304___ signed main()
// #define max_arr(v) *max_element(v.begin(), v.end())
// #define min_arr(v) *min_element(v.begin(), v.end())

using namespace std;

const int MAX = 1e5, MIN = -1e9, INF = 1e9;

___TruongChinh304___ {

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<bool> mdd(MAX, false);
    vector<pair<int, int>> pai;
    for(int i = 0; i < n; i++){
        if(!mdd[a[i]]) { 
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == a[i]) {
                    count++;
                }
            }
            pai.push_back({a[i], count});
            mdd[a[i]] = true; 
        }
    }

    pair<int, int> max_pair = pai[0];
    for(const auto& p : pai){
        if(p.second > max_pair.second){
            max_pair = p;
        }
    }

    cout << max_pair.first << " " << max_pair.second << endl;

    return 0;
}
