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
		std::ios::sync_with_stdio(false); 

		ll n;
		cin>>n;
		string s="";
		int temp1=0;
		int temp2=0;
		for(int i=0;i<n;i++){

			if(temp1<2){
				s+='a';
				temp1++;
				temp2=0;
			}else{
				s+='b';
				temp2++;
				if(temp2==2){
					temp1=0;
				}
			}
		}
		cout <<s<< endl;

	return 0;
}