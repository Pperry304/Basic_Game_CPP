#include <bits/stdc++.h>
#define pb push_back
#define __TruongChinh__ signed main()
#define SNT(i, a, n) for(int i = 2; i*i <= n; i++)
using namespace std;

int ktra_snt(int n){
    if(n < 2) return 0;
    SNT(i, 2, n){
        if(n % i == 0) return 0;
    }
    return n > 1;
}

__TruongChinh__ {

    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> numbers;
    int num;

    while (iss >> num) {
        numbers.push_back(num);
    }

    int sum = 0;
    vector<int> snt;
    for(int i = 0; i < numbers.size(); i++){
        if(ktra_snt(numbers[i])){
            sum += numbers[i];
            snt.pb(numbers[i]);
        }
    }

    if(snt.empty()){
        cout << "-" << endl;
    } else {
        for(int x : snt){
            cout << x << " ";
        }
        cout << endl << sum << endl;
    }

    return 0;
}   
