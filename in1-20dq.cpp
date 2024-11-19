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

void in_so_de_quy(int n){
    if(n < 1) return;
    else{
        cout << n << " " << endl;
        in_so_de_quy(n - 1);
    }
}

__TruongChinh__ {
    fast_io;
    
    in_so_de_quy(20);

    cerr << "Time: " << TIME << " s.\n";
    return 0;
}
