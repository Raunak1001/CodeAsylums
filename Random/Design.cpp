#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vp vector<pr >
#define vvp vector<vp >
#define vc vector<char>
#define vvc vector<vc  >
#define vs vector<string>
#define vvs vector<vs>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

void makeWord(vvs &v,string &s,ll i){
	string a="";
	ll j=0;
	while(j<s.size()){

		if(s[j]==' '){
			v[i][0]=a;
			a="";
			j++;
		}else{
			a+=s[j];
			j++;
		}

	}
	v[i][1]=a;
	return ;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll n;
		cin >>n;
		vvs v(n,vs(2));
		string temp;
		getline(cin,temp);
		for(ll i=0;i<n;i++){
			string s;
			getline(cin,s);
			makeWord(v,s,i);
		}
		vi a(n);
		for(ll i=0;i<n;i++){
			cin >> a[i];
			a[i]--;
		}

		temp=min(v[a[0]][0],v[a[0]][1]);
		for(ll i=1;i<n;i++){
			string s1=v[a[i]][0];
			string s2=v[a[i]][1];
			if(s1>s2){
				swap(s1,s2);
			}
			if(s1>temp){
				temp=s1;
				continue;
			}else if(s2>temp){
				temp=s2;
				continue;
			}else{
				cout <<"NO"<< endl;
				return 0;
			}

		}

		cout << "YES"<< endl;


	return 0;
}			