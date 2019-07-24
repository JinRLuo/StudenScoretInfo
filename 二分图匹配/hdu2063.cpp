#include <bits/stdc++.h>
using namespace std;

int N,M,res;
int pel[505][505];
int boy[505];
int use[505];

int dfs(int x){
	for(int i=1;i<=M;i++){
		if(!use[i]&&pel[x][i]){
			use[i]=1;
			if(!boy[i]||dfs(boy[i])){
				boy[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int K;
	int a,b;
	while(cin>>K){
		memset(pel,0,sizeof(pel));
		memset(boy,0,sizeof(boy));
		res=0;
		if(K==0)
			break;
		cin>>N>>M;
		for(int i=0;i<K;i++){
			cin>>a>>b;
			pel[a][b]=1;
			//pel[b][a]=1;
		}
		for(int i=1;i<=N;i++){
			memset(use,0,sizeof(use));
			if(dfs(i))
				res++;
		}
		cout << res << endl;
	}
}
