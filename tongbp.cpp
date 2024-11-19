#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    int tbp = 0; 
    for(int i = 1; i <= n; i++){
        tbp += i*i; 
    }
    cout << tbp;
    return 0;
}
