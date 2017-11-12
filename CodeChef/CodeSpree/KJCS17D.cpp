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
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

bool isValid(char c){

	if(c>='a' && c<='z'){
		return 1;
	}
	return 0;


}
void toLower(string &s,vb &visited){


	for(ll i=0;i<s.size();i++){
					if(s[i]>='A' && s[i]<='Z'){
						char c=s[i];
						c=(c-'A')+'a';
						s[i]=c;
						visited[i]=1;
					}

				}

}

char myFun(char a,ll b){
	//	cout <<b<<" "<<a<< endl;
	ll temp;
	if(b>(a-'a')){
		temp=b-(a-'a');
		temp=26-temp;
	}else{
		temp=(a-'a')-b;
		
	}
	return char(temp+'a');

}

void toUpper(string &s,vb &visited){
	for(ll i=0;i<s.size();i++){
		if(visited[i]){
			char c=s[i];
			c=(c-'a')+'A';
			s[i]=c;
		}
	}
}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

			ll t;
			cin >> t;
			while(t--){
				string a,b;
				cin >>a>>b;
				ll l;
				cin >> l;
				string s="";
				ll i=0;
				ll count=0;
				vb visited(a.size(),0);
					toLower(a,visited);
					toLower(b,visited);


				while(count<l){
					if(isValid(a[i])){
						ll temp=0;
						if(b[i]>=a[i]){
							temp=b[i]-a[i];
						}
						else{
							temp=(25-(a[i]-'a')+(b[i]-'a')+1);
						}
						s+=(temp+'0');
						count++;
						
					}
					i++;


				}
				//cout << s<< endl;
				ll q;
				cin >> q;
				string f;
				getline(cin,f);
					while(q--){
					string p;
					getline(cin,p);
					//cout <<p<< endl;
					vb visited(p.size(),0);
					toLower(p,visited);
					ll j=0;
					for(ll i=0;i<p.size();i++){
						if(j>=l){
							j=0;
						}
						if(isValid(p[i])){

							p[i]=myFun(p[i],s[j]-'0');
							j++;
						}
						//cout << p[i];
					}
					toUpper(p,visited);
					cout << p<< endl;
				}

			}


	return 0;
}			