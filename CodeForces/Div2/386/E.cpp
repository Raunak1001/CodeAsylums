#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair


ll findEven(ll last, map<ll,ll> &m, ll p){

for(ll i=last+2;i<=p;i+=2){
	if(m[i]==0){
		//cout << i<< endl;
		return i;
	}
}
return -1;

}


int main(){

ll n,p;
ll ans=0;
cin >>n>>p;
vi v(n);
map<ll,ll> m;
ll countOdd=0;
ll countEven=0;
ll count=0;
for(ll i=0;i<n;i++){
	cin >> v[i];

if(m[v[i]]==0){
	if(v[i]%2==0){
		countEven++;
	}else{
		countOdd++;
	}
	m[v[i]]=1;
}else{

	m[v[i]]++;
	count++;
}

}
ll lastEven=0;
ll lastOdd=-1;
//cout << countEven<< countOdd<< endl;

for(ll i=0;i<n;i++){
if(m[v[i]]>1){
	ans++;
	m[v[i]]--;
	if(countEven>countOdd){
		v[i]=findEven(lastOdd,m,p);
		if(v[i]==-1){
			cout <<-1<<endl;
			return 0;
		}
		lastOdd=v[i];
		countOdd++;
		count--;
		m[lastOdd]=1;
	}else{
		v[i]=findEven(lastEven,m,p);
		if(v[i]==-1){
			cout <<-1<<endl;
			return 0;
		}
		lastEven=v[i];
		countEven++;
		count--;
		m[lastEven]=1;
	}
}
}
/*for(ll i=0;i<n;i++){
	cout<< v[i]<<" ";
}
cout << endl;
cout << countEven<<" "<<countOdd<< endl;
*/

if(countOdd!=countEven){

for(ll i=0;i<n;i++){
	if(countOdd>countEven){
		if(v[i]%2==0){
			continue;
		}
		ans++;
		v[i]=findEven(lastEven,m,p);
		if(v[i]==-1){
			cout <<-1<<endl;
			return 0;
		}
		lastEven=v[i];
		countOdd--;
		countEven++;
		m[lastEven]=1;
	}else if(countEven>countOdd){
		if(v[i]%2!=0){
			continue;
		}
		ans++;
		v[i]=findEven(lastOdd,m,p);
		if(v[i]==-1){
			cout <<-1<<endl;
			return 0;
		}
		lastOdd=v[i];
		countEven--;
		countOdd++;
		m[lastOdd]=1;
	}else{
		break;
	}


}



}
/*countOdd=0;
countEven=0;*/
cout << ans<< endl;
for(ll i=0;i<n;i++){
	/*if(v[i]%2==0){
		countEven++;
	}else{
		countOdd++;
	}*/
	cout<< v[i]<<" ";
}
cout << endl;
// cout<<countEven<<" "<<countOdd<<endl;



}