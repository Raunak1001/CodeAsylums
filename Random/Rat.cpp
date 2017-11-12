#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define ll int
bool isValid(int i,int j,vector<vector<int> > &v){

	int n=v.size();
	int m=v[0].size();
	if(i<0 || i>=n || j<0 || j>=m ||v[i][j]!=1 ){
		return 0;
	}
return 1;

}

int main(){

	int  n,m;
	cin>> n>> m;

	vector<vector<int> > v(n,vector<int>(m,0));
	pr q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v[i][j];
			if(v[i][j]==9){
				q.first=i;
				q.second=j;
			}
		}
	}

	vector<pr> a;
	vector<vector<bool> > visited(n,vector<bool>(m,0));
	visited[q.first][q.second]=1;
	a.push_back(q);
	int dx[]={-1,-1,-1,0,0,1,1,+1};
	int dy[]={0,-1,1,-1,1,0,-1,1};
	while(a.size()!=0){
		q=a[a.size()-1];
		//cout <<q.first<<" "<<q.second<<endl;
		a.pop_back();
		if(q.first==0 && q.second==0){
			cout <<1<< endl;
			return 0;
		}
		ll l=q.first;
		ll p=q.second;
		for(ll i=0;i<8;i++){
			
				if(isValid(l+dx[i],p+dy[i],v) && visited[l+dx[i]][p+dy[i]]==0){
					visited[l+dx[i]][p+dy[i]]=1;
					a.push_back(make_pair(l+dx[i],p+dy[i]));
				}
			
		}
	}

	cout << 0<< endl;
	return 0;




}