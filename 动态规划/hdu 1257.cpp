#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int dp[10000]; //dp[i]��ʾ��iΪ��β������������г���

int main(){
	int res=0;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
			dp[i]=1; //��dp����ÿһλ�ĳ�ʼֵΪ1 
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]>a[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i=0;i<n;i++){
			res=max(dp[i],res);
		}
		cout << res << endl;
	}
} 
