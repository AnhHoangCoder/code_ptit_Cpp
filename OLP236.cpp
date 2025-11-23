#include <iostream>
#include <string>

using namespace std;

#define Max 1000000

int near_palindrome(int n){
    string s = to_string(n);
    int l = s.size();

    int cnt = 0;
    for(int i=0;i<l/2;i++){
        if(s[i] != s[l-i-1]) cnt++;
        if(cnt > 1) return 2; //kết thúc sớm để tránh lãng phí time
    }
    return cnt;
}

int is_good[Max+1];
int pref[Max+1];

void test_case(){
    int a,b;
    cin >> a >> b;
    cout << pref[b] - pref[a-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1;i<=Max;i++){
        //nếu là 2 thì nó sẽ = 0
        is_good[i] = (near_palindrome(i) <= 1);
    }
    //dùng pref để tính tổng số no thỏa mãn
    pref[0] = 0;
    for(int i=1;i<=Max;i++){
        pref[i] = pref[i-1] + is_good[i];
    }

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}