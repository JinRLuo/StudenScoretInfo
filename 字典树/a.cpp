/*
hdu 1251

Ignatius�������һ������ , ��ʦ�������ܶ൥�� ( ֻ��Сд��ĸ��� , �������ظ��ĵ��ʳ��� ),������ʦҪ��ͳ�Ƴ���ĳ���ַ���Ϊǰ׺�ĵ�������( ���ʱ���Ҳ���Լ���ǰ׺ ).
Input
�������ݵĵ�һ������һ�ŵ��ʱ� , ÿ��һ������ , ���ʵĳ��Ȳ�����10 , ���Ǵ��������ʦ����Ignatiusͳ�Ƶĵ��� ,һ�����д����ʱ�Ľ���.�ڶ�������һ����������, ÿ��һ������ , ÿ�����ʶ���һ���ַ��� . 

ע�� : ����ֻ��һ��������� , �����ļ����� .

Output
����ÿ������ , �����Ը��ַ���Ϊǰ׺�ĵ��ʵ����� .

Sample Input
	
banana 
band 
bee 
absolute
acm

ba 
b 
band
abc

Sample Output

2 
3 
1 
0
*/
#include <string>
#include <iostream>
using namespace std;

struct node{
	int a;
	node *next[27];
	bool isword;
}*root;

void insert(string s){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL){
			tmp->next[p]=new node();
		}
		tmp=tmp->next[p];
		tmp->a++;
		if(i==s.length()-1)
			tmp->isword=true;
	}
}

int stat(string s){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int a=s[i]-'a'+1;
		if(tmp->next[a]==NULL){
			return 0;
		}
		tmp=tmp->next[a];
	}
	return tmp->a;
}

int main(){
	string s;
	root=new node();
	while(1){
		getline(cin,s);
		//cout << "s:" << s << endl;
		if(s=="")
			break;
		insert(s);
	}
	while(getline(cin,s)){
		if(s=="")
			break;
		cout << stat(s) << endl;
	}
}
