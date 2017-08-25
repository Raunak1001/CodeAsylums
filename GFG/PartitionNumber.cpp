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

ll getNum(string &s,ll start,ll end){
    
    ll a=1;
    a=s[start]-'0';
   // cout << a<< endl;
    for(ll i=start+1;i<=end;i++){
        a*=10;
        a+=s[i]-'0';
    }
    return a;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >>s;
        ll a,b;
        cin >>a>>b;
        ll  n,m;
         n=s[0]-'0';
        ll p=s.size();
        if(p==1){
            cout << -1<< endl;
            continue;
        }
         m=getNum(s,1,p-1);
//cout << n<< " "<<m<< endl;
        if(n%a==0 && m%b==0){
            cout << n<<" "<<m<< endl;
            continue;
        }
        ll temp=0;
        for(ll i=1;i<p-1;i++){
            n*=10;
            n+=s[i]-'0';
            m-=(s[i]-'0')*(pow(10,p-i-1));
            //cout << n<<" "<<m<< endl;
            if(n%a==0 && m%b==0){
            for(ll j=0;j<=i;j++){
                cout << s[j];
            }
            cout <<" ";
            for(ll j=i+1;j<p;j++){
                cout << s[j];
            }
            temp=1;
            break;
        }
        }
    
    if(!temp){
        cout << -1;
    }
    cout << endl;
        
        
        
    }
    
    
	return 0;
}