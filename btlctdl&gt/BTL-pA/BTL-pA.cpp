#include <bits/stdc++.h>
using namespace std;
#define TM int main
#define FOR(i, a, b) for (int i = a; i < b; i++)

class SV {
private:
    string msv;
    string ten;
    long tuoi;
    double diem;

public:
    SV() {
        msv = "";
        ten = "";
        tuoi = 0;
        diem = 0.0;
    }
    ~SV() {}

    friend istream& operator>>(istream &inp, SV &sv) {
        inp >> sv.msv;
        inp.ignore();
        getline(inp, sv.ten);
        inp >> sv.tuoi;
        inp >> sv.diem;
        return inp;
    }

    friend ostream& operator<<(ostream &oup, const SV &sv) {
        oup << left << setw(10) << sv.msv
            << left << setw(20) << sv.ten
            << left << setw(10) << sv.tuoi
            << left << setw(10) << sv.diem << endl;
        return oup;
    }

    bool operator<(const SV &other) const {
        return this->diem < other.diem;
    }

    string getMsv() const {
        return msv;
    }

    string getTen() const {
        return ten;
    }

    double getDiem() const {
        return diem;
    }
};

// Quản lý danh sách sinh viên sử dụng vector
class VectorSV {
private:
    vector<SV> svs;

public:
    void addStudent(const SV& sv) {
        svs.push_back(sv);
    }

    void opList() const {
        cout << left << setw(10) << "Ma SV"
             << left << setw(20) << "Ten SV"
             << left << setw(10) << "Tuoi"
             << left << setw(10) << "Diem" << endl;
        for (const auto &sv : svs) {
            cout << sv;
        }
    }

     // Hàm thêm sinh viên vào danh sách
    void addSV() {
        SV sv;
        cout << "Nhap thong tin sinh vien moi:\n";
        cin >> sv;
        svs.push_back(sv);
    }

    void sortList() {
        sort(svs.begin(), svs.end());
    }

    SV findMax() const {
        if (svs.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return SV();
        }
        return *max_element(svs.begin(), svs.end());
    }

    SV findMin() {
        if (svs.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return SV();
        }
        return *min_element(svs.begin(), svs.end());
    }

    // Tìm kiếm sinh viên theo mã hoặc tên
    void searchStudent(const string &query) const {
        bool found = false;
        for (const auto &sv : svs) {
            if (sv.getMsv() == query || sv.getTen() == query) {
                cout << "Sinh vien tim thay:\n" << sv;
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien nao.\n";
        }
    }

    // Xóa sinh viên theo mã hoặc tên
    void deleteStudent(const string &query) {
        auto it = remove_if(svs.begin(), svs.end(), [&](const SV &sv) {
            return sv.getMsv() == query || sv.getTen() == query;
        });
        if (it != svs.end()) {
            svs.erase(it, svs.end());
            cout << "Da xoa sinh vien co ma hoac ten: " << query << endl;
        } else {
            cout << "Khong tim thay sinh vien de xoa.\n";
        }
    }
};

// Quản lý danh sách sinh viên sử dụng list
class ListSV {
private:
    list<SV> svs;

public:
    void addStudent(const SV& sv) {
        svs.push_back(sv);
    }

    void opList() const {
        cout << left << setw(10) << "Ma SV"
             << left << setw(20) << "Ten SV"
             << left << setw(10) << "Tuoi"
             << left << setw(10) << "Diem" << endl;
        for (const auto &sv : svs) {
            cout << sv;
        }
    }

    // Hàm thêm sinh viên vào danh sách
    void addSV() {
        SV sv;
        cout << "Nhap thong tin sinh vien moi:\n";
        cin >> sv;
        svs.push_back(sv);
    }

    void sortList() {
        svs.sort();
    }

    SV findMax() const {
        if (svs.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return SV();
        }
        return *max_element(svs.begin(), svs.end());
    }

    SV findMin() {
        if (svs.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return SV();
        }
        return *min_element(svs.begin(), svs.end());
    }

    // Tìm kiếm sinh viên theo mã hoặc tên
    void searchStudent(const string &query) const {
        bool found = false;
        for (const auto &sv : svs) {
            if (sv.getMsv() == query || sv.getTen() == query) {
                cout << "Sinh vien tim thay:\n" << sv;
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien nao.\n";
        }
    }

    // Xóa sinh viên theo mã hoặc tên
    void deleteStudent(const string &query) {
        auto it = remove_if(svs.begin(), svs.end(), [&](const SV &sv) {
            return sv.getMsv() == query || sv.getTen() == query;
        });
        if (it != svs.end()) {
            svs.erase(it, svs.end());
            cout << "Da xoa sinh vien co ma hoac ten: " << query << endl;
        } else {
            cout << "Khong tim thay sinh vien de xoa.\n";
        }
    }
};

// Hàm kiểm tra số cuối của mã sinh viên là chẵn hay lẻ
bool isEvenLastDigit(const string &id) {
    char lastChar = id.back();
    if (isdigit(lastChar)) {
        int lastDigit = lastChar - '0';
        return lastDigit % 2 == 0;
    }
    return false;
}

TM() {
    VectorSV vectorSV;
    ListSV listSV;

    ifstream file("input.txt");
    int n;
    if (file.is_open()) {
        file >> n;
        file.ignore();
        FOR(i, 0, n) {
            SV sv;
            file >> sv;
            if (isEvenLastDigit(sv.getMsv())) {
                vectorSV.addStudent(sv);
            } else {
                listSV.addStudent(sv);
            }
        }
        file.close();
    } else {
        cout << "Khong mo duoc file input.txt\n";
        return 1;
    }

    int choice;
    do {
        cout << "\n1. Xem danh sach sinh vien trong vector\n";
        cout << "2. Xem danh sach sinh vien trong list\n";
        cout << "3. Tim sinh vien trong vector\n";
        cout << "4. Tim sinh vien trong list\n";
        cout << "5. Xoa sinh vien trong vector\n";
        cout << "6. Xoa sinh vien trong list\n";
        cout << "7. Them sinh vien vao vector\n";
        cout << "8. Them sinh vien vao list\n";
        cout << "9. Tim sinh vien co diem thap nhat trong vector\n";
        cout << "10. Tim sinh vien co diem thap nhat trong list\n";
        cout << "11. Tim sinh vien co diem cao nhat trong vector\n";
        cout << "12. Tim sinh vien co diem cao nhat trong list\n";
        cout << "0. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vectorSV.opList();
                break;
            case 2:
                listSV.opList();
                break;
            case 3: {
                string query;
                cout << "Nhap ma hoac ten sinh vien can tim: ";
                cin.ignore();
                getline(cin, query);
                vectorSV.searchStudent(query);
                break;
            }
            case 4: {
                string query;
                cout << "Nhap ma hoac ten sinh vien can tim: ";
                cin.ignore();
                getline(cin, query);
                listSV.searchStudent(query);
                break;
            }
            case 5: {
                string query;
                cout << "Nhap ma hoac ten sinh vien can xoa: ";
                cin.ignore();
                getline(cin, query);
                vectorSV.deleteStudent(query);
                break;
            }
            case 6: {
                string query;
                cout << "Nhap ma hoac ten sinh vien can xoa: ";
                cin.ignore();
                getline(cin, query);
                listSV.deleteStudent(query);
                break;
            }
            case 7:
                vectorSV.addSV();
                break;
            case 8:
                listSV.addSV(); 
                break;
            case 9: {
                SV minSV = vectorSV.findMin();
                cout << "Sinh vien co diem thap nhat trong vector:\n" << minSV;
                break;
            }
            case 10: {
                SV minSV = listSV.findMin();
                cout << "Sinh vien co diem thap nhat trong list:\n" << minSV;
                break;
            }
            case 11: {
                SV maxSV = vectorSV.findMax();
                cout << "Sinh vien co diem thap nhat trong vector:\n" << maxSV;
                break;
            }
            case 12: {
                SV maxSV = listSV.findMax();
                cout << "Sinh vien co diem thap nhat trong list:\n" << maxSV;
                break;
            }
            case 0:
                cout << "Thoat.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
