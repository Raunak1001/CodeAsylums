#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int  DFS(vvi &g,ll src,ll dest,ll index,vi visited){
    
    if(index==dest){
        return true;
    }
    visited[index]=1;
    for(ll i=0;i<g[index].size();i++){
        if(!visited[g[index][i]]){
        if(DFS(g,src,dest,g[index][i],visited)){
            return true;
        }
        }
    }
    return false;
    
}



int main()
 {
ll t;
cin >>t;
for(ll q=0;q<t;q++){
ll n;
cin >>n;
ll src;
ll dest;
vvi v(n,vi(n));
for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
    cin >>v[i][j];
    if(v[i][j]==0){
        v[i][j]=3;
    }else if(v[i][j]==3){
        v[i][j]=0;
    }
    if(v[i][j]==1){
        src=i*n+j;
    }
    if(v[i][j]==2){
        dest=i*n+j;
    }
    }
}
/*cout << src<<" "<<dest<<endl;
for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
 cout << v[i][j]<<" ";
    }
    cout << endl;
}*/



vvi g(n*n);
for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        if(v[i][j]==3){
            continue;
        }
        ll temp=i*n+j;
        if(i-1>=0 && v[i-1][j]!=3){
            g[temp].push_back((i-1)*n+j);
        }
        if(i+1<n && v[i+1][j]!=3){
                        g[temp].push_back((i+1)*n+j);
        }
        if(j-1>=0 && v[i][j-1]!=3){
            g[temp].push_back((j-1)+i*n);
        }
        if(j+1<n && v[i][j+1]!=3){
                        g[temp].push_back((j+1)+i*n);
        }
        
        
        
    }
    
}

/*for(ll i=0;i<n*n;i++){
    cout <<"ver "<<i<<" ";
    for(ll j=0;j<g[i].size();j++){
        cout << g[i][j]<<" ";
    }
    cout << endl;
}*/


vi visited(n*n,0);
cout << DFS(g,src,dest,src,visited)<<endl;;



    
}


	return 0;
}