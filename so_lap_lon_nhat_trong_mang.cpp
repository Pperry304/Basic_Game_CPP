#include <bits/stdc++.h>
#include <cstdlib> // random
#include <unistd.h> // time delay (sleep)
#define __TruongChinh__ signed main()
#define loop while (true)
#define ll long long
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define SNT(i, a, n) for(int i = 2; i*i <= n; i++)
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

__TruongChinh__ {

    int n; cin >> n;
    int mang[n];
    for(int i = 0; i < n; i++){
        cin >> mang[i];
    }

    // tìm số bị lặp
    vector<int> mangchuasolap;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(mang[j] == mang[i]){
                mangchuasolap.push_back(mang[i]);
                break;
            }
        }
    }

    // tìm số bị lặp lớn nhất
    int max = mangchuasolap[0];
    for(int i = 0; i < mangchuasolap.size(); i++){
        if(mangchuasolap[i] > max){
            max = mangchuasolap[i];
        }
    }
    cout << max << endl; 

    cerr << "Time: " << TIME << " (s)" << endl;
    return 0;
}
