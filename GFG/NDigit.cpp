#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 
vi fin;

void myFun(vvi &v, ll i, ll n){
    
    if(n==0){
        for(ll i=0;i<fin.size();i++)
        {
            cout << fin[i];
        }
        cout << endl;
        return ;
    }
    
    for(ll j=0;j<v[i].size();j++){
        fin.push_back(v[i][j]);
        myFun(v,v[i][j],n-1);
        fin.pop_back();
    }
    return ;
    
    
    
}


int main()
 {

 ll t;
 cin >>t;
 for(ll q=0;q<t;q++){
     fin.clear();
     ll n;
     cin >>n;
    vvi v(10);
    for(ll i=1;i<10;i++){
        for(ll j=i+1;j<10;j++){
            v[i].push_back(j);
        }
    }

  for(ll i=1;i<=9;i++){
    fin.push_back(i);
    myFun(v,i,n-1);
    fin.pop_back();
  }
    
    
    
 }



	return 0;
}