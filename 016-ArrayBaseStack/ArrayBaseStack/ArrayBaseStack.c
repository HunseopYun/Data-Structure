#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ArrayBaseStack.h"	

void StackInit(Stack * pstack) {
	pstack->topIndex = -1;	// topIndex의 -1은 빈 상태를 의미함
}

int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1) // 스택이 비어있다면
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {	// push 연산 담당 함수
	pstack->topIndex += 1;	// 데이터 추가를 위한 인덱스 값 증가
	pstack->stackArr[pstack->topIndex] = data;	// 데이터 저장
}

Data SPop(Stack * pstack) { // pop 연산 담당 함수
	int rIdx;

	if (SIsEmpty(pstack)) {
		printf("Stack Memort Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;	// 삭제할 데이터가 저장된 인덱스 값 저장
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];	// 삭제되는 데이터 반환
}

Data SPeek(Stack * pstack) {	// peek 연산 담당 함수
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];	// 맨 위에 저장된 데이터 반환
}