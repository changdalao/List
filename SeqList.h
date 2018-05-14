#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<string.h> 

typedef int DataType;

typedef struct SeqList
{
	DataType _data;
	struct SeqList* _next;
}SeqList;

SeqList* BuyHead(DataType data);		//创建节点
void InitList(SeqList** ppHead);		//初始化链表
void PrintList(SeqList *pHead);			//打印链表
void PushBack(SeqList** ppHead, DataType data);//尾插
void PopBack(SeqList** ppHead);			//尾删
void PushFront(SeqList** ppHead, DataType data);//头插
void PopFront(SeqList** ppHead);		//头删
SeqList* FindList(SeqList* pHead,DataType data);//查找单链表
void PopList(SeqList** ppHead, SeqList* pos, DataType data);//任意位置插入
void ListErase(SeqList** ppHead,SeqList* pos);     //指定位置删除
///////////////////////////////////////////////////////////////////////////////////
void SLitsPrintTailToHead(SeqList* pphead);
SeqList* SListFindMidNode(SeqList** phead);
void SListDelNonTailNode(SeqList* pos);
void NoHeadSeqListInsert(SeqList** pphead, SeqList* pos, DataType data);
void SeqListReverse(SeqList** pphead);
void SListBubbleSort(SeqList* phead);
SeqList* SListFindTailKNode(SeqList** phead, size_t k);
SeqList* CircleSListNode(SeqList** phead);
int SeqListFloyd(SeqList* phead);

