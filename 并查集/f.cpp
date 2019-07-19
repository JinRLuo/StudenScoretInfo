#include <bits/stdc++.h>
using namespace std;

const int maxn=1000010;
int f[maxn];
int rep[maxn];
int flag[maxn];

void init(int n){
	for(int i=0;i<n;i++){
		f[i]=i;
		rep[i]=i;
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
	int n,m;
	int k=1;
	string s;
	int a,b;
	int count;
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		init(n);
		int fn=n+1;
		for(int i=0;i<m;i++){
			cin >> s;
			if(s=="M"){
				cin >> a >> b;
				merge(rep[a],rep[b]);
			}else{
				cin >> a;
				rep[a]=fn;
				f[fn]=fn;
				fn++;
			}
		}
		memset(flag,0,sizeof(flag));
		count=0;
		for(int i=0;i<n;i++){
			if(flag[find_set(rep[i])]==0){
				flag[find_set(rep[i])]=1;
				count++;
			}
		}
		cout << "Case #" << k << ": " << count << endl;
		k++; 
	}
}

