#include <iostream>
#include <cstring>
#define ll long long 
using namespace std;

const int maxn = 100010;
int num[maxn];
ll a[maxn];
ll b[maxn];
ll c[maxn];

int lowbit(int x){
	return x&-x;
}

void add(int k,int x){
	for(int i=k;i<maxn;i+=lowbit(i)){
		a[i]+=1;
	}
}

ll sum(int k){
	ll ans=0;
	for(int i=k;i>0;i-=lowbit(i)){
		ans+=a[i];
	}
	return ans;
}

int main(){
	int T,N;
	ll ans;
	cin >> T;
	while(T--){
		ans=0;
		cin>>N;
		for(int i=1;i<=N;i++){
			cin >> num[i];
		}
		memset(a,0,sizeof(a));
		//cout << "b:";
		for(int i=1;i<=N;i++){
			add(num[i],1);
			b[i]=sum(num[i]-1);
			//cout << b[i];
		}
		//cout << endl;
		memset(a,0,sizeof(a));
		for(int i=N;i>0;i--){
			add(num[i],1);
			c[i]=sum(num[i]-1);
		}
		for(int i=1;i<=N;i++){
			ans+=b[i]*(N-i-c[i])+c[i]*(i-1-b[i]);
		}
		cout << ans << endl;
	}
}
