#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	struct Node{
		ll x;
		ll y;
		ll dir;
	};


bool isValid(ll i,ll j,vvi &visited,vvc &v){

if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]=='*'){
	return false;
}
return true;
}

Node* newNode(ll x,ll y, ll dir){
Node* n = new Node();
n->x=x;
n->y=y;
n->dir=dir;
return n;

}

void goDown(ll i,ll j,vvi &visited, vvi &dir, queue<Node*> &q){
    if(dir[i-1][j]==-1 || dir[i-1][j]==1){
        if(visited[i][j]>=visited[i-1][j]){
            if(visited[i][j]==visited[i-1][j]){
                if(dir[i][j]==0){
                    dir[i][j]=-1;
                }
            }else{
                visited[i][j]=visited[i-1][j];
                dir[i][j]=1;
                q.push(newNode(i,j,-1));
            }
        }
    }else{
                if(visited[i][j]>=visited[i-1][j]+1){
            if(visited[i][j]==visited[i-1][j]+1){
                if(dir[i][j]==0){
                    dir[i][j]=-1;
                }
            }else{
                visited[i][j]=visited[i-1][j]+1;
                dir[i][j]=1;
                q.push(newNode(i,j,-1));
            }
        }

        
    }
    
    
}
void goUp(ll i,ll j,vvi &visited, vvi &dir, queue<Node*> &q){
    if(dir[i+1][j]==-1 || dir[i+1][j]==1){
        if(visited[i][j]>=visited[i+1][j]){
            if(visited[i][j]==visited[i+1][j]){
                if(dir[i][j]==0){
                    dir[i][j]=-1;
                }
            }else{
                visited[i][j]=visited[i+1][j];
                dir[i][j]=1;
                q.push(newNode(i,j,-1));
            }
        }
    }else{
                if(visited[i][j]>=visited[i+1][j]+1){
            if(visited[i][j]==visited[i+1][j]+1){
                if(dir[i][j]==0){
                    dir[i][j]=-1;
                }
            }else{
                dir[i][j]=1;
                visited[i][j]=visited[i+1][j]+1;
                q.push(newNode(i,j,-1));
            }
        }

        
    }
    
    
}

void goLeft(ll i,ll j,vvi &visited, vvi &dir, queue<Node*> &q){
    if(dir[i][j+1]==-1 || dir[i][j+1]==0){
        if(visited[i][j]>=visited[i][j+1]){
            if(visited[i][j]==visited[i][j+1]){
                if(dir[i][j]==1){
                    dir[i][j]=-1;
                }
            }else{
                visited[i][j]=visited[i][j+1];
                dir[i][j]=0;
                q.push(newNode(i,j,-1));
            }
        }
    }else{
                if(visited[i][j]>=visited[i][j+1]+1){
            if(visited[i][j]==visited[i][j+1]+1){
                if(dir[i][j]==1){
                    dir[i][j]=-1;
                }
            }else{
                dir[i][j]=0;
                visited[i][j]=visited[i][j+1]+1;
                q.push(newNode(i,j,-1));
            }
        }

        
    }
    
    
}
void goRight(ll i,ll j,vvi &visited, vvi &dir, queue<Node*> &q){
    if(dir[i][j-1]==-1 || dir[i][j-1]==0){
        if(visited[i][j]>=visited[i][j-1]){
            if(visited[i][j]==visited[i][j-1]){
                if(dir[i][j]==1){
                    dir[i][j]=-1;
                }
            }else{
                visited[i][j]=visited[i][j-1];
                dir[i][j]=0;
                q.push(newNode(i,j,-1));
            }
        }
    }else{
                if(visited[i][j]>=visited[i][j-1]+1){
            if(visited[i][j]==visited[i][j-1]+1){
                if(dir[i][j]==1){
                    dir[i][j]=-1;
                }
            }else{
                dir[i][j]=0;
                visited[i][j]=visited[i][j-1]+1;
                q.push(newNode(i,j,-1));
            }
        }

        
    }
    
    
}






int main(){

ll n,m;
cin >> m>>n;
ll startx=-1,starty=-1,endx,endy;
vvc v(n,vc(m));
for(ll i=0;i<n;i++){
	for(ll j=0;j<m;j++){
		cin >> v[i][j];
	if(v[i][j]=='C'){
		if(startx==-1 && starty==-1){
		startx=i;
		starty=j;
	}else{
		endx=i;
		endy=j;
		}
	}
	}
}
vvi visited(n,vi(m,10000000));
queue<Node*> q;
q.push(newNode(startx,starty,-1));
visited[startx][starty]=0;
vvi dir(n,vi(m,-2));
dir[startx][starty]=-1;
while(!q.empty()){
	Node* p= q.front();
	q.pop();
	ll i=p->x;
	ll j=p->y;
	if(isValid(i+1,j,visited,v)){
	goDown(i+1,j,visited,dir,q);
	}
	if(isValid(i-1,j,visited,v)){
		goUp(i-1,j,visited,dir,q);
	}
	if(isValid(i,j+1,visited,v)){
		goRight(i,j+1,visited,dir,q);
	}
	if(isValid(i,j-1,visited,v)){
	goLeft(i,j-1,visited,dir,q);
 }

}
/*for(ll i=0;i<n;i++){
	for(ll j=0;j<m;j++){
		if(visited[i][j]==10000000){
			cout << 0<<" ";
		}else
		cout << visited[i][j]<< " ";
	}

cout << endl;
}*/


cout<< visited[endx][endy]<< endl;

}