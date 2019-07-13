#include <bits/stdc++.h>
using namespace std;

int n,m,t,flag,cut;
int sx,sy,dx,dy;
char c[10][10];
int v[10][10];

void dfs(int x,int y,int step){
	if(flag==1){
		return;
	}else if(t-step-(abs(dx-x)+abs(dy-y))<0){
		return;
	}else if((t-step-(abs(dx-x)+abs(dy-y)))%2!=0){
		return;
	}else if(x<0||x>=n||y<0||y>=m||v[x][y]==1||step>t){
		return;
	}else if(c[x][y]=='X')
		return;
	else if(c[x][y]=='D'){
		if(step==t){
			flag=1;
		}
		return;
	}
	else{
		v[x][y]=1;
		dfs(x+1,y,step+1);
		dfs(x,y+1,step+1);
		dfs(x-1,y,step+1);
		dfs(x,y-1,step+1);
		v[x][y]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m>>t){
		memset(v,0,sizeof(v));
		flag=0;
		cut=0;
		if(n==0&&m==0&&t==0)
			break;
		for(int i=0;i<n;i++){
			cin >> c[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]=='S'){
					sx=i;
					sy=j;
				}else if(c[i][j]=='D'){
					dx=i;
					dy=j;
				}else if(c[i][j]=='X'){
					cut++;
				}
			}
		}
		if(n*m-cut-1>=t)
			dfs(sx,sy,0);
		if(flag==0){
			cout << "NO" << endl;
		}else
			cout << "YES" << endl;
	}
}
