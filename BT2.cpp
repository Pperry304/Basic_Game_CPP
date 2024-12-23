// Bài 5. Viết chương trình nhập/xuất dữ liệu cho dãy số nguyên A gồm n phần tử: 
// a) Kiểm tra xem dãy A có đang được sắp xếp theo thứ tự (tăng/giảm) hay không? 
// b) Hãy sắp xếp nửa đầu của dãy A tăng dần, nửa sau giảm dần, số ở giữa nếu có giữ nguyên. 
// Ví dụ: Dãy A ban đầu: 1, 6, 2, 3, 4, 5, 0, 1, 7 thì sắp xếp thành 1, 2, 3, 6, 4, 7, 5, 1, 0 
// c) Hãy tìm vị trí của cặp số có khoảng cách giá trị lớn nhất trong dãy A. 
// Ví dụ: Dãy A: 3, 9, 1, 9, 2, 7, 0, 5,  0. Thì khoảng cách giá trị lớn nhất chính là phần tử có 
// giá trị là 9 và 0 ở vị trí thứ 2 và thứ 9, tức là các phần tử A[1] và A[8].

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MAX 1000000

using namespace std;

// Câu A
bool ktra_tang_dan(vector<int>& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool ktra_giam_dan(vector<int>& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}


// Câu B
void sap_xep_tang_va_giam(vector<int>& a, int n){
    int pt_giua = n / 2;
    if(n % 2 != 0){
        for(int i = 0; i < pt_giua-1; i++){
            for(int j = i + 1; j < pt_giua; j++){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
        for(int i = pt_giua+1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] < a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
        for(int x : a){
            cout << x << " ";
        } cout << endl;
    } else {
        pt_giua--;
        for(int i = 0; i <= pt_giua; i++){
            for(int j = i + 1; j <= pt_giua; j++){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
        for(int i = pt_giua+1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] < a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
        for(int x : a){
            cout << x << " ";
        } cout << endl;
    }
}

// Câu C
void ktra_khoang_cach_lon_nhat(vector<int>& b){
    int max = -1e9, min = 1e9, max_id = 0, min_id = 0;   
    for(int i = 0; i < b.size(); i++){
        for(int j = i + 1; j < b.size(); j++){
            int hieu2so = abs(b[i] - b[j]);
            if(hieu2so > max){
                max = hieu2so, max_id = i;
            } 
            if(hieu2so < min){ 
                min = hieu2so, min_id = j;
            }
        }
    }
    cout << "Max: " << max << " " << "A[" << max_id << "]" << endl; 
    cout << "Min: " << min << " " << "A[" << min_id << "]" << endl;
}

int main(){

    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.pb(a[i]);
    }

    // Gọi hàm ktra tăng dần
    if(ktra_tang_dan(a, n)){
        cout << "Mang tang dan" << endl;
    } else cout << "Mang khong tang dan" << endl;

    // Gọi hàm ktra giảm dần
    if(ktra_giam_dan(a, n)){
        cout << "Mang giam dan" << endl;
    } else cout << "Mang khong giam dan" << endl;

    // Gọi hàm sắp xếp tăng và giảm
    sap_xep_tang_va_giam(a, n);

    // Gọi hàm kiểm tra khoảng cách lớn nhất
    ktra_khoang_cach_lon_nhat(b);

    return 0;
}
