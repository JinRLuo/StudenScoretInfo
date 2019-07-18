#include <bits/stdc++.h>
using namespace std;

int n,m;
int f[1010];

void init(int a){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}

int find_set(int a){
	if(f[a]!=a)
		return find_set(f[a]);
	return a;
}

void merge(int a,int b){
	int x1=find_set(a);
	int x2=find_set(b);
	if(x1!=x2){
		f[x1]=x2;
	}
}

int main(){
	int a,b,count;
	while(cin>>n){
		if(n==0)
			break;
		init(n);
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> a >> b;
			merge(a,b);
		}
		count=0;
		for(int i=1;i<=n;i++){
			if(f[i]==i)
				count++;
		}
		cout << count-1 << endl;
	}
}
