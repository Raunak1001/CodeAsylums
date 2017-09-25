#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >


ll myFun(string &s,vector<map<string,ll> > &v,ll i,string temp){
	//cout << i<< endl;	
	ll n=s.size();
	if(i>=n){
		return 0;
	}

	if(v[i].find(temp)!=v[i].end()){
		return v[i][temp];
	}
	//cout <<"sdf"<< endl;
	ll count=myFun(s,v,i+1,temp)+1;
	//cout <<i<<" ";
	for(ll k=0;k<i;k++){

		if(s[k]==s[i]){
			//cout <<k<<" "<<i<< endl;
			ll j=k;
			ll l=i;
			string a="";
			while(l<n && j<i && s[j]==s[l]){
				//cout <<l<<" "<<i<<endl;
				a+=s[l];
				j++;
				l++;
				//cout << a<< endl;
				if(a.size()>1){
					//cout <<"jhhjhjgh"<< endl;
				count=min(count,myFun(s,v,l,a)+2);
			}
			}
			//cout <<k<<" "<<i<< endl;
		}

	}
ll l=i;
ll flag=0;
	for(ll j=0;j<temp.size();j++){
		//cout <<"gghhj"<< endl;
	if(l>=n || s[l]!=temp[j]){
		flag=1;
		break;
	}
	l++;
}

if(!flag && temp.size()!=0){
	count=min(count,myFun(s,v,l,temp)+1);
}

return v[i][temp]=count;
}


int main(){
		std::ios::sync_with_stdio(false); 


		ll t;
		cin >>t;
		ll p=1;
		while(t--){
			string s;
			cin >>s;
			ll n=s.size();
			vector<map<string,ll> > v(n);
			string temp="";
		cout << "Case #"<<p<<": "<<myFun(s,v,0,temp) << endl;

		p++;
		}


	return 0;
}