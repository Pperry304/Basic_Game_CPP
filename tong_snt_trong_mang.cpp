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

int ktra_snt(int n){
    SNT(i, 2, n){
        if(n % i == 0) return 0;
    }
    return n > 1;
}

__TruongChinh__ {
    fast_io;
    
    int n; cin >> n;
    vector<int> mang(n); 
    REP(i, n){
        cin >> mang[i];
    }

    int tsnt = 0;
    for(int z : mang){
        if(ktra_snt(z)) tsnt += z; 
    }
    cout << tsnt << endl;

    cerr << "Time: " << TIME << " s.\n";
    return 0;
}   
