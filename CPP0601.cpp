#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class SinhVien{
    string id , name , lop , date;
    float gpa;
public:
    void nhap(){
        id = "B20DCCN001";
        getline(cin , name);
        cin >> lop >> date >> gpa;
    }

    void xuat(){
        string d , m , y;
        stringstream ss(date);
        getline(ss , d , '/');
        if(d.size() == 1) d = "0" + d;
        getline(ss , m , '/');
        if(m.size() == 1) m = "0" + m;
        getline(ss , y);
        cout << id << " " << name << " " << lop << " "
        << d << "/" << m << "/" << y << " " << fixed << setprecision(2) << gpa << endl;
    }
};

int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}
