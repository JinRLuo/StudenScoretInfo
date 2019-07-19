#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;
int f[maxn];
int v[maxn];
int flag;

void init(){
	for(int i=1;i<=maxn;i++){
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
	if(x1==x2)
		flag=1;
	else{
		f[x1]=x2;
	}
}

int main(){
	int a,b;
	while(1){
		flag=0;
		memset(v,0,sizeof(v));
		init();
		cin >> a >> b;
		if(a==-1&&b==-1)
			break;
		if(a==0&&b==0){
			cout << "Yes" << endl;
			continue;
		}
		v[a]=1;
		v[b]=1;
		merge(a,b);
		while(1){
			cin >> a >> b;
			if(a==0&&b==0)
				break;
			v[a]=1;
			v[b]=1;
			merge(a,b);
		}
		int count=0;
		if(flag==1){
			cout << "No" << endl;
		}else{
			for(int i=1;i<maxn;i++){
				if(v[i]==1&&f[i]==i){
					count++;
					if(count>1){
						cout << "No" << endl;
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
				cout << "Yes" << endl;
		}
			
	}
}
