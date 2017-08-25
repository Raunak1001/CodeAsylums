#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
ll t;
cin >> t;
while(t--){
    ll n,m;
    cin >> n>> m;
    vvi v(n,vi(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
   /* for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout << v[i][j]<<" ";
        }
        cout<< endl;
    }
    cout << endl;*/

    stack<ll> s;
    ll startx=0,endx=m;
    ll starty=m-2,endy=0;
    ll startu=1,endu=n;
    ll startv=n-2,endv=1;
    
    while(1){

        if(startx>=endx){
            break;
        }
        for(ll i=startx;i<endx;i++){
            s.push(v[startu-1][i]);
          // cout << v[startu-1][i]<<" ";
        }

        if(startu>=endu){
            break;
        }

        for(ll i=startu;i<endu;i++)
        {
            s.push(v[i][endx-1]);
            //cout << v[i][endx-1]<<" ";
        }

        if(starty<endy){
            break;
        }

        for(ll i=starty;i>=endy;i--){
            s.push(v[startv+1][i]);
            //cout <<v[startv+1][i]<<" ";
        }

                        //cout << "saf"<< endl;

        if(startv<endv){
            break;
        }
        for(ll i=startv;i>=endv;i--){
            s.push(v[i][startx]);
           // cout << v[i][startx]<<" ";
        }
        //cout << endl;
        startx++;
        endx--;
        startu++;
        endu--;
        startv--;
        endv++;
        starty--;
        endy++;
        if(startx>=endx && startu>=endu && starty<endy && startv<endv){
            break;
        }
        
    }
    while(!s.empty()){
        cout << s.top()<<" ";
        s.pop();
    }
    
    
}

	return 0;
}