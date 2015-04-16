#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 連結リストを実現するためのノード構造体
 */
typedef struct node {
	int data;
	struct node *next;
} NODE;

/**
 * 新しいノードを作成する関数
 * @param data 最初に入れる値
 * @param *next 次のノードを指すポインタ
 *
 * @return 新しく生成したノード
 */
NODE *newNode(int data, NODE *next) {
	NODE *node;
	node = malloc(sizeof(node));

	if (node == NULL) {
		return NULL;
	}

	node -> data = data;
	node -> next = next;

	return node;
}

/**
 * リストの先頭に要素を追加する関数
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool prependNode(int data, NODE **nodePointer) {
	NODE *node;
	node = newNode(data, *nodePointer);

    if (nodePointer == NULL) {
        return false;
    }
	
	*nodePointer = node;

	return true;
}

/**
 * リストの末尾に要素を追加する関数
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
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

/**
 * リストの指定した位置に要素を追加する関数
 * @param index 追加する位置
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
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

/**
 * リストの指定した位置の要素を削除する関数
 * @param index 削除する位置
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool deleteNode(int index, NODE **nodePointer) {
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

	*nodePointer = (*nodePointer) -> next;

	return true;
}

/**
 * リストの指定した位置の要素を変更する関数
 * @param index 変更する位置
 * @param data 変更後の値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool replaceNode(int index, int data, NODE **nodePointer) {
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

	node = newNode(data, (*nodePointer) -> next);

	if (node == NULL) {
		return false;
	}

	*nodePointer = node;

	return true;
}

/**
 * リストの要素数を取得する関数
 * @param *nodePointer リストの先頭をを指すポインタ
 *
 * @return 要素数
 */
int getNumNodes(NODE *nodePointer) {
	int num = 0;

	while (nodePointer != NULL) {
		nodePointer = nodePointer -> next;
		num++;
	}

	return num;
}

/**
 * 指定した値を検索する関数
 * @param data 検索する値
 * @param *nodePointer 検索対象のリストを指すポインタ
 *
 * @return 指定した値が存在すればindex、存在しなければ-1を返す。
 */
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

/**
 * リストの全要素を削除する関数
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 */
void deleteAllNodes(NODE **nodePointer) {
	NODE *node;
	
	while (*nodePointer != NULL) {
		node = *nodePointer;
		*nodePointer = (*nodePointer) -> next;
		free(node);
	}

	*nodePointer = NULL;
}

/**
 * リストの全要素を標準出力に出力する関数
 * @param *nodePointer リストの先頭をを指すポインタ
 */
void printList(NODE *nodePointer) {
	printf("{ ");

	while (nodePointer != NULL) {
		printf("%d ", nodePointer -> data);
		nodePointer = nodePointer -> next;
	}

	printf("}\n");
}

