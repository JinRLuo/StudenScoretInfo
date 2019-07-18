#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;
int f[maxn];
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
		init();
		cin >> a >> b;
		if(a==-1&&b==-1)
			break;
		merge(a,b);
		while(1){
			cin >> a >> b;
			if(a==0&&b==0)
				break;
			merge(a,b);
		}
		if(flag==1){
			cout << "No" << endl;
		}else
			cout << "Yes" << endl;
	}
}
