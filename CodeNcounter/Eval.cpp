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

	ll getInt(string &s,ll i){

	ll n=s.size();
	ll ans=0;
	while(i<n && s[i]!=' '){

		ll temp=s[i]-'0';
		ans*=10;
		ans+=temp;
		i++;
	}
	//cout << ans<< endl;
	return ans;
	}


	bool higherP(char a, char b){

		if(b=='/'){
			return false;
		}
		if(b=='*'){
			if(a=='/'){
				return true;
			}else
			return false;
		}
		if(b=='-'){
			if(a=='+'){
				return false;
			}else{
				return true;
			}
		}
		
	return true;
	}

	ll calculate(stack<ll> &a,stack<char> &b){

	char c=b.top();
	ll temp2=a.top();
	a.pop();
	ll temp1=a.top();
	a.pop();

	if(c=='+'){
		return temp1+temp2;
	}else if(c=='-'){
		return temp1- temp2;
	}else if(c=='*'){
		return temp1*temp2;
	}else{
		if(temp2==0){
			return INT_MAX;
		}else{
			return temp1/temp2;
		}
	}


	}




	int main(){
			std::ios::sync_with_stdio(false); 

			ll t;
			cin>> t;
			string z;
			getline(cin,z);
			while(t--){
				ll flag=0;
				string s;
				getline(cin,s);
				//cout << s<< endl;
				ll n=s.size();
				stack<ll> a;
				stack<char> b;
				ll temp=0;
				for(ll i=0;i<n;i++){
					if(s[i]==' '){
						continue;
					}
					if(s[i]=='-'){
						if(s[i+1]!=' '){
							temp=getInt(s,i+1);
							while(i<n && s[i]!=' '){
								i++;
							}
							a.push(-temp);
						}else{
							if(!b.empty() && higherP(b.top(),s[i])){
								ll p=calculate(a,b);
								if(p==INT_MAX){
									cout <<"Division by zero encountered"<< endl;
								flag=1;
								break;
								}else{
									a.push(p);
									b.pop();
								}	
							}
							b.push(s[i]);
						}
					}else if(s[i]=='*' || s[i]=='+' || s[i]=='/'){
						if(!b.empty() && higherP(b.top(),s[i])){
								ll p=calculate(a,b);
								if(p==INT_MAX){
									cout <<"Division by zero encountered"<< endl;
								flag=1;
								break;
								}else{
									a.push(p);
									b.pop();
								}							}
							b.push(s[i]);
						}else{
							temp=getInt(s,i);
							while(i<n && s[i]!=' '){
								i++;
							}
							a.push(temp);
						}
				}
			if(flag==1)
			{
				continue;
			}
			//cout << b.size()<< endl;
				while(!b.empty()){
								ll p=calculate(a,b);
								//cout <<p<< endl;
								if(p==INT_MAX){
									cout <<"Division by zero encountered"<< endl;
								flag=1;
								break;
								}else{
									a.push(p);
									b.pop();
								}	
				}
				if(flag==1)
			{
				continue;
			}

				if(!a.empty()){
					cout << a.top()<< endl;
				}else{
					//cout <<"Sf"<< endl;
					cout << "0"<< endl;
				}



			}	



		return 0;
	}