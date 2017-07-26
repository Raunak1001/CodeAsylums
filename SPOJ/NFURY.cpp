#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair


int main(){

ll t;
cin >> t;
vi s;
ll a=1;
while(1){
	ll temp=a*a;
	if(temp>1000){
	break;
	}else{
		s.push_back(temp);
	}
	a++;
}
/*for(ll i=0;i<s.size();i++){
	cout << s[i]<<" ";
}*/
vi ans(1001,1000000);
ans[0]=0;
ans[1]=1;
for(ll i =1;i<1001;i++){
	for(ll j=0;j<s.size();j++){
		if(s[j]>i){
			break;
		}
if(i==s[j]){
	ans[i]=1;
	break;
}
		ans[i]=min(ans[i],ans[i-s[j]]+ans[s[j]]);
	}
// cout << ans[i]<< " ";

}



for(ll q=0;q<t;q++){

ll n;
cin >>n;
cout << ans[n]<< endl;


}





}