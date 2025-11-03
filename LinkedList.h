#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

// Define the node structure of a singly linked list as a structure
typedef struct ListNode {					// 번호, 과일 이름, 가격을 갖는 노드 구조체 정의
	int no;
	char fName[20];
	int price;
	struct ListNode* link;					// link는 이 노드가 가리킬 노드
} listNode;

// Define the head node that represents the start of the list as a structure
typedef struct LinkedList {					// 해더와 길이를 갖는 링크드 리스트 구조체 정의
	listNode* head;
	int length;
}linkedList;


// Fill your code			// Initialize a value
linkedList* initList();
// Fill your code			// Insert as the first node
void insertFirst(linkedList* L, int a, char* b, int c);
// Fill your code			// Insert as the last note
void insertLast(linkedList* L, int a, char* b, int c);
// Fill your code			// delete node
int delete(linkedList* L, listNode* p);
// Fill your code			// search no
listNode* searchNo(linkedList* L, int x);
// Fill your code			// search price
listNode* searchPrice(linkedList* L, int x);
// Fill your code			// Return the number of data in the list
int getLength(linkedList* L);
// Fill your code			// Print all elements of the list
void displayList(linkedList* L);
// Fill your code			// Release the entire memory of the list
void clear(linkedList* L);
// Fill your code			// Sort No. field in ascending order
void selectionSortNo(linkedList* L);
// Fill your code			// Sort Price field in ascending order
void selectionSortPrice(linkedList* L);

#endif