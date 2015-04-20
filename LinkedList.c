#include "LinkedList.h"

NODE* newNode(int value, NODE *next) {
	NODE *node;
	node = malloc(sizeof(NODE));

	if (node == NULL) {
		return NULL;
	}

	node -> value = value;
	node -> next = next;

	return node;
}

NODE* newNodes(int arg_num, ...) {
	va_list args;
	int i;
	int value;
	NODE *node;

	if (arg_num < 1) {
		return NULL;
	}

	va_start(args, arg_num);

	value = va_arg(args, int);
	node = newNode(value, NULL);

	for (i = 0; i < arg_num - 1; i++) {
		value = va_arg(args, int);
		appendNode(value, &node);
	}
	
	return node; 
}

bool prependNode(int value, NODE **list) {
	NODE *node;
	node = newNode(value, *list);

    if (*list == NULL || node == NULL) {
        return false;
    }
	
	*list = node;

	return true;
}

bool appendNode(int value, NODE **list) {
	NODE *node;
	node = newNode(value, NULL);

	if (*list == NULL || node == NULL) {
		return false;
	}
		
	while (*list != NULL) {
		// *list = (*list) -> nextだと先頭を指すポインタを変えてしまう。
		list = &((*list) -> next);
	}
		
	*list = node;

	return true;
}

bool insertNode(int index, int value, NODE **list) {
	NODE *node;
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *list != NULL; i++) {
		list = &((*list) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	node = newNode(value, *list);

	if (node == NULL) {
		return false;
	}

	*list = node;

	return true;
}

bool deleteNode(int index, NODE **list) {
	NODE *deleteNode;
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *list != NULL; i++) {
		list = &((*list) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	deleteNode = *list;
	*list = (*list) -> next;
	free(deleteNode);

	return true;
}

bool updateNode(int index, int value, NODE **list) {
	int i;

	if (index < 0) {
		return false;
	}

	for (i = 0; i < index && *list != NULL; i++) {
		list = &((*list) -> next);
	}

	// この時点でiがindexより小さいということは、indexがlist長を超えていることを示す。
	if (i < index) {
		return false;
	}

	(*list) -> value = value;

	return true;
}

int getNumNodes(NODE *list) {
	int num = 0;

	while (list != NULL) {
		list = list -> next;
		num++;
	}

	return num;
}

int searchValue(int value, NODE *list) {
	int index = 0;

	while (list != NULL) {
		if (list -> value == value) {
			return index;
		}

		list = list -> next;
		index++;
	}

	return -1;
}

void deleteAllNodes(NODE **list) {
	NODE *node;
	
	while (*list != NULL) {
		node = *list;
		*list = (*list) -> next;
		free(node);
		node = NULL;
	}
}

void printList(NODE *list) {
	printf("{ ");

	while (list != NULL) {
		printf("%d ", list -> value);
		list = list -> next;
	}

	printf("}\n");
}

