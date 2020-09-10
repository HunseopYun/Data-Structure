#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ArrayBaseStack.h"	

void StackInit(Stack * pstack) {
	pstack->topIndex = -1;	// topIndex�� -1�� �� ���¸� �ǹ���
}

int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1) // ������ ����ִٸ�
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {	// push ���� ��� �Լ�
	pstack->topIndex += 1;	// ������ �߰��� ���� �ε��� �� ����
	pstack->stackArr[pstack->topIndex] = data;	// ������ ����
}

Data SPop(Stack * pstack) { // pop ���� ��� �Լ�
	int rIdx;

	if (SIsEmpty(pstack)) {
		printf("Stack Memort Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;	// ������ �����Ͱ� ����� �ε��� �� ����
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];	// �����Ǵ� ������ ��ȯ
}

Data SPeek(Stack * pstack) {	// peek ���� ��� �Լ�
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];	// �� ���� ����� ������ ��ȯ
}