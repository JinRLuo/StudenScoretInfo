#include <bits/stdc++.h>
using namespace std;

char s[25][25];
int t[25][25];
int a,b;

int dfs(int x,int y){
	if(s[x][y]=='#'||t[x][y]==1)
		return 0;
	else if(x<0||x>=b||y<0||y>=a)
		return 0;
	s[x][y]='#';
	return dfs(x+1,y)+dfs(x,y+1)+dfs(x-1,y)+dfs(x,y-1)+1;
	
}

int main(){
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>a>>b){
		memset(t,0,sizeof(t));
		if(a==0&&b==0)
			break;
		for(int i=0;i<b;i++){
				cin >> s[i];
			for(int j=0;j<a;j++){
				if(s[i][j]=='@'){
					m=i;
					n=j;
				}
			}
		}
		cout << dfs(m,n) << endl;
	}
}
