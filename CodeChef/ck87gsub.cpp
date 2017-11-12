#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<long long > v(s.size());
		v[0]=0;
		char x=s[0];
		long long count=0;
		for(int i=1;i<s.size();i++){
			if(s[i]==s[i-1]){
				v[i]=v[i-1]+1;
			}
			else{
				count+=((v[i-1])*(v[i-1]+1))/2;
				if(s[i]==x)
					count++;
				v[i]=0;
				x=s[i-1];
			}
		} 
		count+=(v[s.size()-1])*(v[s.size()-1]+1)/2;
		cout<<count<<endl;
	}
}