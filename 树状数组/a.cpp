#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int N;
	int m,n;
	while(cin>>N){
		if(N==0)
			break;
		memset(a,0,sizeof(a));
		for(int i=0;i<N;i++){
			cin >> m >> n;
			a[m]++;
			a[n+1]--;
		}
		cout << a[1];
		for(int i=2;i<=N;i++){
			a[i]=a[i-1]+a[i];
			cout << " " << a[i];
		}
		cout << endl;
	}
}
