#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[1000][1000];

int main(){
	int len1,len2;
	while(cin>>s1>>s2){
		memset(dp,0,sizeof(dp));
		len1=s1.length();
		len2=s2.length();
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(s1[i-1]==s2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout << dp[len1][len2] << endl;
	}
} 
