#include <bits/stdc++.h>
using namespace std;

int a,b;
char c[105][105];

void dfs(int x,int y){
	if(x<0||x>=a||y<0||y>=b)
		return;
	else if(c[x][y]=='*')
		return;
	else{
		c[x][y]='*';
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x,y-1);
		dfs(x+1,y+1);
		dfs(x+1,y-1);
		dfs(x-1,y+1);
		dfs(x-1,y-1);
		return;
	}
}

int main(){
	int count;
	while(cin>>a>>b){
		memset(c,0,sizeof(c)); 
		if(a==0&&b==0)
			break;
		count=0;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				cin >> c[i][j];
			}
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if(c[i][j]=='@'){
					dfs(i,j);
					count++;
				}

			}
		}
		cout << count << endl;
	}
}
