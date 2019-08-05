#include <bits/stdc++.h>
using namespace std;

int c,n,res;
int t[105][105];
int dp[105][105];

int main(){
	cin>>c;
	while(c--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++){
				cin>>t[i][j];
			}
		}
		for(int i=n;i>=0;i--){
			for(int j=0;j<n;j++){
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+t[i][j];
			}
		}
		cout << dp[0][0] << endl;
	}
}

//int main(){
//	int a;
//	cin>>c;
//	while(c--){
//		res=0;
//		cin>>n;
//		cin>>t[0][0];
//		for(int i=1;i<n;i++){
//			for(int j=0;j<i+1;j++){
//				cin>>a;
//				if(j==0){
//					t[i][j]=t[i-1][j]+a;
//				}else if(j==i){
//					t[i][j]=t[i-1][j-1]+a;
//				}else{
//					t[i][j]=max(t[i-1][j],t[i-1][j-1])+a;
//				}
//			}
//		}
//		for(int i=0;i<n;i++){
//			if(t[n-1][i]>res)
//				res=t[n-1][i];
//		}
//		cout << res << endl;
//	}
//}
