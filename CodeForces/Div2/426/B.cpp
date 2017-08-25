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
	
	ll n,k;
	cin >>n>>k;
	string s;
	cin >>s;
	map<char,ll> m;
	//ll n=s.size();
	for(ll i=0;i<n;i++){
		m[s[i]]++;
	}

	ll gate=0;
	vi visited(27,0);
	for(ll i=0;i<n;i++)
	{
		char a=s[i];
		m[s[i]]--;
		if(!visited[a-'A']){
			gate++;
			visited[a-'A']=1;
		}
		if(gate>k){
			cout<<"YES"<<endl;
			return 0;
		}
		if(m[a]==0){
			gate--;
		}

	}

	cout <<"NO"<< endl;


	return 0;
}