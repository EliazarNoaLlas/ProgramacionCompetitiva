#include<iostream>
#include<string>
using  namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    int t = 0, c = 0, o = 0, d = 0, i = 0;
    string s;
    for (int j = 0; j < n; j++){
        getline(cin, s);
        if(s[0]=='T') t+=4;
        else if(s[0]=='C') c+=6;
        else if(s[0]=='O') o+=8;
        else if(s[0]=='D') d+=12;
        else i+=20;
    }
    cout << t+c+d+o+d+i;
    return 0;
}