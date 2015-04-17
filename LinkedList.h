#ifndef LINKEDLINK_H
#define LINKEDLINK_H

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
 * @return 新しく生成したノードのポインタ
 */
NODE* newNode(int, NODE *);

/**
 * リストの先頭に要素を追加する関数
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool prependNode(int, NODE **);

/**
 * リストの末尾に要素を追加する関数
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool appendNode(int, NODE**);

/**
 * リストの指定した位置に要素を追加する関数
 * @param index 追加する位置
 * @param data 追加する値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool insertNode(int, int, NODE**);

/**
 * リストの指定した位置の要素を削除する関数
 * @param index 削除する位置
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool deleteNode(int, NODE**);

/**
 * リストの指定した位置の要素を変更する関数
 * @param index 変更する位置
 * @param data 変更後の値
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 *
 * @return 成功: true, 失敗: false
 */
bool replaceNode(int, int, NODE**);

/**
 * リストの要素数を取得する関数
 * @param *nodePointer リストの先頭をを指すポインタ
 *
 * @return 要素数
 */
int getNumNodes(NODE*);

/**
 * 指定した値を検索する関数
 * @param data 検索する値
 * @param *nodePointer 検索対象のリストを指すポインタ
 *
 * @return 指定した値が存在すればindex、存在しなければ-1を返す。
 */
int searchData(int, NODE*);

/**
 * リストの全要素を削除する関数
 * @param **nodePointer リストの先頭をを指すポインタのポインタ
 */
void deleteAllNodes(NODE**);

/**
 * リストの全要素を標準出力に出力する関数
 * @param *nodePointer リストの先頭をを指すポインタ
 */
void printList(NODE*);

#endif

