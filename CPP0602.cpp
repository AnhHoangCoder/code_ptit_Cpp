#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class SinhVien{
    string id , name , lop , date;
    float gpa;
public:
    friend istream &operator >> (istream &in , SinhVien &a){
        a.id = "B20DCCN001";
        getline(in , a.name);
        in >> a.lop >> a.date >> a.gpa;
        return in;
    }
    friend ostream &operator << (ostream &out , SinhVien a){
        string day , mon , year;
        stringstream ss(a.date);
        
        getline(ss , day , '/');
        if(day.size() == 1) day = "0" + day;

        getline(ss , mon , '/');
        if(mon.size() == 1) mon = "0" + mon;

        getline(ss , year);
        out << a.id << " " << a.name << " " <<
        a.lop << " " << day << "/" << mon << "/"
        << year << " " << fixed << setprecision(2)
        << a.gpa << endl;
        return out;
    }
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}
