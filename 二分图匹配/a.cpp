#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int cw[205][205];
int use[205];
int mk[205];

int dfs(int x){
	for(int i=1;i<=M;i++){
		if(cw[x][i]&&!use[i]){
			use[i]=1;
			if(!mk[i]||dfs(mk[i])){
				mk[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int a,b,si,res;
	while(cin>>N>>M){
		memset(cw,0,sizeof(cw));
		memset(mk,0,sizeof(mk));
		res=0;
		for(int i=1;i<=N;i++){
			cin>>si;
			while(si--){
				cin>>a;
				cw[i][a]=1;
				//cw[a][i]=1;
			}
		}
		for(int i=1;i<=N;i++){
			memset(use,0,sizeof(use));
			if(dfs(i))
				res++;
		}
		cout << res << endl;
	}
}
