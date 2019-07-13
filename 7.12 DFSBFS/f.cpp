#include <bits/stdc++.h>
using namespace std;

int a,c;
int s[15];

bool place(int n){
	for(int i=1;i<n;i++){
		if((abs(s[i]-s[n])==abs(i-n))||s[i]==s[n])
			return false;
	}
	return true;
}

void dfs(int n){
	if(n>a){
		c++;
		return;
	}else{
		for(int i=1;i<=a;i++){
			s[n]=i;
			if(place(n))
				dfs(n+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>a){
		if(a==0)
			break;
		c=0;
		dfs(1);
		cout << c << endl;
	}
}
