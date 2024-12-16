// Nhập 1 mảng 3 chiều có kích thước MxNxP gồm các giá trị là số nguyên 
// 1. In ra tất các phần tử trong mảng theo thứ tự giảm dần và ko có số trùng lặp nhau.
// 2. In ra các cặp số khác nhau sao cho chúng chia hết được cho nhau 
// 3. In ra các bộ 3 số khác nhau sao cho 1 số này bằng tổng 2 số còn lại 

#include <bits/stdc++.h>
#define ___TruongChinh304___ signed main()
#define pb push_back
#define ll long long
#define MAX 1000000
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;

___TruongChinh304___ {
    #ifdef ONLINE_JUDGE
    fast_io;  
    #endif

    int n, m, p; cin >> n >> m >> p;
    int a[n][m][p];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < p; k++){
                //cout << "a[" << i << "][" << j << "][" << k << "] = ";
                cin >> a[i][j][k];
            }
        }
    }

    // Lọc các phần tử trùng lặp
    bool b[MAX] = {false}; // mảng đánh dấu
    vector<int> c; // mảng chứa các số riêng lẻ làm câu 2
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < p; k++){
                if(!b[a[i][j][k]]){
                    b[a[i][j][k]] = true;
                    c.push_back(a[i][j][k]);
                }
            }
        }
    }

    // 1) In theo chiều ngược lại
    cout << "Ket qua 1: ";
    for(int i = MAX-1; i >= 0; i--){
        if(b[i]){
            cout << i << " ";
        }
    }
    cout << endl;

    // 2) In ra các cặp số ngẫu nhiên chia hết cho nhau
    cout << "Ket qua 2:" << endl;;
    for(int i = 0; i < c.size(); i++){
        for(int j = i + 1; j < c.size(); j++){
            if(c[i] % c[j] == 0){
                cout << "(" << c[i] << "; " << c[j] << ")" << endl;
            } else if(c[j] % c[i] == 0){
                cout << "(" << c[j] << "; " << c[i] << ")" << endl;
            }
        }
    }

    // 3) In ra bộ 3 số khác nhau sao cho 2 số này bằng số còn lại
    cout << "Ket qua 3:" << endl;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c.size(); j++){
            for(int k = j + 1; k < c.size(); k++){
                if(c[j] + c[k] == i){
                    cout << i << " = " << c[j] << " + " << c[k] << endl;
                }
            }
        }
    }

    cerr << "Time: " << TIME << " s.\n";
    return 0;
}
