#include<bits/stdc++.h>

using namespace std;
//#define vector<long long in> vector<long long int>


int main(){

long long int n;
while(1){
	cin >>n;
	if(n==0){

		break;
	}

map<long long int,long long int> m;
vector<long long int> v(n,0);
long long int a;
vector<long long int> sum1(n,0);
for(long long int i=0;i<n;i++){
	cin >>a;
	v[i]=a;
m[a]=i;
if(i==0){
	sum1[i]=a;
}else
sum1[i]=sum1[i-1]+a;

}
cin >>n;
vector<long long int> r(n,0);

vector<long long int> sum2(n,0);
for(int i=0;i<n;i++){
	scanf("%lld",&a);

	r[i]=a;
	if(i==0){
	sum2[i]=a;
}else
sum2[i]=sum2[i-1]+a;

}

/*for(int i=0;i<v.size();i++){
	cout<<v[i]<<" ";
}
cout << endl;*/

int q;
long long int index1=-1;
long long int index2=-1;
long long int ans=0;
for(int i=0;i<n;i++){

if(m.find(r[i])!=m.end()){
if(index1==-1 && index2==-1)
{
q=m.find(r[i])->second;
	ans=max(sum1[q],sum2[i]);
index1=q;
index2=i;
//cout << ans<<endl;
}else{
q=m.find(r[i])->second;
ans+=max(sum1[q]-sum1[index1],sum2[i]-sum2[index2]);
index1=q;
index2=i;
//cout<<ans<<endl;
}


}


}

ans+=max(sum1[v.size()-1]-sum1[index1],sum2[r.size()-1]-sum2[index2]);	
cout << ans<<endl;

}






}