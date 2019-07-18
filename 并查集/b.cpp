#include <bits/stdc++.h>
using namespace std;

const int maxn=10000010;
int maxc;
int f[maxn];
int c[maxn];

void init(){
	for(int i=1;i<maxn;i++){
		f[i]=i;
		c[i]=1;
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
		c[x2]+=c[x1];
		if(c[x2]>maxc)
			maxc=c[x2];
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	int a,b;
	while(cin>>n){
		if(n==0){
			cout << 1 << endl;
			continue;
		}
		maxc=0;
		init();
		for(int i=0;i<n;i++){
			cin>>a>>b;
			merge(a,b);
		}
		cout << maxc << endl;
	}
}
