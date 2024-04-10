#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
void merge(vi &v,int &l,int &r){
    int m = l + (r-l)/2;
    int a1 = l;
    int a2 = m+1;


    while(a1 < m+1 && a2 < r){
        if(v[a1] > v[a2]){
            swap(v[a1],v[a2]);
            a1++;
        }
        else if(v[a1] < v[a2]){
            swap(v[a1],v[a2]);
            a2++;
        }
        else{
            a1++;
        }
    }

    while(a1 < m+1){

    }

    

}
void mergesort(vi &v,int l,int r){
    if(l >= r)return ;
    int m = l + (r-l)/2;
    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,r);
}
int main(){
    int n;cin>>n;
    vi v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.pb(x);
    }
    cout<<"BEFORE -> ";
    for(auto i : v)cout<<i<<" ";cout<<endl;



    mergesort(v,0,v.size()-1);





    cout<<"AFTER -> ";
    for(auto i : v)cout<<i<<" ";cout<<endl;



return 0;
}