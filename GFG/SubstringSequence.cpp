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

ll myFun(string &A, string &B, vvi &ans, ll i, ll j){
    //out <<i<<" "<<j << endl;
    ll n=A.size();
    ll m=B.size();
    if(i>=m || j>=n){
        return 0;
    }
    if(ans[j][i]!=-1){
        return ans[j][i];
    }
    
    ll fin=0;
    for(ll k=j;k<n;k++){
        if(A[k]==B[i]){
            fin=max(fin,myFun(A,B,ans,i+1,k+1)+1);
        }
    }
    
    return ans[j][i]=fin;
}



int main(){
    
    ll t;
    cin >> t;
    while(t--){
        string A;
        string B;
        cin >> A;
        cin >> B;
        ll n=A.size();
        ll m=B.size();
        vvi ans(n,vi(m,-1));
        ll fin=0;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                if(A[j]==B[i]){
                            //cout << "asf"<<endl;

                    fin=max(fin,myFun(A,B,ans,i+1,j+1)+1);
                }
            }
        }
        
        
       cout << fin << endl; 
    }
    
    
	return 0;
}