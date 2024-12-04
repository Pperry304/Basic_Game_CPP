#include <bits/stdc++.h>
#define pb push_back
#define __TruongChinh__ signed main()
#define SNT(i, a, n) for(int i = 2; i*i <= n; i++)
using namespace std;

bool ktra_scp(int n){
    if(n < 0) return false;
    for(int i = 1; i <= n; i++){
        if(i * i == n) return true;
    }
    return false;
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

    bool check = false;
    float ttb = 0.0, count = 0.0;
    for(int i = 0; i < numbers.size(); i++){
        if(ktra_scp(numbers[i])){
            ttb += numbers[i], count ++, check = true;
        } 
    }

    if(!check){
        cout << "-" << endl;
        return 0;
    }
    float tb = ttb / count ;
    cout << fixed << setprecision(1) << tb << endl; 
    return 0;
}   
