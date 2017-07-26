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

ll getNum(ll i,ll j,ll temp){

ll a=i%10;
i/=10;
ll b=i%10;
i/=10;
ll c=i%10;
i/=10;
ll d=i%10;
i/=10;
if(j==1){
	if(a==0){
		if(temp!=-1){
			return d*1000+c*100+b*10+(a+temp);
		}
	}else if(a==9){
		if(temp!=1){
			return d*1000+c*100+b*10+(a+temp);
		}
	}else{
		return d*1000+c*100+b*10+(a+temp);
	}
}

if(j==2){
	if(b==0){
		if(temp!=-1){
			return d*1000+c*100+(b+temp)*10+a;
		}
	}else if(b==9){
		if(temp!=1){
			return d*1000+c*100+(b+temp)*10+a;
		}
	}else{
		return d*1000+c*100+(b+temp)*10+a;
	}
}
if(j==3){
	if(c==0){
		if(temp!=-1){
			return d*1000+(c+temp)*100+b*10+a;
		}
	}else if(c==9){
		if(temp!=1){
			return d*1000+(c+temp)*100+b*10+a;
		}
	}else{
		return d*1000+(c+temp)*100+b*10+a;
	}
}

if(j==4){
	if(d==0 || d==1){
		if(temp!=-1){
			return (d+temp)*1000+(c)*100+b*10+a;
		}
	}else if(d==9){
		if(temp!=1){
			return (d+temp)*1000+(c)*100+b*10+a;
		}
	}else{
		return (d+temp)*1000+(c)*100+b*10+a;
	}
}
return -1;




}


int main(){

ll t;
cin >>t;
 vi s(10000,1);
 //cout << "sfd"<< endl;

 s[1]=-1;
for(ll i=3;i<10000;i+=2){
 	if(s[i]==1){
 		for(ll j=3;j*i<10000;j+=2){
 			s[j*i]=-1;
 		}
 	}
}

vvi v(10000);
//cout << s[1033]<<endl;
for(ll i=1000;i<10000;i++){
	if(i%2!=0 && s[i]!=-1){
		ll newI=i;
ll a=newI%10;
newI/=10;
ll b=newI%10;
newI/=10;
ll c=newI%10;
newI/=10;
ll d=newI%10;
newI/=10;


ll newN;
	for(ll j=0;j<=9;j++){
		if(j!=a){
			newN=d*1000+c*100+b*10+j;
			if(newN%2!=0 && s[newN]!=-1){
				v[i].push_back(newN);
			}
		}
	}
	for(ll j=0;j<=9;j++){
		if(j!=b){
			newN=d*1000+c*100+j*10+a;
			if(newN%2!=0 && s[newN]!=-1){
				v[i].push_back(newN);
			}
		}
	}
	for(ll j=0;j<=9;j++){
		if(j!=c){
			newN=d*1000+j*100+b*10+a;
			if(newN%2!=0 && s[newN]!=-1){
				v[i].push_back(newN);
			}
		}
	}
	for(ll j=1;j<=9;j++){
		if(j!=d){
			newN=j*1000+c*100+b*10+a;
			if(newN%2!=0 && s[newN]!=-1){
				v[i].push_back(newN);
			}
		}
	}


		}

}
/*
for(ll i=1000;i<10000;i++){
	for(ll j=0;j<v[i].size();j++){
		cout << v[i][j]<<" ";
	}
	cout << endl;

}*/


while(t--){

ll n,m;
cin >>n>>m;
queue<ll> q;
q.push(n);
vi dis(10001,100000);
dis[n]=0;
ll temp=0;
while(!q.empty()){
 ll i=q.front();
 q.pop();
//cout << i<<endl;
 for(ll j=0;j<v[i].size();j++){
 	if(dis[v[i][j]]>dis[i]+1){
 		dis[v[i][j]]=dis[i]+1;
 	q.push(v[i][j]);
 	}
 	if(v[i][j]==m){
 		temp=1;
 		break;
 	}
 }
 if(temp){
 	break;
 }

}
if(dis[m]<100000)
cout << dis[m]<< endl;
else
cout <<"Impossible"<< endl;



}




	
}