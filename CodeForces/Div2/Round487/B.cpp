#include<bits/stdc++.h>
using namespace std;
int right(vector<std::vector<int> > &v,vector<int> &count,int index,int m);

int left(vector<vector<int> > &v,vector<int> &count,int index,int m){

	if(index<0){
		return 0;
	}
	int ans=0;
for(int i=0;i<m;i++){
if(count[index]==0){
//cout << ans<< endl;
ans=ans+min(i+left(v,count,index-1,m),m-i+right(v,count,index-1,m))+1;
break;
}else{
	if(v[index][i]==1){
		count[index]--;
		
	}
	ans++;
}

}
return ans;
}



int right(vector<std::vector<int> > &v,vector<int> &count,int index,int m){
	if(index<0){
		return 0;
	}
	int ans=0;
for(int i=m-1;i>=0;i--){
if(count[index]==0){

ans+=min(i+left(v,count,index-1,m),m-i+right(v,count,index-1,m))+1;

break;
}else{
	if(v[index][i]==1){
		count[index]--;
		
	}
ans++;
}

}
return ans;
}




int main(){

int n;
int m;
cin >>n>>m;
vector<int> count(n,0);
		char a;

vector<std::vector<int > > v(n,vector<int>(m,0));
for(int i=0;i<n;i++){
	cin >>a;
	for(int j=0;j<m;j++){
		cin>>a;
		v[i][j]=a-'0';
		if(v[i][j]==1 ){
			count[i]=count[i]+1;
		}
	}
	cin >>a;
}
for(int i=0;i<m;i++){
	cout << count[i]<< " ";
	
}
int ans=0;
for(int i=0;i<m;i++){

if(count[n-1]==0){
ans+=min(i+left(v,count,n-2,m),m-i+right(v,count,n-2,m))+1;
break;
}else{
	if(v[n-1][i]==1){
		count[n-1]--;
		
	}
	ans++;
}

}


	cout << ans<<endl;	

}