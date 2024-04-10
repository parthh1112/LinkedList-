#include <bits/stdc++.h>
using namespace std;
int divide(int x){
    int cnt = 0;
    while(x != 0){
        x /= 2;
        cnt++;
    }
    // cout<<cnt<<endl;
    return cnt;
}
int main (){
    int n;cin>>n;
    int a,b;cin>>a>>b;
    vector<vector<int>> v;
    for(int i=0;i<a;i++){
        vector<int> help;
        for(int i=0;i<b;i++){
            int x;cin>>x;
            help.push_back(x);
        }
        v.push_back(help);
    }
    int i =0,j=0;
    while(n--){
        int x = v[i][0];
        int y = v[i][1];
        int a1,a2;
        if(x % 2 ==0 && y % 2 == 0){
            a1 = divide(x);
            a2 = divide(y);
            // cout<<"ok";
            cout<<a1+a2<<" ";
        }
        else if(x % 2 == 0 && y % 2 != 0){//
             a1 = divide(x);
             a1 = divide(y-1);
            cout<<a1+a2<<" ";
        }
        else if(x % 2 != 0 && y % 2 == 0){
            a1 = divide(x-1);
             a2 = divide(y);
            cout<<a1+a2+1<<" ";
        }
        else{//
             a1 = divide(x-1);
            a2 = divide(y-1);
            cout<<a1+a2-1<<" ";
        }
        i++;
    }
    return 0;    
}