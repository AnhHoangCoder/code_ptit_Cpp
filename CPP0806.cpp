#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

ifstream in_kh("KH.in");
ifstream in_mh("MH.in");
ifstream in_hd("HD.in");

int idx_kh = 0 , idx_mh = 0 , idx_hd = 0;

class HoaDon;

class KhachHang{
protected:
    string maKh , tenKh , gender , date , addr;
public:
    static KhachHang dskh[21];
    static int n;
    friend istream &operator >> (istream &in , KhachHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_kh;
        a.maKh = "KH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.tenKh);
        in >> a.gender >> a.date;
        in.ignore(numeric_limits<streamsize>::max() , '\n');
        getline(in , a.addr);
        dskh[n++] = a;
        return in;
    }
    string get_id(){return maKh;}
    friend class HoaDon;
};

KhachHang KhachHang::dskh[21];
int KhachHang::n=0;

class MatHang{
protected:
    string maMh , tenMh , dvt;
    int buy , pass;
public:
    static MatHang dsmh[41];
    static int n;
    friend istream &operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.maMh = "MH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.tenMh);
        in >> a.dvt >> a.buy >> a.pass;
        in.ignore(numeric_limits<streamsize>::max() , '\n');
        dsmh[n++] = a;
        return in;
    }
    string get_id(){ return maMh;}
    friend class HoaDon;
};

MatHang MatHang::dsmh[41];
int MatHang::n=0;

class HoaDon : public KhachHang , public MatHang{
    string id_hd , id_kh , id_mh;
    int sl;
public:
    friend istream &operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_hd;
        a.id_hd = "HD" + tmp.str();
        in >> a.id_kh >> a.id_mh >> a.sl;

        for(int i=0;i<KhachHang::n;i++){
            if(KhachHang::dskh[i].get_id() == a.id_kh){
                (KhachHang&)a = KhachHang::dskh[i];
                break;
            }
        }

        for(int i=0;i<MatHang::n;i++){
            if(MatHang::dsmh[i].get_id() == a.id_mh){
                (MatHang&)a = MatHang::dsmh[i];
                break;
            }
        }
        return in;
    }
    friend ostream &operator << (ostream &out , HoaDon a){
        ll sum = 1LL*a.sl*a.pass;
        out << a.id_hd << " " << a.tenKh << " " << a.addr << " " <<
        a.tenMh << " " << a.dvt << " " << a.buy << " "
        << a.pass << " " <<  a.sl << " " << sum << endl;
        return out;
    }
};

int main(){
    int n,m,k;
    in_kh >> n;
    KhachHang dskh[n];
    for(int i=0;i<n;i++){
        in_kh >> dskh[i];
    }

    in_mh >> m;
    MatHang dsmh[m];
    for(int i=0;i<m;i++){
        in_mh >> dsmh[i];
    }
    
    in_hd >> k;
    HoaDon dshd[k];
    for(int i=0;i<k;i++){
        in_hd >> dshd[i];
    }

    for(int i=0;i<k;i++){
        cout << dshd[i];
    }
    return 0;
}
