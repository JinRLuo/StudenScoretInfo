#include <iostream>

using namespace std;

int n,k,cut;
int s[15];
char c[10][10];

bool place(int t){
	for(int i=1;i<t;i++){
		if(s[i]==s[t])
			return false;
	}
	return true;
}

void dfs(int t,int rn){
	if(t>n){
		if(rn==0)
			cut++;
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(c[t][i]=='#'&&rn>0){
				s[t]=i;
				if(place(t))
					dfs(t+1,rn-1);
			}
		}
		s[t]=0;
		dfs(t+1,rn);
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>k){
		cut=0;
		if(n==-1&&k==-1)
			break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin >> c[i][j];
		
		dfs(1,k);
		cout << cut << endl;
	}
}
