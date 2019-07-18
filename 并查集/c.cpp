#include <bits/stdc++.h>
using namespace std;

int f[1005];

void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}

int find_set(int a){
	if(f[a]!=a)
		f[a]=find_set(f[a]);
	return f[a];
}

void merge(int a,int b){
	int x1=find_set(a);
	int x2=find_set(b);
	if(x1!=x2){
		f[x1]=x2;
	}
}

int main(){
	int t,n,m,count;
	cin >> t;
	while(t--){
		int a,b;
		cin >> n >> m;
		init(n);
		for(int i=0;i<m;i++){
			cin >> a >> b;
			merge(a,b);
		}
		count=0;
		for(int i=1;i<=n;i++){
			if(f[i]==i)
				count++;
		}
		cout << count << endl;
	}
	
}
