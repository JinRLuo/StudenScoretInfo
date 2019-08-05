//hdu 2159 ¶þÎ¬±³°ü 
#include <bits/stdc++.h>
using namespace std;

int n,m,k,s;
int a[105],b[105];
int dp[105][105];

int main(){
	int res=0;
	while(cin>>n>>m>>k>>s){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=0;i<k;i++){
			for(int j=b[i];j<=m;j++){
				for(int t=1;t<=s;t++){
					dp[j][t]=max(dp[j][t],dp[j-b[i]][t-1]+a[i]);
				}
			}
		}
		//cout << "DP:" << dp[m][s] << endl;
		if(dp[m][s]<n)
			cout << "-1" << endl;
		else{
			for(int i=0;i<=m;i++){
				if(dp[i][s]>=n){
					res=i;
					break;
				}
			}
			cout << m-res << endl;
		}
	}
}
