#include<stdio.h>
int main(){
	int Let[26],i;
	Let[0]='a';
	for(i=1;i<26;i++){
		Let[i]=Let[0]+i;
	}
	for(i=0;i<26;i++){
		printf("%c ",Let[i]);
	}
	return 0;
} 
