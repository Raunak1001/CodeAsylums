#include<bits/stdc++.h>
using namespace std;
long long int y;
long long int n;
long long int m;
long long int maxMatching(vector<long long int> &a,vector<long long int> &b){

int j=m-1;
long long int count=0;
long long int prevj=m-1;	
for(int i=n-1;i>=0;i--){
	j=prevj;
while(j>=0 && abs(a[i]-b[j])>y){
	j--;
}
if(j>=0){
	j--;
	count++;
	prevj=j;
}

}
return count;
}


long long int binary1(vector<long long int> &a,vector<long long int> &b,long long int lx,long long int rx,long long int prevans)
{
	//cout << prevans<<endl;
	
long long int mx=lx+(rx-lx)/2;
if(lx>rx){
			return prevans;
}
vector<long long int > c(n,0);
for(long long int i=0;i<n;i++){
	c[i]=a[i]+mx;
}
long long int ans=maxMatching(c,b);
if(prevans>ans){
	return binary1(a,b,lx,mx-1,max(prevans,ans));
}
else{
	return binary1(a,b,mx+1,rx,max(prevans,ans));
}

}










long long int binary(vector<long long int> &a,vector<long long int> &b,long long int lx,long long int rx,long long int prevans)
{
	//cout << prevans<<endl;
	
long long int mx=lx+(rx-lx)/2;
if(lx>rx){
			return prevans;
}
vector<long long int > c(n,0);
for(long long int i=0;i<n;i++){
	c[i]=a[i]+mx;
}
long long int ans=maxMatching(c,b);
if(prevans<ans){
	return binary(a,b,lx,mx-1,max(prevans,ans));
}
else{
	return binary(a,b,mx+1,rx,max(prevans,ans));
}

}

int main(){
long long int t;
cin >>t;
for(int q=0;q<t;q++){
cin >>n>>m>>y;
vector<long long int> a(n),b(m);
for(long long int i=0;i<n;i++){
	cin >> a[i];
}
for(long long int j=0;j<m;j++){
	cin >> b[j];
}
sort(a.begin(),a.end());
sort(b.begin(),b.end());


long long int ans=maxMatching(a,b);
long long int rx=2*1000000000;
long long int lx=-rx;

cout<<max(binary(a,b,lx,0,ans),binary1(a,b,0,rx,ans))<<endl;;

}



}