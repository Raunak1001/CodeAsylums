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
ll c=1000000007;
int main(){
	
	ll t;
	cin >>t;
	while(t--){
		string s;
		cin >>s;
		ll n=s.size();
		vi v(n,0);
		ll sum=1;
		map<char,ll> m;
		if(n==0){
			cout <<1<< endl;
			continue;
		}

		v[n-1]=1;
		for(ll i=n-2;i>=0;i--){
			v[i]=(sum- m[s[i]]+1)%c;
			if(v[i]<0){
				v[i]+=c;
			}
			if(m[s[i]]!=0 || s[i]==s[n-1]){
				v[i]--;
			}
			m[s[i]]=sum%c;
			sum=(sum%c + v[i]%c)%c;
		}

		cout << (sum+1)%c<< endl;
	}



	return 0;
}