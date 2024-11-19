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
    fast_io;
    
    string n;
    getline(cin, n);

    int tcs = 0;
    for(char c : n){
        tcs += c - '0';
    }
    cout << tcs;


    cerr << "Time: " << TIME << " s.\n";
    return 0;
}
