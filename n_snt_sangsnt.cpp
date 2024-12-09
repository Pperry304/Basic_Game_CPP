#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MAX 1000000
#define ___TruongChinh304___ signed main()
using namespace std;

vector<bool> a(MAX + 1, true);
void sang_snt(){
    a[0] = a[1] = false; 
    for(int i = 2; i <= sqrt(MAX); i++){
        if(a[i]){ 
            for(int j = i * i; j <= MAX; j += i){ 
                a[j] = false;
            }
        }
    }
}

___TruongChinh304___ {
    
    sang_snt();
    int n; cin >> n;
    vector<int> b;
    for(int i = 0; i < 1000000; i++){
        if(a[i]){
            b.pb(i);
            if(b.size() == n){
                break;
            }
        } 
    }

    for(int x : b){
        cout << x << " ";
    }

    return 0;
}   
