// ! cpp
// Game TX 
// Copyright by @Truongchinh304
    
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#define __TruongChinh__ signed main()
using namespace std;
string path_file_so_du = "/sdcard/download/codingc++/so_du.txt";
string path_file_lich_su = "/sdcard/download/codingc++/lich_su_choi.txt";

// Ham in banner 
void in_ra_banner(){
    const char* banner = 
    R"(Telegram owner: @CChinh304
    
    ███████╗██████╗░   ░█████╗░░█████╗░
    ██╔════╝██╔══██╗   ██╔══██╗██╔══██╗
    █████╗░░██████╦╝   ╚█████╔╝╚█████╔╝
    ██╔══╝░░██╔══██╗   ██╔══██╗██╔══██╗
    ██║░░░░░██████╦╝   ╚█████╔╝╚█████╔╝
    ╚═╝░░░░░╚═════╝░   ░╚════╝░░╚════╝░
    
   ░█▄─░█ ░█─░█ ─█▀▀█ 　 ░█▀▀█ ─█▀▀█ ▀█▀ 
   ░█░█░█ ░█▀▀█ ░█▄▄█ 　 ░█─── ░█▄▄█ ░█─ 
   ░█──▀█ ░█─░█ ░█─░█ 　 ░█▄▄█ ░█─░█ ▄█▄ 

 ░█▀▀█ ░█─░█ ─█▀▀█ ░█─░█ 　 ░█▀▀█ ░█─░█ ▀█▀ 
 ░█─── ░█▀▀█ ░█▄▄█ ░█─░█ 　 ░█▄▄█ ░█▀▀█ ░█─ 
 ░█▄▄█ ░█─░█ ░█─░█ ─▀▄▄▀ 　 ░█─── ░█─░█ ▄█▄
    )";
    cout << banner << endl; 
}

// Mảnh xúc xắc 6 mặt 
const char* dice_faces[7][4] = {
    {"", "", "", ""}, 
    {"-----------", "|         |", "|    •    |", "|         |"},
    {"-----------", "|  •      |", "|         |", "|      •  |"},
    {"-----------", "|  •      |", "|    •    |", "|      •  |"},
    {"-----------", "|  •   •  |", "|         |", "|  •   •  |"},
    {"-----------", "|  •   •  |", "|    •    |", "|  •   •  |"},
    {"-----------", "|  •   •  |", "|  •   •  |", "|  •   •  |"}
};
 
 // Hàm đọc số dư từ file
int doc_so_du_tu_file(){
    ifstream file(path_file_so_du);
    int so_du = 0;
    if (file.is_open()) {
        file >> so_du;
        file.close();
    }
    return so_du;
}

// Hàm ghi số dư và lịch sử chơi vào file
void ghi_lich_su_choi(int so_du, int tien_cuoc, char ket_qua_du_doan, bool ket_qua_thang){
    ofstream file(path_file_lich_su, ios::app);
    if (file.is_open()) {
        file << "{Tiền cược: " << tien_cuoc << " VND, Dự đoán: " << (ket_qua_du_doan == 't' ? "Tài" : "Xỉu")
             << ", Kết quả: " << (ket_qua_thang ? "Thắng" : "Thua") 
             << ", Số dư sau phiên: " << so_du << " VND};\n" << endl;
        file.close();
    }
}

// Hàm lưu số dư cuối cùng vào file
void luu_so_du_cuoi_cung(int so_du) {
    ofstream file(path_file_so_du);
    if (file.is_open()) {
        file << so_du << endl;
        file.close();
    }
}

// Hàm nhập số dư 
int nhap_so_du_ban_dau(){
    while (true){
        try{
            cout << "Nạp số dư cuả bạn: ";
            int so_du; cin >> so_du;
            if(so_du < 1000 || so_du > 100000000){
                throw "Giới hạn nạp 1000 - 100000000";
            }else{
                return so_du;
            }    
        }
        catch (const char* msg) {
            cout << "Ngoại lệ: " << msg << endl;
        }    
    }
}

// Hàm nhập kết quả dự đoán
char nhap_ket_qua_du_doan(){
    while (true){
        try{
            cout << "Vui lòng chọn tài hoặc xỉu (T/X): ";
            char ket_qua_du_doan; 
            cin >> ket_qua_du_doan;
            if (ket_qua_du_doan != 't' && ket_qua_du_doan != 'x' && ket_qua_du_doan != 'T' && ket_qua_du_doan != 'X') {
                throw "Chỉ nhập T hoặc X!";
            }else{
                return tolower(ket_qua_du_doan);
            }
        }
        catch (const char* msg) {
            cout << "Ngoại lệ: " << msg << endl;
        }    
    }
}

// Hàm nhập tiền cược
int nhap_tien_cuoc(int so_du){
    while (true){
        try{
            cout << "Nhập tiền cược: ";
            int tien_cuoc; cin >> tien_cuoc;
            if(tien_cuoc < 1000 || tien_cuoc > 100000000){
                throw "Giới hạn nhập 1000 - 100000000";
            }    
            if(tien_cuoc > so_du){
                throw "Tiền cược vượt quá số dư !";
            }else{
                return tien_cuoc;
            }    
        }
        catch (const char* msg) {
            cout << "Ngoại lệ: " << msg << endl;
        }    
    }
}

// Hàm delay
void delay(int seconds) {
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time);
}

// Hàm đếm ngược
void loading() {
    for (int i = 5; i > 0; i--) {
        cout << "Kết quả sẽ có trong " << i << " giây\r";
        cout.flush(); 
        delay(1);
    }
}    

// Hàm xử lý kết quả
int xu_ly_ket_qua(int so_du, char ket_qua_du_doan, int tien_cuoc){
    srand(time(0));
    int xuc_xac_1 = rand() % 6 + 1;
    int xuc_xac_2 = rand() % 6 + 1;
    int xuc_xac_3 = rand() % 6 + 1;
    int tong_diem_xuc_xac = xuc_xac_1 + xuc_xac_2 + xuc_xac_3;
    cout << endl;
    loading(); 
    for (int line = 0; line < 5; line++) {
        cout << dice_faces[xuc_xac_1][line] << "  "
             << dice_faces[xuc_xac_2][line] << "  "
             << dice_faces[xuc_xac_3][line] << endl;
    }
    cout << endl;
    bool ket_qua_thang = (tong_diem_xuc_xac > 10 && ket_qua_du_doan == 't') || (tong_diem_xuc_xac <= 10 && ket_qua_du_doan == 'x');
    if (ket_qua_thang){
        float tien_thang = tien_cuoc * 0.9;
        so_du += tien_thang + tien_cuoc; 
        cout << "Bạn đã đoán đúng !" << endl;
        cout << "Kết quả: " << (tong_diem_xuc_xac > 10 ? "Tài" : "Xỉu") << " (" << tong_diem_xuc_xac << ") " << "[" << xuc_xac_1 << " - " << xuc_xac_2 << " - " << xuc_xac_3 << "]" << endl;
        cout << "Tiền thắng: " << tien_thang << " VND" << endl;
    }
    else {
        so_du -= tien_cuoc; 
        cout << "Bạn đã đoán sai !" << endl;
        cout << "Kết quả: " << (tong_diem_xuc_xac > 10 ? "Tài" : "Xỉu") << " (" << tong_diem_xuc_xac << ") " << "[" << xuc_xac_1 << " - " << xuc_xac_2 << " - " << xuc_xac_3 << "]" << endl;
        cout << "Tiền thua: " << tien_cuoc << " VND" << endl;
    }    
    ghi_lich_su_choi(so_du, tien_cuoc, ket_qua_du_doan, ket_qua_thang);
    cout << "Số dư mới: " << so_du << " VND" << endl;
    return so_du;
}

// Hàm kiểm tra số dư 
int kiem_tra_so_du(int so_du){
    if(so_du < 1000){
        cout << "Bạn đã hết tiền! Nạp thêm để chơi" << endl;
        return true;
    }
    return false;
}

// Hàm main
__TruongChinh__ {
    in_ra_banner();
    int so_du = doc_so_du_tu_file(); 
    if (so_du == 0) { 
        so_du = nhap_so_du_ban_dau();
    }
    for(int i = 1; i <= 1000; i++){
        cout << "Số dư cuả bạn là: " << so_du << " VND" << endl;
        cout << "Phiên: " << i << endl;
        cout << "---------------------------------------------" << endl;
        char ket_qua_du_doan = nhap_ket_qua_du_doan();
        int tien_cuoc = nhap_tien_cuoc(so_du);
        so_du = xu_ly_ket_qua(so_du, ket_qua_du_doan, tien_cuoc);
        if (kiem_tra_so_du(so_du)){
            so_du = nhap_so_du_ban_dau();
        }
        cout << "---------------------------------------------\n\n" << endl;
        luu_so_du_cuoi_cung(so_du);
    }
    return 0;
} 
