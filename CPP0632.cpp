#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

class HoaDon;

int idx_kh = 0 , idx_mh = 0 , idx_hd = 0;

class KhachHang{
protected:
    string maKh , tenKh , gender , date , addr;
public:
    static KhachHang dskh[25];
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
KhachHang KhachHang::dskh[25];
int KhachHang::n=0;

class MatHang{
protected:
    string maMh , tenMh , dvt;
    int buy , pass;
public:
    static MatHang dsmh[45];
    static int n;
    friend istream &operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.maMh = "MH" + tmp.str();

        if(in.peek() == '\n') in.ignore();
        getline(in , a.tenMh);
        in >> a.dvt;
        in >> a.buy >> a.pass;
        in.ignore(numeric_limits<streamsize>::max() , '\n');

        dsmh[n++] = a;
        return in;
    }
    string get_id(){return maMh;}
    friend class HoaDon;
};
MatHang MatHang::dsmh[45];
int MatHang::n=0;

class HoaDon : public KhachHang , public MatHang{
    string id_hd , id_kh , id_mh;
    int sl;
public:
    ll loi_nhuan;
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

        a.loi_nhuan = 1LL * a.sl * (a.pass - a.buy);
        return in;
    }
    friend ostream &operator << (ostream &out , HoaDon &a){
        ll sum = 1LL*a.sl*a.pass;
        out << a.id_hd << " " << a.tenKh << " " << a.addr
            << " " << a.tenMh << " " << a.sl << " "
            << sum << " " << a.loi_nhuan << '\n';
        return out;
    }
    friend bool operator < (HoaDon &a,HoaDon &b){
        if(a.loi_nhuan != b.loi_nhuan) return a.loi_nhuan > b.loi_nhuan;
        return a.tenMh > b.tenMh;
    }
};

void sapxep(HoaDon dshd[] , int K){
    sort(dshd , dshd + K);
}

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
