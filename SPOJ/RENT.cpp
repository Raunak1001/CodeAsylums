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

	struct Node{

		ll a,b,c;

	};

	bool sortFun(Node a, Node b){
		if(a.a==b.a){
			return a.b<b.b;
		}
		return a.a<b.a;
	}


	ll bSearch(vector<Node> &v,ll end){

		ll n=v.size();
		ll low=0;
		ll high=n;
		while(low < high){

			ll mid=low+(high-low)/2;
			if(low==mid){
				return high;
			}
			if(v[mid].a<end){
				low=mid;
			}else{
				high=mid;
			}

		}
		return high;

	}


	int main(){
			std::ios::sync_with_stdio(false); 


			ll t;
			cin >>t;
			while(t--){

				ll n;
				cin >> n;
				vector<Node> v(n);
				for(ll i=0;i<n;i++){
					cin >>v[i].a>>v[i].b>>v[i].c;
					v[i].b+=v[i].a;
				}
				sort(v.begin(),v.end(),sortFun);
				/*for(ll i=0;i<n;i++){
					cout << v[i].a<<" "<<v[i].b<<" "<<v[i].c<< endl;
				}*/
				vi dp(n+1,0);
				dp[n-1]=v[n-1].c;
				for(ll i=n-2;i>=0;i--){
//					cout <<"bk"<< endl;

					ll temp=bSearch(v,v[i].b);
					//cout << temp<<" "<<v[i].b<< endl;
					dp[i]=max(dp[i+1],v[i].c+dp[temp]);
				}

				cout << dp[0]<< endl;
			
			}


		return 0;
	}