#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 2; i <= 9 ; i++){
        for(int j = 2; i <= 9; i++){
            cout << i << "*" << j << "=" << j*i << endl;
        }
        cout << endl;
    }
    return 0;
}
