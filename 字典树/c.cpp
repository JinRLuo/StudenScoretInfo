/*
hdu 1247

Problem Description
A hat¡¯s word is a word in the dictionary that is the concatenation of exactly two other words in the dictionary.
You are to find all the hat¡¯s words in a dictionary.
 

Input
Standard input consists of a number of lowercase words, one per line, in alphabetical order. There will be no more than 50,000 words.
Only one case.

Output
Your output should contain all the hat¡¯s words, one per line, in alphabetical order.
 

Sample Input
a
ahat
hat
hatword
hziee
word
 

Sample Output
ahat
hatword

*/
#include <bits/stdc++.h>
using namespace std;

struct node{
	int a;
	node* next[27];
	bool isword;
}*root;

string st[50010];

void insert(string s){
	node* tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL){
			tmp->next[p]=new node();
		}
		tmp=tmp->next[p];
		tmp->a++;
	}
	tmp->isword=true;
}

int searchWord(string s){
	node* tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL)
			return 0;
		tmp=tmp->next[p];
	}
	if(tmp->isword)
		return 1;
	else
		return 0;
}

int main(){
	int count=0;
	int len;
	root=new node();
	string s;
	while(cin>>st[count]){
		insert(st[count]);
		count++;
	}
	for(int i=0;i<count;i++){
		len = st[i].length();
		for(int j=1;j<len;j++){
			if(searchWord(st[i].substr(0,j))&&searchWord(st[i].substr(j,len-j))){
				cout << st[i] << endl;
				break;
			}
		}
	}
}
