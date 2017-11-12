#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<double,double>
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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		while(1){

			ll n,m;
			cin>>n>> m;
			if(n==0){
				break;
			}
			vvp v(n+1);
			for(ll i=0;i<m;i++){
				ll a,b,c;
				cin >> a>>b>>c;
				v[a].pb(mp(double(c)/100.0,b));
				v[b].pb(mp(double(c)/100.0,a));
				//cout << double(c)/100.0<<" ";
					
			}

			vector<double> dis(n+1,INT_MIN);
			priority_queue<pr,vp,greater<pr> > pq;
			pq.push(mp(1.0,1));
			dis[1]=1.0;
			while(!pq.empty()){
				pr p=pq.top();
				pq.pop();
				for(ll i=0;i<v[p.second].size();i++){
					//cout << v[p.second][i].second<<" "<<dis[v[p.second][i].second] << endl;
					if(dis[v[p.second][i].second]<(dis[p.second]*v[p.second][i].first)){
						//cout <<"asdf"<< endl;
						dis[v[p.second][i].second]=dis[p.second]*v[p.second][i].first;
						pq.push(mp(dis[v[p.second][i].second],v[p.second][i].second));
					}
				}
			}

			double temp=dis[n]*100.0;
			cout << fixed;
			cout << setprecision(6);
			cout << temp<<" percent"<< endl;



		}


	return 0;
}			