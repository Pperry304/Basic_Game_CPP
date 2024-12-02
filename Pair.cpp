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
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<bool> b(n, false);
    vector<pair<int, int>> pai;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] + a[j] == 30 && i != j && !b[a[i]] && !b[a[j]]){
                pai.pb(make_pair(a[i], a[j]));
                b[a[i]] = true , b[a[j]] = true;
            }
        }
    }

    for(const auto& x : pai){
        cout << x.first << " " << x.second << endl;
    }
    
    cerr << "Time: " << TIME << " s.\n";
    return 0;
}   
