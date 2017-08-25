#include<bits/stdc++.h>
using namespace std;
#define vi vector<pair<long long int,long long int> >
#define vvi vector<vector<long long int> >
#define ll long long int 

bool myfun(pair<ll,ll> &a,pair<ll,ll> &b){
    return a.first<b.first;
}


int main()
 {
	ll t;
	cin >>t;
	for(ll q=0;q<t;q++){
	    ll n;
	    cin >>n;
	    vi v(n);
	    ll b,c,a;
	    ll count=0;
	    set<ll> s;
	    for(ll i=0;i<n;i++){
	        cin >>a>>b>>c;
	        v[i]=make_pair(b,c);
	        s.insert(b);
	    }
	    	   // cout <<"fasdfds"<<endl;

	    sort(v.begin(),v.end(),myfun);
/*for(ll i=0;i<n;i++){
	cout << v[i].first<<" "<<v[i].second<<endl;
}
	*/    ll mx=0,curr=0,prv=0;
	    ll time=0;
	    for(ll i=0;i<n;i++){
	    	
	        if(time<v[i].first){
	            if(prv==0){
	            	count++;
	                prv=v[i].first;
	                curr=v[i].second;
	                
	            }else{
	                if(v[i].first==prv){
	                    curr=max(curr,v[i].second);
	                    	                //mx=max(curr,mx);
	                }else{
	                    time++;
                        mx=mx+curr;                   ;
	                    prv=0;
	                    i--;
	                   // cout <<i<<endl;	
	                }
	            }
	            
	            
	        }
	        
	        //mx=max(mx,curr);
	        
	    }
	    // cout <<endl;
	    cout << count<<" "<<mx+curr<<endl;
	}
	return 0;
}