#include <bits/stdc++.h>
using namespace std;
#define ___TruongChinh___ signed main() 

___TruongChinh___ {

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int check = 0; 
    vector<bool> found(n, false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] + a[j] == x && (!found[a[i]])){
                cout << a[i] << " " << a[j] << endl;
                check = 1, found[a[i]] = true; found[a[j]] = true;
            }
        }
    }
    
    if(!check){
        cout << "-" << endl;
    }
    return 0;    
}   
