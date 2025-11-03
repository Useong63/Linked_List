#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

linkedList* initList() {
	linkedList* L;										// 링크드 리스트 생성
	L = (linkedList*)malloc(sizeof(linkedList));		// 메오리 확보
	L->head = NULL;										// 해더 노드에 NULL 할당
	L->length = 0;										// 링크드 리스트의 길이 0으로 초기화
	return L;											// 링크드 리스트 반환
}

int getLength(linkedList* L) {
	return L->length;									// 링크드 리스트의 길이 반환
}

void insertFirst(linkedList* L, int a, char* b, int c) {
	listNode* newNode;									// 새 노드 생성
	newNode = (listNode*)malloc(sizeof(listNode));		// 메모리 확보
	newNode->no = a;									// 새 노드에 정보 저장
	strcpy(newNode->fName, b);
	newNode->price = c;
	newNode->link = L->head;							// 새 노드가 가리킬 노드에 해더가 가르키니는 노드 할당
	L->head = newNode;									// 해더가 가리킬 노드에 새 노드 할당
	L->length++;										// 링크드 리스트의 길이 1 증가
}
void insertLast(linkedList* L, int a, char* b, int c) {
	listNode* newNode;									// 새 노드 생성
	listNode* temp;										// 마지막 노드를 찾기 위한 임시 포인터 생성
	newNode = (listNode*)malloc(sizeof(listNode));		// 메모리 확보
	newNode->no = a;									// 새 노드에 정보 저장
	strcpy(newNode->fName, b);
	newNode->price = c;
	newNode->link = NULL;								// 새 노드가 가리킬 노드에 NULL할당

	if (L->head == NULL)								// 해더가 비었으면 즉 빈 리스트이면
	{
		L->head = newNode;								// 해더에 새 노드 할당
	}
	else
	{
		temp = L->head;									// 임시 포인터에 해더 할당
		while (temp->link != NULL)						// 임시 포인터가 가리키는 노드가 비어있지 않으면 즉 마지막이 아니라면 반복
		{
			temp = temp->link;							// 임시 포인터에 다음 노드 할당
		}
		temp->link = newNode;							// 임시 포인터가 마지막 순서가 되었으므로 마지막 노드가 가리키는 노드에 새 노드 할당
	}
	L->length++;										// 리스트의 길이 1 증가
}
int delete(linkedList* L, listNode* p) {
	listNode* pre;										// 제거할 노드의 앞 노드를 가리킬 포인터 생성

	if (L->head == NULL)								// 해더가 비어있으면 즉 빈 리스트이면
	{
		return FALSE;									// FALSE 반환
	}

	if (p == NULL)										// 제거할 노드가 없으면
	{
		return FALSE;									// FALSE 반환
	}

	if (L->head == p)									// 해더가 제거할 노드이면 즉 첫 노드가 제거할 노드이면
	{
		L->head = p->link;								// 해더가 가리킬 노드에 제거할 노드가 가리킬 노드 할당
		free(p);										// 제거할 노드 제거
	}
	else
	{
		pre = L->head;									// 임시 포인터에 해더 할당
		while (pre->link != p)							// 임시 포인터가 가리키는 노드가 제거할 노드가 아니라면 반복
		{
			pre = pre->link;							// 임시 포인터에 다음 노드 할당
			if (pre->link == NULL)						// 임시 포인터가 가리키는 노드가 비었다면 즉 마지막 노드까지 제거할 노드가 없다면
			{
				return FALSE;							// FALSE 반환
			}
		}
		pre->link = p->link;							// 임시 포인터가 가리키는 노드에 제거할 노드가 가리키는 노드 할당
		free(p);										// 제거할 노드 제거
	}
	L->length--;										// 리스트의 길이 1 감소
	return TRUE;										// TRUE 반환
}
listNode* searchNo(linkedList* L, int x) {
	listNode* temp = L->head;							// 노드를 찾기 위한 임시 포인터 생성과 동시에 해더 할당

	while (temp != NULL)								// 임시 포인터가 비어있지 않으면 반복
	{
		if (temp->no == x)								// 임시 포인터의 번호가 찾고자 하는 번호와 같으면
		{
			return temp;								// 임시 포인터 반환
		}
		else
		{
			temp = temp->link;							// 임시 포인터에 다음 노드 할당
		}
	}
	return temp;										// 임시 포인터 반환
}
listNode* searchPrice(linkedList* L, int x) {
	listNode* temp = L->head;							// 노드를 찾기 위한 임시 포인터 생성과 동시에 해더 할당

	while (temp != NULL)								// 임시 포인터가 비어있지 않으면 반복
	{
		if (temp->price == x)							// 임시 포인터의 가격이 찾고자 하는 가격과 같으면
		{
			return temp;								// 임시 포인터 반환
		}
		else
		{
			temp = temp->link;							// 임시 포인터에 다음 노드 할당
		}
	}
	return temp;										// 임시 포인터 반환
}
void displayList(linkedList* L) {
	listNode* p;													// 나열할 노드를 가리킬 포인터 생성
	printf("L=( No., Fruit Name, Price\n--> ");						// 표 출력
	p = L->head;													// 포인터에 해더 할당
	while (p != NULL)												// 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면 반복
	{
		printf("%03d, %10s, %04d", p->no, p->fName, p->price);		// 번호, 과일 이름, 가격 출력
		p = p->link;												// 포인터에 다음 노드 할당
		if (p != NULL)												// 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면
		{
			printf(" \n--> ");										// 화살표 출력
		}
	}
	printf(")\n");													// 마지막 노드 나열 후 ) 출력
}
void clear(linkedList* L) {
	listNode* p;										// 제거할 노드를 가리킬 포인터 생성
	while (L->head != NULL)								// 해더가 비어있지 않다면 즉 빈 리스트가 아니라면 반복
	{
		p = L->head;									// 포인터에 해더 할당
		L->head = L->head->link;						// 해더에 다음 노드 할당
		free(p);										// 첫 노드 제거
		p = NULL;										// 포인터에 NULL 반환
	}
	L->length = 0;										// 리스트의 길이 0으로 초기화
}
void selectionSortNo(linkedList* L) {
	listNode* temp;										// 노드의 벙보를 저장할 임시 포인터 생성
	listNode* min;										// 최소 번호을 갖는 노드를 저장할 포인터 생성
	listNode* next;										// 다음 노드를 가리킬 노드 생성
	int tempNo;											// 정보 이동을 위해 상수 / 문자열을 담을 변수 생성
	char tempfName[20];
	int tempPrice;
	if (L->head == NULL)								// 해더가 비어있으면 즉 빈 리스트이면
	{
		return FALSE;									// FALSE 반환
	}

	temp = L->head;										// 임시 포인터에 해더 할당
	while (temp != NULL)								// 임시 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면 반복
	{
		min = temp;										// 최소 포인터에 임시 포인터 할당
		next = min->link;								// 다음 포인터에 최소 포인터가 가리키는 노드 할당
		while (next != NULL)							// 다음 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면 반복
		{
			if (min->no > next->no)						// 최소 포인터의 번호가 다음 포인터의 번호보다 크면
			{
				min = next;								// 최소 포인터에 다음 포인터 할당
			}
			next = next->link;							// 다음 포인터에 다음 노드 할당
		}

		if (min != temp)								// 최소 포인터가 임시 포인터와 다르면 즉 더 작은 값을 찾았다면
		{
			tempNo = temp->no;							// 임시 포인터의 정보 변수에 저장
			strcpy(tempfName, temp->fName);
			tempPrice = temp->price;

			temp->no = min->no;							// 임시 포인터에 최소 포인터 정보 할당
			strcpy(temp->fName, min->fName);
			temp->price = min->price;

			min->no = tempNo;							// 최소 포인터에 변수값 할당
			strcpy(min->fName, tempfName);
			min->price = tempPrice;
		}
		temp = temp->link;								// 임시 포인터에 다음 노드 할당
	}
}
void selectionSortPrice(linkedList* L) {
	listNode* temp;										// 노드의 벙보를 저장할 임시 포인터 생성
	listNode* min;										// 최소 가격을 갖는 노드를 저장할 포인터 생성
	listNode* next;										// 다음 노드를 가리킬 노드 생성
	int tempNo;											// 정보 이동을 위해 상수 / 문자열을 담을 변수 생성
	char tempfName[20];
	int tempPrice;
	if (L->head == NULL)								// 해더가 비어있으면 즉 빈 리스트이면
	{
		return FALSE;									// FALSE 반환
	}

	temp = L->head;										// 임시 포인터에 해더 할당
	while (temp != NULL)								// 임시 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면 반복
	{
		min = temp;										// 최소 포인터에 임시 포인터 할당
		next = min->link;								// 다음 포인터에 최소 포인터가 가리키는 노드 할당
		while (next != NULL)							// 다음 포인터가 비어있지 않으면 즉 마지막 노드가 아니라면 반복
		{
			if (min->price > next->price)				// 최소 포인터의 가격이 다음 포인터의 가격보다 크면
			{
				min = next;								// 최소 포인터에 다음 포인터 할당
			}
			next = next->link;							// 다음 포인터에 다음 노드 할당
		}

		if (min != temp)								// 최소 포인터가 임시 포인터와 다르면 즉 더 작은 값을 찾았다면
		{
			tempNo = temp->no;							// 임시 포인터의 정보 변수에 저장
			strcpy(tempfName, temp->fName);
			tempPrice = temp->price;

			temp->no = min->no;							// 임시 포인터에 최소 포인터 정보 할당
			strcpy(temp->fName, min->fName);
			temp->price = min->price;

			min->no = tempNo;							// 최소 포인터에 변수값 할당
			strcpy(min->fName, tempfName);
			min->price = tempPrice;
		}
		temp = temp->link;								// 임시 포인터에 다음 노드 할당
	}
}