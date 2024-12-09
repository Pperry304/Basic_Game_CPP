#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MAX 1000000
#define ___TruongChinh304___ signed main()
using namespace std;

// Ktra số nguyên tố bth
bool ktra_snt(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// Ktra sàng số nguyên tố
// Nhanh hơn 5 - 6 lần cách bth
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
