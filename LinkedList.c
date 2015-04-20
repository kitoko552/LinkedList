#include "LinkedList.h"

NODE* newNode(int data, NODE *next) {
	NODE *node;
	node = malloc(sizeof(NODE));

	if (node == NULL) {
		return NULL;
	}

	node -> data = data;
	node -> next = next;

	return node;
}

bool prependNode(int data, NODE **nodePointer) {
	NODE *node;
	node = newNode(data, *nodePointer);

    if (nodePointer == NULL) {
        return false;
    }
	
	*nodePointer = node;

	return true;
}

bool appendNode(int data, NODE **nodePointer) {
	NODE *node;
	node = newNode(data, NULL);

	if (nodePointer == NULL) {
		return false;
	}
		
	while (*nodePointer != NULL) {
		// *nodePointer = (*nodePointer) -> nextだと先頭を指すポインタを変えてしまう。
		nodePointer = &((*nodePointer) -> next);
	}
		
	*nodePointer = node;

	return true;
}

bool insertNode(int index, int data, NODE **nodePointer) {
	NODE *node;
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *nodePointer != NULL; i++) {
		nodePointer = &((*nodePointer) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	node = newNode(data, *nodePointer);

	if (node == NULL) {
		return false;
	}

	*nodePointer = node;

	return true;
}

bool deleteNode(int index, NODE **nodePointer) {
	NODE *deleteNode;
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *nodePointer != NULL; i++) {
		nodePointer = &((*nodePointer) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	deleteNode = *nodePointer;
	*nodePointer = (*nodePointer) -> next;
	free(deleteNode);

	return true;
}

bool replaceNode(int index, int data, NODE **nodePointer) {
	NODE *node;
	NODE *deleteNode;
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *nodePointer != NULL; i++) {
		nodePointer = &((*nodePointer) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	node = newNode(data, (*nodePointer) -> next);

	if (node == NULL) {
		return false;
	}

	deleteNode = *nodePointer;
	*nodePointer = node;
	free(deleteNode);

	return true;
}

int getNumNodes(NODE *nodePointer) {
	int num = 0;

	while (nodePointer != NULL) {
		nodePointer = nodePointer -> next;
		num++;
	}

	return num;
}

int searchData(int data, NODE *nodePointer) {
	int index = 0;

	while (nodePointer != NULL) {
		if (nodePointer -> data == data) {
			return index;
		}

		nodePointer = nodePointer -> next;
		index++;
	}

	return -1;
}

void deleteAllNodes(NODE **nodePointer) {
	NODE *node;
	
	while (*nodePointer != NULL) {
		node = *nodePointer;
		*nodePointer = (*nodePointer) -> next;
		free(node);
		node = NULL;
	}
}

void printList(NODE *nodePointer) {
	printf("{ ");

	while (nodePointer != NULL) {
		printf("%d ", nodePointer -> data);
		nodePointer = nodePointer -> next;
	}

	printf("}\n");
}

