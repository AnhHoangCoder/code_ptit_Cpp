#include <iostream>
#include <vector>

using namespace std;
using db = double;

void test_case(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    db max_value = sum * 1.0 / k;
    int max_pos = 0;

    //sliding window
    for(int i=1;i<=n-k;i++){
        sum = sum - a[i-1] + a[i+k-1];
        db tmp = sum * 1.0 / k;

        if(tmp > max_value){
            max_value = tmp;
            max_pos = i;
        }
    }
    for(int i=0;i<k;i++){
        cout << a[max_pos+i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}