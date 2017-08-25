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

bool myFun(ll a,ll b)
{

if(a==1 && b==1){
	return 1;
}
if(a==0 || b==0){
	return 0;
}

ll k=sqrt(max(a,b));

for(ll i=k;i>1;i--){
	ll temp=0;
			if(b%i==0 && a%(i*i)==0){
				temp=myFun(b/i,a/(i*i));
			if(temp==1){
				return 1;
			}
		}

			if(b%(i*i)==0 && a%(i)==0){
				temp=myFun(b/(i*i),a/i);
			if(temp==1){
				return 1;
			}
		}

			

	}

return 0;


}


int main(){
	
	ll n;
	cin >>n;
	while(n--){
		ll a,b;
		cin >>a>>b;	
		ll k=sqrt(max(a,b));
		ll end=1;
ll temp2=0;
//cout <<k<< end<<endl;
//cout <<k<<" "<<end<<endl;
		for(ll i=k;i>=end;i--){
			ll temp=0;
			//cout <<"safd"<< endl;
			if(b%i==0 && a%(i*i)==0){
				temp=myFun(b/i,a/(i*i));
			if(temp==1){
				cout <<"Yes"<< endl;
				temp2=1;
				break;
			}
		}

			if(b%(i*i)==0 && a%(i)==0){
				temp=myFun(b/(i*i),a/i);
			if(temp==1){
				cout <<"Yes"<< endl;
				temp2=1;
				break;
			}
		}

			if(temp2){
				break;
			}

	}
	if(!temp2){
		cout <<"No"<< endl;
	}
}


	return 0;
}