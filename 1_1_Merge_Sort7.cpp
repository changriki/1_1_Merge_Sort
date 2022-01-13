// Merge Sort Algorithm is done.

#include <iostream>
#include <vector>
#include <cstdio>
#include <limits.h>
#include <cassert>
using namespace std;

//宣告Merge融合函數
void Merge(vector<int> &Array, int front, int mid, int end){

//宣告左右子集合
	vector<int> Left(Array.begin()+front, Array.begin()+mid+1),
	Right(Array.begin()+mid+1, Array.begin()+end+1);

//在尾端差最大值
	Left.insert(Left.end(), INT_MAX);
	Right.insert(Right.end(), INT_MAX);

//兩個子集合融合融合
	int iLeft=0, iRight=0;
	for(int i=front; i<=end; i++){
		if(Left[iLeft]<=Right[iRight]){
			Array[i] = Left[iLeft];
			iLeft++;
		}
		else{
			Array[i] = Right[iRight];
			iRight++;
		}
	}
}

//宣告MS融合整理函數
void MergeSort(vector<int> &array, int front, int end){

//遞迴比較
	if(front<end){
		int mid=(front+end)/2;
		MergeSort(array, front, mid);
		MergeSort(array, mid+1, end);
		Merge(array, front, mid, end);
	}
}

//宣告陣列列印函數
void PrintArray(vector<int> &array){
	for(int i=0; i<array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

//主程式
int main(){
	int *p = new int[100000];
	char ch;
	int j=0, sign=1, space=0;
	p[j] = 0;

	//輸入字串
	while(1){
		ch = getchar();
		if(ch == '\n'){	
			p[j] = p[j] * sign;
			if(space == 1)
				break;
			else{
				j++;
				break;
			}
		}
		else if((int)ch == 32){
			p[j] = p[j] * sign;
			j++;
			p[j] = 0;
			sign = 1;
			space = 1;
			continue;
		}
		else{
			space = 0;
			if(ch == '-'){
				sign = -1;
				p[j] = 0;
			}
			else{
				p[j] = p[j]*10 + (int)ch - 48;
			}
		}
	}
	vector<int> array(p, p+j);
	MergeSort(array, 0, j-1);
	PrintArray(array);
	return 0;
}