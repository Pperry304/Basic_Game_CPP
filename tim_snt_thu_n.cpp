// Tìm số nguyên tố thứ n

#include <bits/stdc++.h>
#define ___TruongChinh304___ signed main()
#define pb push_back
#define ll long long
#define MAX 1000000
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

void sang_snt(vector<bool>& a){
    a[0] = a[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++){
        if(a[i]){
            for(int j = i * i; j < MAX; j+=i){
                a[j] = false;
            }
        }
    }
}

___TruongChinh304___ {
    #ifdef ONLINE_JUDGE
    fast_io;  
    #endif
    
    vector<bool> a(1000000, true);
    sang_snt(a);
    int n; cin >> n;
    vector<int> snt;
    for(int i = 0; i < MAX; i++){
        if(a[i]){
            snt.pb(i);
            if(int(snt.size()) == n){
                for(int i = 0; i < int(snt.size()); i++){
                    if(i == int(snt.size()-1)){
                        cout << snt[i] << endl;
                        break;
                    }
                }
            }
        }
    }

    cerr << "Time: " << TIME << " s.\n";
    return 0;
}   
