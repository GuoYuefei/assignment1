
/*
 * 1008.cpp
 *
 *  Created on: 2017年5月2日
 *      Author: Administrator
 */
// #include<cstdlib>
// #include<iostream>
#include<stdio.h>
// using namespace std;

void inversion(int* n,int end,int begin);
/**
 * 解决思路：
 * 	数组分成AB前后两部分
 * 	全部倒置成B^-1A^-1
 * 	然后在前面倒置，后面倒置BA
 */
int main(){
	int size,distance;		//数组大小，位移量
	int* n = NULL;
// 	cin >> size;
// 	cin >> distance;
	scanf("%d %d", &size, &distance);
	distance = distance%size;
// 	n = new int[size];
	n = (int*)malloc(size * sizeof(int));
	for(int i=0;i<size;i++){
		// cin >> n[i];
		scanf("%d ",&n[i]);
	}
	inversion(n,size,0);		//整体倒置
	inversion(n,distance,0);	//前面的B^-1倒置
	inversion(n,size,distance);	//后面A^-1倒置
	for(int i=0;i<size-1;i++){
		// cout << n[i]<<" ";
		printf("%d ",n[i]);
	}
// 	cout << n[size-1]<<endl;
  printf("%d", n[size-1]);
}

//数组倒置函数
//num要从begin位子操作的数量
void inversion(int* n,int end,int begin){
	for(int i=begin;i<(end+begin)/2;i++){
		int temp = n[i];
		n[i] = n[begin+end-i-1];
		n[begin+end-i-1] = temp;
	}
}


