#include <bits/stdc++.h>
#define pb push_back
#define __TruongChinh__ signed main()
#define SNT(i, a, n) for(int i = 2; i*i <= n; i++)
using namespace std;

bool ktra_snt(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
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
    bool check = false;
    for(int i = 0; i < numbers.size(); i++){
        if(ktra_snt(numbers[i])){
            cout << numbers[i] << " ";
            sum += numbers[i];
            check = true;
        }
    }

    if(!check){
        cout << "-";
    }

    cout << endl << sum << endl;
    
    return 0;    
}   
