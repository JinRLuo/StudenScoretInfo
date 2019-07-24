#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct gps{
	double x,y;
}gp[105];

//struct gphs{
//	int x,y;
//}gh[105];

int use[105];
int hole[105];
int g[105][105];
int n,m,s,v;

int dfs(int x){
	for(int i=1;i<=m;i++){
		if(g[x][i]&&!use[i]){
			use[i]=1;
			if(!hole[i]||dfs(hole[i])){
				hole[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	double x,y;
	int res=0;
	memset(g,0,sizeof(g));
	memset(hole,0,sizeof(hole));
	cin>>n>>m>>s>>v;
	for(int i=1;i<=n;i++){
		cin>>gp[i].x>>gp[i].y;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(sqrt(pow(gp[j].x-x,2)+pow(gp[j].y-y,2))<=s*v){
				g[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(use,0,sizeof(use));
		if(dfs(i))
			res++;
	}
	cout << n-res << endl;
}
