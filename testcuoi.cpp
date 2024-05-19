#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const char* RED_TEXT ="\033[1;31m";      // mã màu 
const char* ORANGE_TEXT ="\033[0;33m";   
const char* YELLOW_TEXT ="\033[1;33m";   
const char* GREEN_TEXT ="\033[1;32m";    
const char* BLUE_TEXT ="\033[0;34m";     
const char* INDIGO_TEXT ="\033[1;94m";   
const char* VIOLET_TEXT ="\033[1;35m";   
const char* PINK_TEXT ="\033[1;35m";   
const char* RESET_TEXT ="\033[1;37m";
const char* GRAY_TEXT = "\033[1;30m";      

class benhnhan {                          // lop thong tin benh nhan 
private:
    int id;
    string sdt, tenbn, ngaysinh, quequan;
    string ngaydieutri;
    int phikham, phidieutri, phithuoc, tongtien;
public:
    void input() {                       // ham nhap thông tin benh nhan 
        cin.ignore();
        cout <<"\nNhap ma benh nhan: ";
        cin >> id;
        fflush(stdin);
        while (id < 0) {                // neu id<0 nhap lai id 
            cout <<RED_TEXT<<"\nVui long nhap ma benh nhan > 0: ";
            cout<< RESET_TEXT;
            cin >> id;
            fflush(stdin);
        }
        cout <<"\nNhap ten benh nhan: ";
        getline(cin, tenbn);
        fflush(stdin);
        cout <<"\nNhap ngay sinh: ";
        getline(cin, ngaysinh);
        fflush(stdin);
        cout <<"\nNhap que quan: ";
        getline(cin, quequan);
        fflush(stdin);
        cout <<"\nNhap so dien thoai: ";
        cin >> sdt;
        fflush(stdin);
		cout <<"\nNgay dieu tri: ";
        getline(cin, ngaydieutri);
        fflush(stdin);
        cout <<"\nPhi kham benh: ";
        cin >> phikham;
        fflush(stdin);
        cout <<"\nPhi dieu tri: ";
        cin >> phidieutri;
        fflush(stdin);
        cout <<"\nPhi thuoc: ";
        cin >> phithuoc;
        fflush(stdin);
        tongtien = (phikham + phidieutri + phithuoc);            // tinh tong chi phi benh nhan 
        cout <<RED_TEXT<<"\nTong tien : " << tongtien;
        cout<<RESET_TEXT; 
        fflush(stdin);
    }
    void output() {                       // ham xuat thông tin benh nhan 
        cout << setw(8) <<left<< id << setw(20) << tenbn << setw(13) << ngaysinh;
        cout << setw(15) << quequan << setw(12) << sdt; 
        cout << setw(12) << ngaydieutri;
        cout << setw(11) << phikham << setw(11) << phidieutri << setw(11) << phithuoc << setw(11) << tongtien<<endl;
    }
    int get_id() {                       //public cac thông tin benh nhan de goi ngoai lop 
        return id;
    }
    string get_tenbn() {
    	return tenbn; 
	}
	string get_ngaysinh(){
		return ngaysinh;
	}
	string get_quequan() {
		return quequan;
	}
	string get_sdt(){
		return sdt;
	}
	int get_tongtien() {
        return tongtien;
    }
    string get_ngaydieutri(){
    	return ngaydieutri;
	}
	int get_phikham() {
		return phikham;
	}
	int get_phidieutri(){
		return phidieutri;
	}
	int get_phithuoc(){
		return phithuoc;
	}

};
class NhanSu {                     // lop thong tin nhan su 
private:
    string SDT, Ten, date, que;
    int ID, ngaycong, phucap, luong ; 
    static int hesoluongcoban;
public:
    string vitri;
    void INPUT() {                 // ham nhap thong tin nhân su 
        cin.ignore();
        cout <<"\nNhap ma so nhan su: ";
        cin >> ID;
        fflush(stdin);
        while (ID < 0) {
            cout <<RED_TEXT<<"\nVui long nhap ma nhan su > 0: ";
            cout <<RESET_TEXT; 
            cin >> ID;
            fflush(stdin);
        }
        cout <<"\nNhap ten nhan su: ";
        getline(cin, Ten);
        fflush(stdin);
        cout <<"\nNhap ngay sinh: ";
        getline(cin, date);
        fflush(stdin);
        cout <<"\nNhap que quan: ";
        getline(cin, que);
        fflush(stdin);
        cout <<"\nNhap so dien thoai: ";
        cin >> SDT;
        fflush(stdin);
        cout <<"\nNhap vi tri lam viec( y ta or bac si or quan ly): ";
        getline(cin, vitri);
        fflush(stdin);
		cout<<"\nNhap so ngay cong: ";
		cin>>ngaycong;
		fflush(stdin); 
        if (vitri == "y ta") {                 // gán giá tri luong cho moi vi tri làm viec 
            phucap = 1000000;
        } else if (vitri == "bac si") {
            phucap = 3000000;
        } else if (vitri == "quan ly") {
            phucap = 5000000;
        } else {
            phucap = 0;
        }
        luong = static_cast<int>(ngaycong) * hesoluongcoban + phucap; 
        cout<<RED_TEXT<<"\nTong tien luong la: "<<luong; 
    }   
    
    void OUTPUT() {                         // ham xuat thong tin nhan su 
        cout <<setw(8)<< ID<< setw(20) << Ten << setw(13) << date;
        cout <<setw(15)<<que<<setw(12)<<SDT<<setw(10)<<vitri<<setw(10)<<ngaycong<<setw(11)<<phucap<<setw(13)<<luong<<endl; 
    }
    int get_ID() {
        return ID;
	}
	int get_luong() {
        return luong;
	}
	string get_Ten(){
		return Ten; 
	}
	string get_date(){
		return date; 
	}
	string get_que(){
		return que; 
	}
	string get_SDT(){
		return SDT; 
	}
	int get_ngaycong(){
		return ngaycong; 
	} 
	string get_vitri(){
		return vitri; 
	}
	int get_phucap(){
		return phucap; 
	} 
 
};
int NhanSu::hesoluongcoban = 400000;     // khoi tao bien tinh he so luong co ban=400000 
const int NN = 100;          // co dinh so luong mang  
class qlythietbi {
private:
    int masp[NN];          
    int soluong[NN];        
    string tenthietbi[NN];  
    string tinhtrang[NN];   
    int soluongthietbi;

public:
    qlythietbi() {
        soluongthietbi = 0;
    }
    void Input() {
        int nn;
        cout <<YELLOW_TEXT<< "\nNhap so thiet bi can nhap: ";
        cout<<RESET_TEXT; 
        cin >> nn;
        for (int i = 0; i < nn; ++i) {
            cout<< "\nNhap ma thiet bi thu "<<i+1<< ":"; 
            cin >> masp[soluongthietbi];
            cout << "\nNhap so luong : ";
            cin >> soluong[soluongthietbi];
            cin.ignore();
            cout << "\nNhap ten thiet bi: ";
            getline(cin,tenthietbi[soluongthietbi]);
            cout << "\nNhap tinh trang thiet bi (new or old): ";
            getline(cin,tinhtrang[soluongthietbi]);
            cout<<RED_TEXT<<"\n================================";
            cout<<RESET_TEXT<<endl; 
            soluongthietbi++;
        }
    }
    void Output() {
    	cout<<setw(10)<<left<<"\n\nMaTB"<<setw(10)<<left<<"SoLuong"<<setw(20)<<left<<"TenTB"<<setw(13)<<left<<"TinhTrang"<<endl;
    	for (int i = 0; i < soluongthietbi; ++i) {
			cout<<setw(10)<<left<<masp[i]<<setw(10)<<left<<soluong[i]<<setw(20)<<left<<tenthietbi[i]<<setw(13)<<left<<tinhtrang[i]<<endl; 
	    }  
	}
    void qlthietbi() {               // menu quan ly thiet bi phong kham 
    int luachon;
    bool exit = false;
    do {
        system("cls"); 
        cout <<YELLOW_TEXT<<"\t                                                  Quan Ly Thiet Bi Phong Kham Rang "<<RED_TEXT<<"H"<<ORANGE_TEXT<<"I"<<YELLOW_TEXT<<"E"<<GREEN_TEXT<<"P"<<BLUE_TEXT<<"D"<<INDIGO_TEXT<<"A"<<VIOLET_TEXT<<"T \t" << endl;
        cout<<GREEN_TEXT<<"                                                           ======================================"<<endl;
        cout <<GREEN_TEXT<<"                                                           ="<<YELLOW_TEXT<<"            1.Nhap thiet bi         "<<GREEN_TEXT<<"=" << endl;
        cout <<GREEN_TEXT<<"                                                           ="<<YELLOW_TEXT<<"            2.Xuat thiet bi         "<<GREEN_TEXT<<"=" << endl;
        cout <<GREEN_TEXT<<"                                                           ="<<YELLOW_TEXT<<"            3.Quay lai menu         "<<GREEN_TEXT<<"=" << endl;
        cout<<GREEN_TEXT<<"                                                           ======================================" <<endl; 
        cout <<YELLOW_TEXT<<"\t                                                   *****Nhap lua chon cua ban: ";
        cout<<RESET_TEXT;
        cin >> luachon;
        switch (luachon) {
        case 1:
            Input();
            cout << endl;
            system("pause");
            break;
        case 2:
            Output();
            cout << endl;
            system("pause");
            break;
        case 3:
            exit = true; // danh dau thoat khoi vong lap quay tro lai menu chinh 
            break;
        default:
            cout <<RED_TEXT<<"Khong co du lieu ban nhap!";
            cout<<RESET_TEXT; 
            break;
        }
    } while (!exit);
}
};
class quanlyphongkham : public benhnhan, qlythietbi, NhanSu{                     // lop quan ly phong kham rang ke thua lop benh nhan, chi phi, qlythietbi, nhan su. 
public:
    benhnhan bn;
    NhanSu ns;                                        // goi cac phuong thuc nhap xuat thong tin benh nhan , nhan su, chi phi 
    void nhap() { 
        bn.input();
    }
    void xuat() {
        bn.output();
    }
    void Nhap() {
        ns.INPUT();
    }
    void Xuat() {
        ns.OUTPUT();
    }
};
void nhapds(quanlyphongkham a[], int n) {                         // ham nhap danh sach benh nhan 
    benhnhan bn;
    for (int i = 0; i < n; i++) {
    	int res = 0;
        do {
            res = 0;
            cout<<endl; 
            cout <<YELLOW_TEXT<<"\nBenh nhan thu: " << i + 1 << ""<<endl; 
            cout<< GREEN_TEXT<<"======================" <<endl; 
            cout<<RESET_TEXT; 
            a[i].nhap();
            for (int j = 0; j < i; j++) {
                if (a[j].bn.get_id() == a[i].bn.get_id()) {            // khi id vua nhap bang id vua nhap truoc do thì nhap lai 
                    cout <<RED_TEXT<<"\n***Ma benh nhan khong duoc trung nhau, Moi nhap lai!" << endl;
                    cout<<RESET_TEXT; 
                    res++;
                }
            }
        } while (res != 0);
    }
}
void xuatds(quanlyphongkham a[], int n) {                     // ham xuat danh sach benh nhan  
	int res=0; 
	cout<<endl; 
    cout <<YELLOW_TEXT<< setw(8) << left << "MaBN" << setw(20) << left << "TenBN" << setw(13) << left << "NgaySinh" << setw(15) << left << "QueQuan" << setw(12) << left << "SDT" << setw(12) << left << "Ngaydieutri" << setw(11) << left << "Phikham" << setw(11) << left << "Phidieutri" << setw(11) << left << "Phithuoc" << setw(11) << left << "Tongtien" << endl;
    cout<<RESET_TEXT; 
    for (int i = 0; i < n; i++) {
        a[i].xuat();
    }
}
void xuatfile(quanlyphongkham a[], int n) {              // ham ghi thong tin benh nhan vao file danhsach.txt 
    ofstream ofs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsach.txt");
    if (ofs.is_open()) {
        ofs << setw(10) << left << "MaBN" << setw(20) << left << "TenBN" << setw(15) << left << "NgaySinh" << setw(15) << left << "QueQuan" << setw(14) << left << "SDT" << setw(14) << left << "Ngaydieutri" << setw(13) << left << "Phikham" << setw(13) << left << "Phidieutri" << setw(13) << left << "Phithuoc" << setw(13) << left << "Tongtien" << endl;
        for (int i = 0; i < n; i++) {
            ofs << setw(10) << left << a[i].bn.get_id() ;
            ofs << setw(20) << left << a[i].bn.get_tenbn();
            ofs << setw(15) << left << a[i].bn.get_ngaysinh();
            ofs << setw(15) << left << a[i].bn.get_quequan();
            ofs << setw(14) << left << a[i].bn.get_sdt();
            ofs << setw(14) << left << a[i].bn.get_ngaydieutri();
            ofs << setw(13) << left << a[i].bn.get_phikham();
            ofs << setw(13) << left << a[i].bn.get_phidieutri();
            ofs << setw(13) << left << a[i].bn.get_phithuoc();
            ofs << setw(13) << left << a[i].bn	.get_tongtien()<< endl;          
    }
        ofs.close();
        cout << GREEN_TEXT << "\nXuat file thanh cong!" << RESET_TEXT << endl;
    } else {
        cout << RED_TEXT <<"\nKhong the mo file de ghi!" << RESET_TEXT << endl;
    }
}
void timkiem(quanlyphongkham a[], int n) {                   // ham tim kiem thong tin benh nhan bang id 
    int x;
    benhnhan bn;
    int count = 0;
    cout <<YELLOW_TEXT<<"\nNhap ma benh nhan can tim: ";
    cin >> x;
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    cout<<endl; 
    cout << setw(8) << left << "MaBN" << setw(20) << left << "TenBN" << setw(15) << left << "NgaySinh" << setw(12) << left << "QueQuan" << setw(12) << left << "SDT" << setw(12) << left << "Ngaydieutri"
         << setw(11) << left << "Phikham" << setw(11) << left << "Phidieutri" << setw(11) << left << "Phithuoc" << setw(1) << left << "Tongtien" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].bn.get_id() == x) {
            a[i].xuat();
            count++;
        }
    }
    if (count == 0) {
        cout <<RED_TEXT<<"\nKhong tim thay du lieu ban nhap";
        cout<<RESET_TEXT; 
    }
}
void thembn(quanlyphongkham a[], int& n) {                   // ham them thong tin benh nhan 
    n++;
    int res = 0;
    benhnhan bn;
    do {
        res = 0;
        cout <<YELLOW_TEXT<<"\nNhap thong tin benh nhan can them: "<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[n - 1].nhap();
        for (int i = 0; i < n - 1; i++) {
        if (a[i].bn.get_id() == a[n - 1].bn.get_id()) 
			{
                cout <<RED_TEXT<<"\nMa benh nhan khong duoc trung nhau. Moi ban nhap lai!" << endl;
                cout<<RESET_TEXT; 
                res++;
            }
        }
    } while (res != 0);
}
void xoabn(quanlyphongkham a[], int& n) {              // ham xoa benh nhan bang id 
    int xoa;
    int res = 0;
    benhnhan bn;
    cout <<YELLOW_TEXT<<"\nNhap ma benh nhan can xoa: ";
    cin >> xoa;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < n; i++) {
    if (a[i].bn.get_id() == xoa) {
        res++;
        for (int j = i; j < n - 1; j++) {
            a[j] = a[j + 1];
            }
        }
    }
    if (res == 0) {
        cout << RED_TEXT <<"\nMa so benh nhan khong ton tai!";
    } else {
        n--;
        cout <<GREEN_TEXT<<"\nDa xoa benh nhan co ma so " << xoa << " thanh cong!";
        cout<<RESET_TEXT; 
    }
}
void suatt(quanlyphongkham a[], int n) {               //ham sua thong tin benh nhan  
    int sua;
    int count = 0;
    benhnhan bn;
    cout <<YELLOW_TEXT<<"Nhap ma benh nhan can sua: ";
    cout<<RESET_TEXT; 
    cin >> sua;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < n; i++) {
        if (a[i].bn.get_id() == sua) {
            a[i].nhap();
            cout<<GREEN_TEXT<<"\nSua thong tin benh nhan thanh cong !";
            cout<<RESET_TEXT; 
            count++;
        }
    }
    if (count == 0) {
        cout <<RED_TEXT<<"Khong tim thay du lieu !";
        cout<<RESET_TEXT; 
    }
}
void nhapdsns(quanlyphongkham a[], int N) {                      // ham nhap thong tin nhan su 
    int res = 0;
    NhanSu ns;
    for (int i = 0; i < N; i++) {
    	do { 
    	res=0; 
        cout <<YELLOW_TEXT<<"\nNhan su thu: " << i + 1 << ""<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[i].Nhap();
        for (int j = 0; j < i; j++) {
                if (a[j].ns.get_ID() == a[i].ns.get_ID()) {
                    cout <<RED_TEXT<<"\n***Ma nhan su khong duoc trung nhau, Moi nhap lai!" << endl;
                    cout<<RESET_TEXT;
                    res++;
                }
            }
        } while (res != 0);
    }
}
void xuatdsns(quanlyphongkham a[], int N) {                   // ham xuat thong tin nhan su 
    cout <<YELLOW_TEXT<<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(10)<< left <<"Ngay Cong"<<setw(11)<<left<<"Phu Cap"<<setw(13)<<left<<"luong"<<endl; 
    cout<< RESET_TEXT; 
    for (int i = 0; i < N; i++) {
        a[i].Xuat();      
    }
}
void timkiemnhansu(quanlyphongkham a[], int N) {                   // ham tim kiem thong tin benh nhan bang id 
    int X;
    NhanSu ns;
    int count = 0;
    cout <<YELLOW_TEXT<<"\nNhap ma nhan su can tim: ";
    cin >> X;
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    cout<<endl; 
    cout <<YELLOW_TEXT<<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(10)<< left <<" Luong co ban"<<endl;
    for (int i = 0; i < N; i++) {
        if (a[i].ns.get_ID() == X) {
            a[i].Xuat();
            count++;
        }
    }
    if (count == 0) {
        cout <<RED_TEXT<<"\nKhong tim thay du lieu ban nhap";
        cout<<RESET_TEXT; 
    }
}
void themns(quanlyphongkham a[], int& N) {                   // ham them thong tin benh nhan 
    N++;
    int res = 0;
    NhanSu ns;
    do {
        res = 0;
        cout <<YELLOW_TEXT<<"\nNhap thong tin nhan su can them: "<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[N - 1].Nhap();
        for (int i = 0; i < N - 1; i++) {
        if (a[i].ns.get_ID() == a[N - 1].ns.get_ID()) 
			{
                cout <<RED_TEXT<<"\nMa nhan su khong duoc trung nhau. Moi nhap lai!" << endl;
                cout<<RESET_TEXT; 
                res++;
            }
        }
    } while (res != 0);
}
void xoans(quanlyphongkham a[], int& N) {              // ham xoa benh nhan bang id 
    int xoa;
    int res = 0;
    NhanSu ns;
    cout <<YELLOW_TEXT<<"\nNhap ma nhan su can xoa: ";
    cin >> xoa;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < N; i++) {
    if (a[i].ns.get_ID() == xoa) {
        res++;
        for (int j = i; j < N - 1; j++) {
            a[j] = a[j + 1];
            }
        }
    }
    if (res == 0) {
        cout << RED_TEXT <<"\nMa so nhan su khong ton tai!";
    } else {
        N--;
        cout <<GREEN_TEXT<<"\nDa xoa nhan su co ma so " << xoa <<" thanh cong!";
        cout<<RESET_TEXT; 
    }
}
void suattns(quanlyphongkham a[], int N) {               //ham sua thong tin benh nhan  
    int sua;
    int count = 0;
    NhanSu ns;
    cout <<YELLOW_TEXT<<"Nhap ma nhan su can sua: ";
    cout<<RESET_TEXT; 
    cin >> sua;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < N; i++) {
        if (a[i].ns.get_ID() == sua) {
            a[i].Nhap();
            cout<<GREEN_TEXT<<"\nSua thong tin nhan su thanh cong !";
            cout<<RESET_TEXT; 
            count++;
        }
    }
    if (count == 0) {
        cout <<RED_TEXT<<"Khong tim thay du lieu !";
        cout<<RESET_TEXT; 
    }
}
void xuatfilenhansu(quanlyphongkham a[], int N) {              // ham ghi thong tin benh nhan vao file danhsachnhansu.txt 
    ofstream ofs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsachnhansu.txt");
    if (ofs.is_open()) {
        ofs <<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(12)<< left <<"Ngay Cong"<<setw(11)<<left<<"Phu Cap"<<setw(13)<<left<<"luong"<<endl; 
        for (int i = 0; i < N; i++) {
            ofs << setw(8) << left << a[i].ns.get_ID() ;
            ofs << setw(20) << left << a[i].ns.get_Ten();
            ofs << setw(13) << left << a[i].ns.get_date();
            ofs << setw(15) << left << a[i].ns.get_que();
            ofs << setw(12) << left << a[i].ns.get_SDT();
            ofs << setw(10) << left << a[i].ns.get_vitri();
            ofs << setw(12) << left << a[i].ns.get_ngaycong();
            ofs << setw(11) << left << a[i].ns.get_phucap();
            ofs << setw(13) << left << a[i].ns.get_luong();
			ofs<<endl;     
    }
        ofs.close();
        cout << GREEN_TEXT <<"\nXuat file thanh cong!" << RESET_TEXT << endl;
    } else {
        cout << RED_TEXT <<"\nKhong the mo file de ghi!" << RESET_TEXT << endl;
    }
}
void menu(quanlyphongkham a[], int n, int N) {                   // ham menu tong 
    int choice;
    qlythietbi tb;
                    
    do {
        system("cls");
        cout<<endl; 
        cout <<INDIGO_TEXT<<"\t                                                      CHUONG TRINH QUAN LY PHONG KHAM RANG "<<RED_TEXT<<"H"<<ORANGE_TEXT<<"I"<<YELLOW_TEXT<<"E"<<GREEN_TEXT<<"P"<<BLUE_TEXT<<"D"<<INDIGO_TEXT<<"A"<<VIOLET_TEXT<<"T             \t"<< endl;
        cout <<"\n";                     
        cout << GREEN_TEXT << "                                                       =========================="<<RED_TEXT<<"MENU"<<GREEN_TEXT<<"===========================\n";
        cout << "                                                       ==                                                     ==\n";
        cout << "                                                       ==                                                     ==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        1.Quan ly benh nhan phong kham rang.         "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        2.Xuat danh sach benh nhan.                  "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        3.Xuat danh sach benh nhan vao file          "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        4.Tim kiem theo ma benh nhan.                "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        5.Sua thong tin benh nhan.                   "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        6.Xoa thong tin benh nhan.                   "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<YELLOW_TEXT<<"        7.Them thong tin benh nhan.                  "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        8.Quan ly nhan su phong kham rang.           "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        9.Xuat danh sach nhan su.                    "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        10.Xuat danh sach nhan su vao file           "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        11.Tim kiem theo ma nhan su.                 "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        12.Sua thong tin nhan su.                    "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        13.Xoa thong tin nhan su.                    "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<ORANGE_TEXT<<"        14.Them thong tin nhan su.                   "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<INDIGO_TEXT<<"        15.Quan ly thiet bi phong kham rang.         "<<GREEN_TEXT<<"==\n";
        cout << "                                                       =="<<RED_TEXT<<"        16.Exit.                                     "<<GREEN_TEXT<<"==\n";
        cout << "                                                       ==                                                     ==\n";
        cout << "                                                       ==                                                     ==\n";
        cout << "                                                       =========================================================\n";
        cout <<"\n";
        cout << INDIGO_TEXT <<" \t                                               ***Nhap lua chon : ";
        cout << RESET_TEXT;
        cin >> choice;
        switch (choice) {
        case 1:
            nhapds(a, n);
            cout << endl;
            system("pause");
            break;
        case 2:
            xuatds(a, n);
            cout << endl;
            system("pause");
            break;
        case 3:
            xuatfile(a, n);
            cout << endl;
            system("pause");
            break;
        case 4:
            timkiem(a, n);
            cout << endl;
            system("pause");
            break;
        case 5:
            suatt(a, n);
            cout << endl;
            system("pause");
            break;
        case 6:
            xoabn(a, n);
            cout << endl;
            system("pause");
            break;
        case 7:
            thembn(a, n);
            cout << endl;
            system("pause");
            break;
        case 8:
            nhapdsns(a, N);
            cout << endl;
            system("pause");
            break;
        case 9:
            xuatdsns(a, N);
            cout << endl;
            system("pause");
            break;
        case 10:
            xuatfilenhansu(a, N);
            cout << endl;
            system("pause");
            break;
        case 11:
            timkiemnhansu(a, N);
            cout << endl;
            system("pause");
            break;
        case 12:
            suattns(a, N);
            cout << endl;
            system("pause");
            break;
        case 13:
            xoans(a, N);
            cout << endl;
            system("pause");
            break;
        case 14:
            themns(a, N);
            cout << endl;
            system("pause");
            break;
        case 15:
            tb.qlthietbi();
            cout << endl;
            system("pause");
            break;
        case 16:
            exit(0);
            break;
        default:
            cout <<RED_TEXT<<"Khong co du lieu ban nhap!";
            break;
        }
    } while (choice != 0);
}
int main() {
    int n, N;
    cout <<YELLOW_TEXT<<"Nhap so luong benh nhan phong kham rang: ";
    cin >> n;
    cout <<YELLOW_TEXT<<"\nNhap so luong nhan su phong kham rang: ";
    cin >> N;
    quanlyphongkham* a = new quanlyphongkham[n,N];              // khoi tao mang doi tuong voi kich thuoc n:benh nhan va N: nhan su 
    menu(a,n,N);                                              //goi ham menu de hien thi menu va xu ly lua chon cua nguoi dung 
    return 0;
}



