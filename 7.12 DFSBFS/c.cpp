#include <bits/stdc++.h>
#define maxtime 40005
using namespace std;

int a,b,mint=maxtime;
char c[205][205];
int f[205][205];

void dfs(int x,int y,int t){
	if(x<0||x>=a||y<0||y>=b||c[x][y]=='#'||f[x][y]==1){
		return;
	}else if(c[x][y]=='x'){
		t++;
	}else if(t>mint){
		return;
	}else if(c[x][y]=='r'){
		if(mint>t)
			mint=t;
		return;
	}
	f[x][y]=1;
	dfs(x+1,y,t+1);
	dfs(x,y+1,t+1);
	dfs(x-1,y,t+1);
	dfs(x,y-1,t+1);
	f[x][y]=0;
}

int main(){
	ios::sync_with_stdio(false);
	int time;
	while(cin>>a>>b){
		time=maxtime;
		mint=maxtime;
		memset(f,0,sizeof(f));
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				cin >> c[i][j];
			}
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if(c[i][j]=='a'){
					dfs(i,j,0);
					if(time>mint)
						time=mint;
				}
			}
		}
		if(time==maxtime)
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		else
			cout << time << endl;
	}
}
