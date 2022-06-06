#include <bits/stdc++.h>
using namespace std;

typedef struct data_t{
    int selisih;
    int patung;
    int guci;
    string nama;
}data;

struct Compare {
    bool operator()(data a, data b){
        if(a.selisih == b.selisih){
            if(a.patung == b.patung){
                if(a.guci == b.guci) return a.nama > b.nama;
                else return a.guci>b.guci;
            }
            else return a.patung>b.patung;
        }
        else return a.selisih>b.selisih;
    }
};

int main() {
    // m = guci, n = patung
    int t, m, n;
    cin >> t >> m >> n;
    vector<data> datas(t);
    
    for(int i=0; i<t; i++) {
        cin>>datas[i].nama>>datas[i].guci>>datas[i].patung;
        datas[i].selisih = datas[i].patung - datas[i].guci;
    } if(t < m + n) {
        cout<<"-1\n";
        return 0;
    }
    
    vector<string> patung(n, "");
    vector<string> guci(m, "");
    
    sort(datas.begin(), datas.end(),Compare());
    
    int score = 0;
    
    for(int i = 0; i < n; i++) {
        patung[i] = datas[i].nama;
        score += datas[i].patung;
    }
    for(int i = t - 1; i >= t - m; i--) {
        guci[t - i - 1] = datas[i].nama;
        score += datas[i].guci;
    }
    
    for(int i = n; i < t - m; i++){
        if(datas[i].selisih >= 0) {
            patung.push_back(datas[i].nama);
            score += datas[i].patung;
        }
        else {
            guci.push_back(datas[i].nama);
            score += datas[i].guci;
        }
    }
    
    sort(patung.begin(), patung.end());
    sort(guci.begin(), guci.end());
    
    cout << score << endl;
    for(int i = 0; i < patung.size(); i++) cout<<patung[i]<<" ";
    for(int i = 0;i < guci.size(); i++) cout<< guci[i] <<" ";
    
}
