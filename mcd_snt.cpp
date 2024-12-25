//INPUT
// 7
// 13 5
// 52 77 -12 12 -5 43 77 37 40 63 28 80 6 
// 8 2
// 1 2 3 4 5 6 7 8
// 4 1
// 1 2 3 4
// 1 2
// 1
// 5 1
// 7 8 3 1 54
// 9 1
// 1 2 3 4 5 6 7 8 9
// 15 7
// 12 4 5 6 3 6 7 29 383 20 103 345 2357 56 24

// OUTPUT
// Tc 1: 281
// Tc 2: 3
// Tc 3: 3
// Tc 4: Not Found
// Tc 5: 73
// Tc 6: 3
// Tc 7: 43

#include <bits/stdc++.h>
#define ___TruongChinh304___ signed main()
#define pb push_back
#define ll long long
#define MAX 1000000

using namespace std;

void sang_snt(bool* b){
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

    bool b[MAX];
    fill(b, b + MAX, true);
    sang_snt(b);

    int tc; cin >> tc;
    int count = 1;
    while(count <= tc){
        int n, k; cin >> n >> k;
        int a[n], mcd[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            if(i == 0) mcd[i] = a[i];
            else mcd[i] = mcd[i - 1] + a[i];
        }    

        int check = 0, max = 0;
        for(int x : mcd){
            if(b[x] && x > max && x >= k){
                max = x, check = 1;
            }
        }

        if(max != 0) cout << "Tc " << count << ": " << max << endl;
        if(!check) cout << "Tc " << count << ": " << "Not Found" << endl;
        count++;
    }

    return 0;
}    
