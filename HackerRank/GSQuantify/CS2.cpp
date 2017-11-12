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

vi dist(10000000,0),E(10000000,0),firstOccur(10000000,-1),lastOcur(1000000,0),sum(1000000,0);
ll totalSum=0;
ll ind=0;

void dfs(ll temp,vvi &v,ll par,vi &s){
	totalSum+=s[temp];
	E[ind]=temp;
	if(firstOccur[temp]==-1){
		firstOccur[temp]=ind;
	}
	if(par!=-1){
		dist[temp]=dist[par]+1;
		sum[temp]=totalSum;
	}
	ind++;

	for(ll i=0;i<v[temp].size();i++){
		if(v[temp][i]!=par){
			dfs(v[temp][i],v,temp,s);
			E[ind]=temp;
			ind++;
		}
	}
E[ind]=temp;
lastOcur[temp]=ind;
ind++;
}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >> n;
		vi s(n+1);
		for(ll i=0;i<n;i++){
			cin >> s[i+1];
		}
		vvi v(n+1);
		for(ll i=0;i<n-1;i++)
		{
			ll a,b;
			cin >>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}

		ll countA=0,countB=0,sumA=0,sumB=0;
		ind =0;
		dist[1]=0;
		sum[1]=s[1];
		dfs(1,v,-1,s);
		ll q;
		cin >> q;

		for(ll i=0;i<13;i++){
			cout << E[i]<<" ";
		}
		cout << endl;

		for(ll i=1;i<=n;i++){
			cout <<firstOccur[i]<< " ";
		}
		cout << endl;
		for(ll i=1;i<=n;i++){
			cout <<lastOcur[i]<< " ";
		}
		cout << endl;
		for(ll i=1;i<=n;i++){
			cout <<sum[i]<< " ";
		}
		cout << endl;
		while(q--){
			ll a,b;
			cin >> a>> b;
			ll first;
			ll second;
			ll temp=0;

			if(lastOcur[a]<firstOccur[b]){
				first=lastOcur[a];
				second=firstOccur[b];
			}else{
				first=firstOccur[b];
				second=firstOccur[a];
				temp=1;
			}

			/*if(first>second){
				swap(first,second);
				temp=1;
			}*/
			while(lastOcur[E[first]]<second && lastOcur[E[first]]!=first){
						first=lastOcur[E[first]];
				}

			while(firstOccur[E[second]]>first && firstOccur[E[second]]!=second){
						second=firstOccur[E[second]];
					}

			//cout << E[first]<<" "<< second<< endl;
					cout <<"SAd"<< endl;
				cout << first<< second<<" "<<temp<<endl;
			ll prev=second;
			while(first<second){

				if(temp==0){
					first++;
					while(lastOcur[E[first]]<second && lastOcur[E[first]]!=first){
						first=lastOcur[E[first]]+1;
					}
					if(first==second){
						break;
					}
					//cout << first<< endl;
					prev=second;
					second--;
					while(firstOccur[E[second]]>first && firstOccur[E[second]]!=second){
						second=firstOccur[E[second]]-1;
					}
					if(first==second){
						first=prev;
						break;
					}
				}else{
					prev=second;
					second--;
					while(firstOccur[E[second]]>first && firstOccur[E[second]]!=second){
						second=firstOccur[E[second]];
					}
					if(first==second){
						first=prev;
						break;
					}
					first++;
					while(lastOcur[E[first]]<second && lastOcur[E[first]]!=first){
						first=lastOcur[E[first]];
					}
					if(first==second){
						break;
					}
				}


			}
			cout << first<< endl;
			ll valueFirst,valueSecond;
			
				valueFirst=sum[E[first]]-s[E[first]];
				valueSecond=totalSum - valueFirst;
				cout <<" f saf "<<valueFirst<< endl;
			if(temp){
				if(valueSecond>=valueFirst){
					countA++;
				}else{
					countB++;
				}
				sumA+=valueSecond;
					sumB+=valueFirst;
			}else{
				if(valueSecond>valueFirst){
					countB++;
				}else{
					countA++;
				}
				sumA+=valueFirst;
				sumB+=valueSecond;


			}

		cout <<countA <<" "<<countB<<" "<<sumA<<" "<<sumB<< endl;


		}

		cout <<countA <<" "<<countB<<" "<<sumA<<" "<<sumB<< endl;


	return 0;
}			