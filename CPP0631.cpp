#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;
using ll = long long;

int idx_kh = 0, idx_mh = 0 , idx_hd = 0;

class HoaDon;

class KhachHang{
protected:
    string maKh , tenKh , gender , date , addr;
public:
    static KhachHang dskh[25];
    static int n;
    friend istream& operator >> (istream &in , KhachHang &a){
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
    string get_id(){
        return maKh;
    }
    friend class HoaDon;
};

KhachHang KhachHang::dskh[25];
int KhachHang::n = 0;

class MatHang{
protected:
    string  maMh , tenMh , dvt;
    ll buy , pass;
public:
    static MatHang dsmh[45];
    static int n;
    friend istream& operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.maMh = "MH" + tmp.str();
        if(in.peek() == '\n') in.ignore();

        getline(in , a.tenMh);
        in >> a.dvt >> a.buy >> a.pass;
        dsmh[n++] = a;
        return in;
    }
    string get_id(){
        return maMh;
    }
    friend class HoaDon;
};

MatHang MatHang::dsmh[45];
int MatHang::n = 0;

class HoaDon : public KhachHang , public MatHang{
    string maHd;
    string id_Kh , id_Mh;
    int sl;
public:
    friend istream& operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_hd;
        a.maHd = "HD" + tmp.str();

        in >> a.id_Kh >> a.id_Mh >> a.sl;

        for(int i=0;i<KhachHang::n;i++){
            if(KhachHang::dskh[i].get_id() == a.id_Kh){
                //ép kiểu hóa đơn về khách hàng và gán bằng đối tượng tìm được
                //dòng này thay cho việc gán thủ công a.name = ... ,a.addr = 
                (KhachHang&)a = KhachHang::dskh[i];
                break;
            }
        }

        for(int i=0;i<MatHang::n;i++){
            if(MatHang::dsmh[i].get_id() == a.id_Mh){
                (MatHang&)a = MatHang::dsmh[i];
                break;
            }
        }   
        return in;
    }
    friend ostream& operator << (ostream &out , HoaDon &a){
        ll sum = (ll)a.sl * a.pass;
        //vì tên biến cha khác nhau nên ta gọi trực tiếp thay vì gọi vi ::
        out << a.maHd << " " << a.tenKh << " " <<
        a.addr << " " << a.tenMh << " " << a.dvt << " "
        << a.buy << " " << a.pass << " " << a.sl << " "
        << sum << "\n";
        return out;
    }  
};

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
    
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}