#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

int main(){
        ll t;
        cin >>t;
        while(t--){
            ll n;
            cin >>n;    
            vi a(n);
            vi b(n);
            ll indexa1=-1,indexa2=-1,indexb1=-1,indexb2;
            ll mina1=INT_MAX,mina2=INT_MAX;
            ll minb1=INT_MAX,minb2=INT_MAX;
            for(ll i=0;i<n;i++){
                cin >> a[i];
                if(a[i]<=mina1){
                    mina2=mina1;
                    mina1=a[i];
                    indexa2=indexa1;
                indexa1=i;
                }else if(a[i]<=mina2){
                    mina2=a[i];
                    indexa2=i;
                    
                }
            }
            
            for(ll i=0;i<n;i++){
                cin >> b[i];
                if(b[i]<minb1){
                    minb2=minb1;
                    minb1=b[i];
                    indexb2=indexb1;
                indexb1=i;
                }else if(b[i]<minb2){
                    minb2=b[i];
                    indexb2=i;
                    
                }
            }
            //cout << "Sf"<< endl;    
            //cout <<indexa1<<" "<<indexa2<<" "<<indexb1<<" "<<indexb2<< endl;
            
            if(indexa1!=indexb1){
                cout << a[indexa1]+b[indexb1]<< endl;
            }else{
                cout << min(a[indexa1]+b[indexb2],a[indexa2]+b[indexb1])<< endl;
            }
            //cout <<"Safd"<< endl;
            
        }
    
    
    
	return 0;
}