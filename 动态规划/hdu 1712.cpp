//hdu 1712 分组背包 
//将每种作业看作一类物品，每种作业只能做x天，即每类物品只能选择一个（第x个），花费x。 
#include <bits/stdc++.h>
using namespace std;

int N,M;
int a[105][105];
int dp[10000];

int main(){
	while(cin>>N>>M&&N&&M){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=M;j>=0;j--){
				for(int k=0;k<M;k++){
					if(j>=k+1)
						dp[j]=max(dp[j],dp[j-(k+1)]+a[i][k]);
				}
			}
		}
		cout << dp[M] << endl;
	}
}
