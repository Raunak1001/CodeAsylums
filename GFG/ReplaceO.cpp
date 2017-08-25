#include<bits/stdc++.h>
using namespace std;
#define vi vector<char>
#define vvi vector<vector<char> >
#define ll long long int 

bool myfun(vvi &v,ll i,ll j){
    
    if(i-1<0 || i+1>=v.size() || j-1<0 || j+1>=v[0].size() || v[i][j]==-1){
        v[i][j]=-1;
        return 0;
    }
    if(v[i][j]=='X'){
        return 1;
    }
    if(v[i-1][j]=='X' &&v[i][j-1]=='X' && v[i+1][j]=='X' && v[i][j+1]=='X' )
    {
        v[i][j]='X';
        return 1;
    }else{
        if(!myfun(v,i+1,j)){
    v[i][j]=-1;
    return 0;
}
if(!myfun(v,i-1,j)){
    v[i][j]=-1;
    return 0;
}

if(!myfun(v,i,j+1)){
    v[i][j]=-1;
    return 0;
}

if(!myfun(v,i,j-1)){
    v[i][j]=-1;
    return 0;
}
            
        }
        
        
    }
    
    
    



int main()
 {

ll t;
cin >>t;
for(ll q=0;q<t;q++){
ll n,m;
cin >>n>>m;
vvi v(n,vi(m));
for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        cin >> v[i][j];
    }
}

for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
       

if(v[i][j]=='O'){
    myfun(v,i,j);
}

}
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]==-1){
                v[i][j]='O';
            }
            cout << v[i][j]<<" ";
            
        }
    }
    
    cout << endl;
    
    
}

	return 0;
}