#include <bits/stdc++.h>
using namespace std;

int a,b;
char c[105][105];

void dfs(int x,int y){
	if(x<0||x>=a||y<0||y>=b){
		return;
	}else if(c[x][y]=='.'){
		return;
	}else{
		c[x][y]='.';
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x,y-1);
	}
}

int main(){
	int n,count;
	cin>>n;
	while(n--){
		count=0;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			cin >> c[i];
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if(c[i][j]=='#'){
					dfs(i,j);
					count++;
				}
			}
		}
		cout << count << endl;
	}
}
