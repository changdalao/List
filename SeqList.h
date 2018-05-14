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

SeqList* BuyHead(DataType data);		//�����ڵ�
void InitList(SeqList** ppHead);		//��ʼ������
void PrintList(SeqList *pHead);			//��ӡ����
void PushBack(SeqList** ppHead, DataType data);//β��
void PopBack(SeqList** ppHead);			//βɾ
void PushFront(SeqList** ppHead, DataType data);//ͷ��
void PopFront(SeqList** ppHead);		//ͷɾ
SeqList* FindList(SeqList* pHead,DataType data);//���ҵ�����
void PopList(SeqList** ppHead, SeqList* pos, DataType data);//����λ�ò���
void ListErase(SeqList** ppHead,SeqList* pos);     //ָ��λ��ɾ��
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

