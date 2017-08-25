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

bool myFun(pr a,pr b){
	return a.first<b.first;
}


int main(){
		std::ios::sync_with_stdio(false); 

		ll m;
		cin >>m;
		vi a(m);
		vp b(m);
		for(ll i=0;i<m;i++){
			cin >>a[i];
		}
		ll temp;
		for(ll i=0;i<m;i++){
			cin >> temp;
			b[i]=mp(temp,i);
		}

		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),myFun);
/*for(ll i=0;i<m;i++){
	cout <<b[i].first<<" "<<b[i].second<< endl;
}
*/
		vi v(m);
		for(ll i=0;i<m;i++){
			v[b[m-1-i].second]=a[i];
		}
		a.clear();
		b.clear();
		for(ll i=0;i<m;i++){
			cout << v[i]<< " ";
		}

	return 0;
}