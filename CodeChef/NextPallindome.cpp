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
#define show(a) rep(i,a,b){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

string myFun(string &s){

ll n=s.size();
ll start=(n/2)-1;
ll end=n/2;
ll temp=0;
if(n%2!=0){
end=(n/2)+1;
temp=s[n/2]-'0';
if(temp!=9){
	temp++;
	s[n/2]=(temp+'0');
	return s;
}
}

while(start>=0 && end<n){
	temp=s[start]-'0';
	if(temp!=9){
		temp++;
		s[start]=s[end]=(temp+'0');
		start++;
		while(start!=end){
			s[start]=(0+'0');
			start++;
		}
		return s;
	}
	start--;
	end++;
}

string a="1";
n--;
while(n--){
	a+='0';
}
a+='1';
return a;





}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		ll t;
		cin >>t;
		while(t--){
			string s;
			cin >>s;
			ll n=s.length();
			
			ll start,end;
			if(n%2!=0){
				start=(n/2)-1;
				end=(n/2)+1;
			}else{
				start=(n/2)-1;
				end= n/2;
			}
			bool hasIncreased=0;
			bool hasDecreased=0;
			while(start>=0 && end<n){
				if(s[start]>s[end] && hasDecreased==0){
					hasIncreased=1;
				}else if(s[start]<s[end]){
					hasDecreased=1;
				}
				s[end]=s[start];
				start--;
				end++;
			}
			if(hasIncreased){
				ct(s);
				continue;
			}else{
				ct(myFun(s));
			}


		}


	return 0;
}		