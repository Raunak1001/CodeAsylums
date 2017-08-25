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
	
	char a,b;
	cin >>a>>b;
	//scout <<a<<b<<endl;
	ll n;
	cin >>n;
	if(a==b){
		cout <<"undefined"<< endl;
		return 0;
	}
	n%=4;
	//cout << n<< endl;
	if(n==0 || n==2){
	cout <<"undefined"<< endl;
		return 0;
	}

	if(n==1){
		if(a==118){
			if(b==62){
				cout <<"ccw"<< endl;
				return 0;
			}else{
				cout << "cw"<< endl;
				return 0;
			}
		}
		if(a==60){
			if(b==118){
				cout <<"ccw"<< endl;
				return 0;
			}else{
				cout << "cw"<< endl;
				return 0;
			}
		}

		if(a==94){
			if(b==60){
				cout <<"ccw"<< endl;
				return 0;
			}else{
				cout << "cw"<< endl;
				return 0;
			}
		}

		if(a==62){
			if(b==94){
				cout <<"ccw"<< endl;
				return 0;
			}else{
				cout << "cw"<< endl;
				return 0;
			}
		}



	}


	if(n==3){
		if(a==118){
			if(b==62){
				cout <<"cw"<< endl;
				return 0;
			}else{
				cout << "ccw"<< endl;
				return 0;
			}
		}
		if(a==60){
			if(b==118){
				cout <<"cw"<< endl;
				return 0;
			}else{
				cout << "ccw"<< endl;
				return 0;
			}
		}

		if(a==94){
			if(b==60){
				cout <<"cw"<< endl;
				return 0;
			}else{
				cout << "ccw"<< endl;
				return 0;
			}
		}

		if(a==62){
			if(b==94){
				cout <<"cw"<< endl;
				return 0;
			}else{
				cout << "ccw"<< endl;
				return 0;
			}
		}

		

	}




	return 0;
}