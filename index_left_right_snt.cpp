#include <bits/stdc++.h>
#define ___TruongChinh304___ signed main()
#define pb push_back
#define ll long long
#define MAX 10000000
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

void sang_snt(vector<bool>& b){
    b[0] = b[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++){
        if(b[i]){
            for(int j = i * i; j < MAX; j+=i){
                b[j] = false;
            }
        }
    }
}

___TruongChinh304___ {
    #ifdef ONLINE_JUDGE
    fast_io;  
    #endif

    int n; cin >> n;
    vector<ll> a(n);
    vector<bool> b(MAX, true);
    sang_snt(b);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> mcd(n);
    for(int i = 0; i < n; i++){
        if(i == 0) mcd[i] = abs(a[i]);
        else mcd[i] = abs(mcd[i-1] + a[i]);
    }

    bool check = false;
    for(int i = 1; i < n-1; i++){
        int left = 0, right = 0;
        left = mcd[i-1], right = mcd[n-1] - mcd[i];
        if(b[left] && b[right]){
            check = true;
            cout << i << " ";
        }
    }

    if(!check) cout << "Not Found !" << endl;
    cerr << "Time: " << TIME << " s.\n";
    return 0;
}
