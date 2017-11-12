    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int 
    #define pr pair<ll,ll>
    #define vi vector<ll>
    #define vvi vector< vi >
    #define vvvi vector< vvi >
    #define vp vector<pr >
    #define vvp vector<vp >
    #define vc vector<char>
    #define vvc vector<vc  >
    #define mp Node		
    #define pb push_back
    #define vb vector<bool>
    #define vvb vector< vb >
    #define vvvb vector< vvb >
    #define rep(i,a,b) for(ll i=a;i<b;i++)
    #define repr(i,b,a) for(ll i=b;i>=a;i--)
    #define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
    #define ct(a) cout <<a<<endl

    bool isValid(ll i,ll j,vvb &visited){
        ll n=visited.size();
        if(i<=0 || i>=n || j<=0 || j>=n || visited[i][j]==1){
            return false;
        }
        return true;
    }
    struct Node{
        ll first;
        ll second;
        ll w;
       Node(ll a,ll b,ll c):first(a), second(b), w(c) {}
    };

    int main(){
    		std::ios::sync_with_stdio(false); 
    		cin.tie(NULL);
    		cout.tie(NULL);

        ll n;
        cin >> n;
        vvi v(n+1,vi(n+1,0));
        ll m;
        cin >> m;
        while(m--){
            ll x,y,w;
            cin >>x>>y>>w;
            x++;
            y++;
            ll dx[]={-1,-1,-1,0,0,1,1,1};
            ll dy[]={1,0,-1,1,-1,1,0,-1};
            vvb visited(n+1,vb(n+1,0));
            queue<Node> q;
            q.push(Node(x,y,w));
            v[x][y]+=w;
            if(w<=1){
                continue;
            }
           // cout << v[x][y]<<endl;
            visited[x][y]=1;

            while(!q.empty()){
                Node p=q.front();
                q.pop();
                ll i=p.first;
                ll j=p.second;
                ll k=p.w;

            for(ll l=0;l<8;l++){
                if(isValid(i+dx[l],j+dy[l],visited)){
                    visited[i+dx[l]][j+dy[l]]=1;
                    v[i+dx[l]][j+dy[l]]+=(k-1);
                    if(k>1){
                        q.push(mp(i+dx[l],j+dy[l],k-1));
                    }

                }
            }

        }
           
        }
        
         ll mx=0;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    mx=max(mx,v[i][j]);
                }
            }


    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }

            cout <<mx<< endl;
        
        
    	return 0;
    }			