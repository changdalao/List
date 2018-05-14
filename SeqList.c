#include"SeqList.h"

//打印链表
void PrintList(SeqList *pHead)
{
	assert(pHead);
	while (pHead)
	{
		printf("%d ", pHead->_data);
		pHead = pHead->_next;
	}
	printf("\n");
}

//创建链表
SeqList* BuyHead(DataType data)
{
	SeqList* pNewNode = (SeqList*)malloc(sizeof(SeqList));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	return pNewNode;
}

//初始化链表
void InitList(SeqList** ppHead)
{
	*ppHead = NULL;
}

//尾插 
void PushBack(SeqList** ppHead, DataType data)
{
	if (NULL == *ppHead)
		*ppHead = BuyHead(data);
	else
	{
		SeqList *pNewHead = *ppHead;
		while (pNewHead->_next)
		{
			pNewHead = pNewHead->_next;
		}
		pNewHead->_next = BuyHead(data);
	}
}

//尾删
void PopBack(SeqList** ppHead)
{
	assert(*ppHead);
	SeqList* cur = *ppHead;
	SeqList* Tail = NULL;
	if (NULL == *ppHead)
		assert(0);
	else
	{

		while (cur->_next)
		{
			Tail = cur;
			cur = cur->_next;
		}
		free(cur);
		Tail->_next = NULL;
	}
}

//头插
void PushFront(SeqList** ppHead, DataType data)
                                                                                                                                                                                                                                                                                                                                                                                                                             {
	if (NULL == *ppHead)
		*ppHead = BuyHead(data);
	else
	{
		SeqList* cur = BuyHead(data);
		cur->_next = *ppHead;
		*ppHead = cur;
	}
}

//头删
void PopFront(SeqList** ppHead)
{
	assert(*ppHead);
	if (NULL == *ppHead)
		assert(0);
	else
	{
		SeqList* NewNode = *ppHead;
		*ppHead = (*ppHead)->_next;
		free(NewNode);
	}
}

//查找
SeqList* FindList(SeqList* pHead, DataType data)
{
	assert(pHead);
	while (pHead)
	{
		if (data == pHead->_data)
		{
			//printf("找到了->%d\n", pHead->_data);
			return pHead;
		}
		pHead = pHead->_next;
	}
	if (pHead == NULL)
		return NULL;
}

//任意位置插入
void PopList(SeqList** ppHead, SeqList* pos, DataType data)
{
	assert(*ppHead);
	SeqList* NewNode = *ppHead;
	SeqList* cur = NULL;
	if (pos==*ppHead)
		PushFront(*ppHead, data);
	else
	{
		while (NewNode->_next!=pos)
		{
			NewNode = NewNode->_next;

		}
		cur = BuyHead(data);	
		NewNode->_next = cur;
		cur->_next = pos;
	}
}

//指定位置删除
void ListErase(SeqList** ppHead, SeqList* pos)
{
	assert(*ppHead);
	if (*ppHead == pos)
		PopFront(*ppHead);
	else
	{
		SeqList* cur = *ppHead;
		while (cur->_next != pos)
		{
			cur = cur->_next;
		}
		PopFront(&pos);
		cur->_next = pos;
	}
}
