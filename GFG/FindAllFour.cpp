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
vvi fin;
void myFun(vi &v,ll i,ll count,ll sum,vi &mid){
    
    ll n=v.size();
    if(i>=n){
        return ;
    }
    sum=sum-v[i];
    if(sum<0 || count>4){
        return ;
    }
        //  cout << sum<<" "<<count<<endl;

    if(count==4 && sum==0){
        fin.pb(mid);
        return ;
    }
    for(ll j=i+1;j<n;j++){
        mid.pb(v[j]);
        myFun(v,j,count+1,sum,mid);
        mid.pop_back();
    }
    
    return;
    
}

bool myfunction(vi a,vi b){

for(ll i=0;i<a.size();i++){
    if(a[i]!=b[i]){
        return false;
    }
}
return true;

}


int main(){
    
    ll t;
    cin >>t;
    while(t--){
        fin.clear();
        ll n,z;
        cin >>n>>z;
        vi v(n);
        for(ll i=0;i<n;i++){
            cin >> v[i];
        }
        
        vi mid;
       ll sum=0;
        sort(v.begin(),v.end());
       for(ll i=0;i<n;i++){
            if(i!=0 && v[i]==v[i-1]){
                       continue;
                   }
           mid.pb(v[i]);
           sum=v[i];
           for(ll j=i+1;j<n;j++){
               if(v[j]==v[j-1] && (j-1)!=i){
                   continue;
               }
               sum+=v[j];
               mid.pb(v[j]);
               for(ll k=j+1;k<n;k++){
                   if(v[k]==v[k-1] && k-1!=j){
                       continue;
                   }
                   sum+=v[k];
                   mid.pb(v[k]);
                   for(ll p=k+1;p<n;p++){
                        if(v[p]==v[p-1] && p-1!=k){
                       continue;
                   }
                       if(sum+v[p]==z){
                           mid.pb(v[p]);
                           fin.pb(mid);
                           mid.pop_back();
                       }
                   }
                   sum-=v[k];
                   mid.pop_back();
               }
               sum-=v[j];
               mid.pop_back();
           }
           sum-=v[i];
           mid.pop_back();
       }
       
       if(fin.size()==0){
           cout << -1;
       }
        fin.erase(unique(fin.begin(),fin.end(),myfunction),fin.end());
        for(ll i=0;i<fin.size();i++){
            sort(fin[i].begin(),fin[i].end());
            for(ll j=0;j<fin[i].size();j++){
                cout << fin[i][j]<<" ";
            }
            cout <<'$';
        }
    
    cout << endl;
    }
    return 0;
}