#include <iostream>
#include <vector>
#include <ctime> 
#include <windows.h> 
#define endl "\n"
#define TruongChinh signed main()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const int MAX = 1e5, INF = 1e9;

vector<ll> thuat_toan_random(int n, int m) {
	ll so_ngau_nhien, so_truoc_do = -1;
    ll N = m - n;
    vector<ll> mang_so_ngau_nhien;
    while(N --> 0){
        LARGE_INTEGER tan_so, thoi_gian_hien_tai;
        QueryPerformanceFrequency(&tan_so); 
        QueryPerformanceCounter(&thoi_gian_hien_tai);
    	ull seed = static_cast<ull>(thoi_gian_hien_tai.QuadPart) * (6364136223845231082) + 1;
        seed = (seed * 1103515245 + 12345) & 0x7fffffff;
        so_ngau_nhien = n + (seed % (m - n + 1));
        if(so_ngau_nhien != so_truoc_do){
            so_truoc_do = so_ngau_nhien;
            mang_so_ngau_nhien.push_back(so_ngau_nhien);
        }    
    }
    for(int i = 0; i < N; i++){
        if(mang_so_ngau_nhien[i] % 2 == 0){
            mang_so_ngau_nhien[i] += i;
            if(mang_so_ngau_nhien[i] > m){
                mang_so_ngau_nhien[i] -= n + i - 1;
            }
        } else{ 
            mang_so_ngau_nhien[i] -= i;
            if(mang_so_ngau_nhien[i] < n){
                mang_so_ngau_nhien[i] += m - i + 1;
            }
        }    
    }
    return mang_so_ngau_nhien;
}

TruongChinh {

    int tc; cin >> tc;
    int t_case = 1;
	while(tc --> 0){
        int n, m; cin >> n >> m;
        cout << "Case #" << t_case << ": ";
        vector<ll> a = thuat_toan_random(n, m);
        for(int x : a) cout << x << " ";
        t_case++;
        cout << endl;
    }

	return 0;
}
