#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair        
#define pb push_back


bool str(string &a, string &b){
    return a<b;
}

bool isValid(ll i,ll j, ll n, ll m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
    
}

void setVisited(vvi &v){
    ll n= v.size();
    ll m=v[0].size();
    for(ll i=0;i<n;i++){
       for(ll j=0;j<m;j++){
           v[i][j]=0;
       }
    }
}
int myFun(string &s,vvi &visited,vvc &g,ll i,ll j,ll k){
   // cout << i<<" "<<j<<" "<<k<< endl;

    if(k>=s.size()){
        return 1;
    }
    if(s[k]!=g[i][j]){
        return 0;
    }
    if(s[k]==g[i][j] && k==s.size()-1){
        return 1;
    }
       // cout << g[i][j]<< endl;

visited[i][j]=1;


    ll n=g.size();
    ll m=g[0].size();
    int fin=0;
    if(fin!=1 && isValid(i+1,j,n,m) && !visited[i+1][j]){
            fin|=myFun(s,visited,g,i+1,j,k+1);
    }
    if(fin!=1 && isValid(i-1,j,n,m) && !visited[i-1][j]){
            fin|=myFun(s,visited,g,i-1,j,k+1);
    }
    if(fin!=1 && isValid(i+1,j+1,n,m) && !visited[i+1][j+1]){
            fin|=myFun(s,visited,g,i+1,j+1,k+1);
    }
    if(fin!=1 && isValid(i+1,j-1,n,m) && !visited[i+1][j-1]){
            fin|=myFun(s,visited,g,i+1,j-1,k+1);
    }
    if(fin!=1 && isValid(i,j+1,n,m) && !visited[i][j+1]){
            fin|=myFun(s,visited,g,i,j+1,k+1);
    }
    if(fin!=1 && isValid(i,j-1,n,m) && !visited[i][j-1]){
       // cout << k<< endl;
            fin|=myFun(s,visited,g,i,j-1,k+1);
    }
    if(fin!=1 && isValid(i-1,j-1,n,m) && !visited[i-1][j-1]){
            fin|=myFun(s,visited,g,i-1,j-1,k+1);
    }
    if(fin!=1 && isValid(i-1,j+1,n,m) && !visited[i-1][j+1]){
            fin|=myFun(s,visited,g,i-1,j+1,k+1);
    }
    
    return fin;
    
}



int main(){
    
    ll t;
    cin >>t;
    
    while(t--){
        
        ll n;
        cin >> n;
        map<string,int> mymap;
        vector<string> v;
        for(ll i=0;i<n;i++){
            string s;
            cin >> s;
            if(mymap[s]==0){
            v.pb(s);
            
                mymap[s]++;
            }
        }
        ll m;
       // v.erase(unique(v.begin(),v.end()));
        cin >> n>> m;
        vvc c(n,vc(m));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin >> c[i][j];
            }
        }
       /* vvc g(n*m);
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ll temp=i*m+j;
                if(isValid(i+1,j,n,m)){
                    g[temp].pb((i+1)*m+j);
                }
                if(isValid(i-1,j,n,m)){
                    g[temp].pb((i-1)*m+j);
                }
                if(isValid(i+1,j+1,n,m)){
                    g[temp].pb((i+1)*m+j+1);
                }
                if(isValid(i+1,j-1,n,m)){
                    g[temp].pb((i+1)*m+j-1);
                }
                if(isValid(i,j+1,n,m)){
                    g[temp].pb((i)*m+j+1);
                }
                if(isValid(i,j-1,n,m)){
                    g[temp].pb((i)*m+j-1);
                }
                 if(isValid(i-1,j-1,n,m)){
                    g[temp].pb((i-1)*m+j-1);
                }
                 if(isValid(i-1,j+1,n,m)){
                    g[temp].pb((i-1)*m+j+1);
                }
                
                
            }
        }*/
        vector<string> ans;
        ll temp=0;
        vvi visited(n,vi(m,0));
        for(ll i=0;i<v.size();i++){
            string s=v[i];
           // cout << s<< endl;
            temp=0;
           for(ll j=0;j<n;j++){
               for(ll k=0;k<m;k++){
                   if(s[0]==c[j][k]){
                   if(myFun(s,visited,c,j,k,0)){
                       ans.pb(s);
                       temp=1;
                       break;
                   }
                       setVisited(visited);

               }
               }
               if(temp){
                   break;
               }
           }
            
        }
        
        if(ans.size()!=0){
            //ans.erase(unique(ans.begin(),ans.end()));
            sort(ans.begin(),ans.end());
            for(ll i=0;i<ans.size();i++){
                cout << ans[i]<<" ";
            }
        }else{
            cout << -1;
        }
        cout << endl;
        
        
    }
    
    return 0;
}