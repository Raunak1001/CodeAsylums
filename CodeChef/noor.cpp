#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long y;
		cin>>y;
		long long count=0;
		for(int i=1;i<=700;i++){
			long long temp=y-i;
			if(temp<=0)
				break;
			count+=(long long)(sqrt(temp));
		}
		cout<<count<<endl;
	}
}