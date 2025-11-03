#include <stdio.h>
#include "LinkedList.h"

void main() {
	linkedList* L;
	listNode* p;

	printf("\n\n(1) Create & init List\n");		// (1)
	L = initList();
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));

	printf("\n(2) input data : Insertion \n");	// (2)
	// Fill your code
	insertLast(L, 19, "Apple", 4000);
	insertLast(L, 235, "Banana", 2500);
	insertLast(L, 96, "Cherry", 3000);
	insertLast(L, 270, "Orange", 2000);
	insertLast(L, 15, "Mango", 3500);
	insertLast(L, 675, "Pineapple", 6000);
	insertLast(L, 438, "Grape", 5500);
	insertLast(L, 561, "Strawberry", 3200);
	insertLast(L, 735, "Peach", 4500);
	insertLast(L, 856, "Lemon", 1800);
	insertLast(L, 889, "Chair", 100000);
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));

	printf("\n(3) Search for No. & Price \n");	// (3)
	printf("- search Price 1800\n");
	p = searchPrice(L, 1800);
	if (p == NULL)
		printf(" :data not found\n");
	else
		printf(" :fName-> %s ,price-> %d \n", p->fName, p->price);
	// Fill your code
	printf("- search No. 888\n");
	p = searchNo(L, 888);
	if (p == NULL)
		printf(" :data not found\n");
	else
		printf(" :fName-> %s ,price-> %d \n", p->fName, p->price);

	printf("- search No. 889\n");
	p = searchNo(L, 889);
	if (p == NULL)
		printf(" :data not found\n");
	else
		printf(" :fName-> %s ,price-> %d \n", p->fName, p->price);

	printf("\n(4) delete node of [P] : Deletion\n");	// (4)
	// Fill your code
	p = searchNo(L, 889);
	delete(L, p);
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));

	printf("\n(5) sort for No.\n");		// (5)
	// Fill your code 
	selectionSortNo(L);
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));

	printf("\n(6) sort for Price\n");		// (6)
	// Fill your code 
	selectionSortPrice(L);
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));

	printf("\n(7) All data clear\n");		// (7)
	// Fill your code 
	clear(L);
	displayList(L);
	printf("Number of data in List(L): %d\n", getLength(L));
}