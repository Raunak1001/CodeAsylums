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
    
    ll t;
    cin >>t;
    while(t--){
        string s;
        cin >>s;
        ll q;
        cin >>q;
        ll n=s.size();
        vvi v(n,vi(27,0));
        
        int temp=s[0]-'a';
        v[0][temp]=1;
        for(ll i=1;i<n;i++){
            v[i]=v[i-1];
            temp=s[i]-'a';
            v[i][temp]++;
        }

        /*for(ll i=0;i<n;i++){
            for(ll j=0;j<=26;j++){
                cout<<v[i][j]<<" ";
            }
            cout << endl;
        }*/

        for(ll i=0;i<q;i++){
            ll a,b;
            cin >>a>>b;
            ll count=0;
            for(ll j=0;j<=26;j++){
                if(a>=2){
                temp=v[b-1][j]-v[a-2][j];
                }else{
                    temp=v[b-1][j];
                }
                if(temp>=1){
                    count++;
                }
            }
            cout << count<<" ";
        }
        cout << endl;


    }
    
    
    
	return 0;
}