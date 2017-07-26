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

int main(){
    
    ll c=1000000007;
    vvi v(53,vi(27,0));
    for(ll i=1;i<=26;i++){
        v[i][1]=i;
    }
    
    for(ll i=1;i<=26;i++){
        v[1][i]=i;
        v[2][i]=i;
    }
    for(ll i=3;i<=52;i++){
        for(ll j=1;j<=26;j++){
            if(i%2==0){
                v[i][j]=v[i-1][j];
            }else{
                v[i][j]=((v[i-1][j]%c)*((j-(i/2))%c))%c;
            }
        }
    }
    
   /* for(ll i=1;i<=52;i++){
        for(ll j=1;j<=26;j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }
*/
    
    ll t;
    cin >>t;
    while(t--){
        ll a,b;
        cin >>a>>b;
        ll ans=0;
        for(ll i=1;i<=a;i++){
            ans=(ans%c+(v[i][b])%c)%c;
        }
        //cout << v[a][b]<<endl;
        cout << ans<< endl;
    }
    
	return 0;
}