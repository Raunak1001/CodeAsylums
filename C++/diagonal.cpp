#include<iostream>
#include<vector>
using namespace std;

void swapcol(std::vector<long long int >& a, std::vector<long long int>& b){
for(int i=0;i<a.size();i++){
	swap(a[i],b[i]);
}


}



int main(){
long long int n;
cin >>n;
vector<long long int > r(n,0),c(n,0);
long long int a,b;
vector<vector<long long int> > v(n,std::vector<long long int>(n,0));
for(int i=0;i<n-1;i++){
cin >>a>>b;
v[a-1][b-1]=1;
r[a-1]+=1;
c[b-1]+=1;
}
for(int i=0;i<n;i++){
while(r[i]>i){
	int count=r[i];
	int count2=r[count];
	swap(r[i],r[count]);
	swap(v[i],v[count]);
	cout << 1<<" "<<i+1<<" "<<count+1<<endl;
}

}
for(int i=0;i<n;i++){
while(c[i]>n-1-i){
	int count=n-1-c[i];
	int count2=c[count];
	swap(c[i],c[count]);
	swapcol(v[i],v[count]);
	cout << 2<<" "<<i+1<<" "<<count+1<<endl;
}

}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout <<v[i][j]<<" ";
	}
	cout << endl;
}
/*for(int i=0;i<n;i++){
if(v[i][i]==1){
	swap(v[i],v[i+1]);
	cout <<1<<" "<<i+1<<" "<<i+2<<endl;
}

}
*/




return 0;
}