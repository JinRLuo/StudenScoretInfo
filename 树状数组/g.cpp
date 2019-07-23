#include <bits/stdc++.h>
using namespace std;

int tree[35000];
int lev[15010];

int lowbit(int x){
	return x&-x;
}

void add(int k,int x){
	for(int i=k;i<=35000;i+=lowbit(i)){
		tree[i]+=x;
	}
}

int sum(int x){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		res+=tree[i];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int N;
	int x,y;
	while(cin>>N){
		memset(lev,0,sizeof(lev));
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=N;i++){
			cin>>x>>y;
			//cout << "sum:" << sum(x) << endl;
			lev[sum(x+1)]++;
			add(x+1,1);
		}
		for(int i=0;i<N;i++){
			cout << lev[i] << endl;
		}
	}
}
