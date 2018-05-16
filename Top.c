#include"SeqList.h"
#include"List.h"
#include"Stack.h"

//从尾到头打印单链表
void SLitsPrintTailToHead(SeqList* phead)
{
	//栈实现:先进后出
	/*Stack s;
	StackInit(&s);
	while (phead)
	{
		StackPush(&s, phead->_data);//入栈
		phead = phead->_next;
	}
	while (StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));//出栈
		StackPop(&s);
	}*/

	//顺序表实现
	/*List cur;
	SeqInit(&cur);
	while (phead)
	{
		SeqPushFront(&cur, phead->_data);//头插
		phead = phead->_next;
	}
	SeqPrint(&cur);*/

	//递归实现
	if (phead->_next != NULL)
		SLitsPrintTailToHead(phead->_next);
	printf("%d ", phead->_data);

	//非递归
	/*DataType a[10] = { 0 };
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		a[i] = pphead->_data;
		pphead = pphead->_next;
		if (pphead == NULL)
			break;
		count++;
	}
	for (; count >= 0; count--)
	{
		printf("%d ", a[count]);
	}*/
}

//删除一个无头单链表的非尾节点（不能遍历链表）
void SListDelNonTailNode(SeqList* pos)
{
	SeqList* cur = NULL;
	cur = pos->_next;
	pos->_data = cur->_data;
	pos->_next = cur->_next;
	free(cur);
	cur = NULL;
}

//在无头单链表的一个节点前插入一个节点（不能遍历链表)
void NoHeadSeqListInsert(SeqList** pphead,SeqList* pos,DataType data)
{
	//在pos后面插入一个元素cur，然后pos和cur值交换
	if (NULL == *pphead)//如果是第一个节点，直接调用头插
		PushFront(*pphead, data);
	else if (NULL == (*pphead)->_next)//最后一个节点，直接调用尾插
		PushBack(*pphead, data);
	else
	{
		DataType tmp = pos->_data;
		SeqList* cur = BuyHead(data);
		SeqList* pcur = pos->_next;//记住原来pos的下一个位置，插入cur后方便链接
		pos->_next = cur;
		cur->_next = pcur;
		pos->_data = cur->_data;
		cur->_data = tmp;
	}
}

//单链表实现约瑟夫环(JosephCircle)
SeqList* JoseCir(SeqList* phead, size_t k)
{
	assert(phead);
	SeqList* tmp = phead;
	while (tmp->_next != NULL)//如果不是循环链表，先将链表改变为循环单链表
		tmp = tmp->_next;
	tmp->_next = phead;
	SeqList* cur = phead;
	while (cur->_next != cur)
	{
		int count = k;
		while (--count)
			cur = cur->_next;
		SeqList* next = cur->_next;
		cur->_data = next->_data;
		cur->_next = next->_next;
		free(next);
		next = NULL;
	}
	return cur;
}

//逆置单链表
void SeqListReverse(SeqList** pphead)

{
	SeqList *prev = *pphead; //保存头节点
	SeqList *cur = prev->_next;  //保存第二个节点
	SeqList *tmp;                  
	prev->_next = NULL;  //置空头节点的next,变成尾节点
	while (cur != NULL)  //循环逆置 
	{
		tmp = cur->_next;//保存cur的next
		cur->_next = prev;
		prev = cur;//头结点随链表后移
		cur = tmp;
	}
	*pphead = prev;  //逆置后的头
}

//单链表排序（冒泡排序&快速排序）
void SListBubbleSort(SeqList* phead)
{
	SeqList* cur = phead;
	while (cur)
	{
		SeqList* prev = cur->_next;
		int flag = 0;
		while (prev)
		{
			if (cur->_data > prev->_data)
			{
				DataType tmp = cur->_data;
				cur->_data = prev->_data;
				prev->_data = tmp;
				flag = 1;
			}
			prev = prev->_next;
		}
		cur = cur->_next;
		if (0 == flag)
			break;
	}
}

//合并两个有序链表,合并后依然有序
void SListMerge(SeqList** List1,SeqList** List2)
{
	SeqList* list;
	InitList(&list);
	if ((*List1)->_data > (*List2)->_data)//找较小值，当做新链表的头结点
	{
		list = *List2;
		*List2 = (*List2)->_next;
	}
	else
	{
		list = *List1;
		List1 = (*List1)->_next;
	}
	SeqList* tmp = list;//记住新链表的头指针，方便遍历
	while ((*List1) != NULL && (*List2) != NULL)//循环将两表中的较小值入新链表
	{
		if ((*List1)->_data > (*List2)->_data)
		{
			list->_next = BuyHead((*List2)->_data);
			*List2 = (*List2)->_next;
		}
		else
		{
			list->_next = BuyHead((*List1)->_data);
			*List1 = (*List1)->_next;
		}
		list = list->_next;
	}
	if (NULL == (*List1))//有一个表遍历结束时，直接将另一个表链接到新表后
		list->_next = *List2;
	else
		list->_next = *List1;
	PrintList(tmp);
}

//查找单链表的中间节点，要求只能遍历一次链表
SeqList* SListFindMidNode(SeqList** phead)
{
	SeqList* pos;
	SeqList* cur;
	pos = cur = *phead;
	if (NULL == (*phead) || NULL ==(*phead)->_next || NULL == (*phead)->_next->_next)
		return *phead;
	else
	{
		pos = *phead;//快指针
		cur = *phead;//慢指针
		while (pos)
		{
			pos = pos->_next->_next;
			cur = cur->_next;
		}
		return cur;
	}
}

//查找单链表的倒数第k个节点，要求只能遍历一次链表 
SeqList* SListFindTailKNode(SeqList** phead, size_t k)
{
	SeqList* fast, *slow;
	fast = slow = *phead;
	while (--k)//快指针先走k-1步
	{
		if (NULL == fast->_next)
			return *phead;
		 fast = fast->_next;
	}
	while (fast->_next)//快慢指针相差k，快指针到末尾的时候，慢指针恰好到k节点
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
}

//删除链表的倒数第K个结点
void DeleteKNode(SeqList** phead, size_t k)
{
	if (NULL == (*phead))
		return;
	SeqList* fast, *slow;
	fast = slow = *phead;
	SeqList* tmp=NULL;
	while (--k)//快指针先走k-1步
	{
		if (NULL == fast->_next)
			return *phead;
		fast = fast->_next;
	}
	while (fast->_next)
	{
		tmp = slow;//记录k节点的前驱
		fast = fast->_next;
		slow = slow->_next;
	}
	tmp->_next = slow->_next;
	free(slow);
	slow = NULL;
}

//判断单链表是否带环？若带环，求环的长度？求环的入口
//思路：环形操场，跑得快的人总是能追上跑得慢的人   
//fast==slow环形节点 
SeqList* CircleSListNode(SeqList** phead)//求相遇点
{
	assert(*phead);
	SeqList* fast, *slow;
	fast = slow = *phead;//快 慢指针
	while (fast&&fast->_next!=NULL)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (fast == slow)
		{
			return slow;  //返回相遇点
		}
	}
	return NULL;
}
SeqList *CircleEntrySListNode(SeqList *list, SeqList *meet) //求入口点 
{
	SeqList *start;
	assert(list);
	start = list;
	while (meet != start)
	{
		meet = meet->_next;
		start = start->_next;
	}
	return meet;
}
void test11(SeqList** phead)
{
	SeqList* begin, *end;
	PrintList(*phead);
	begin = FindList(*phead, 4);
	end = FindList(*phead, 9);
	end->_next = begin;
	SeqList* tmp = CircleSListNode(phead);
	printf("环入口节点>%d\n", CircleEntrySListNode(*phead,tmp)->_data);
}

//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
void test12()
{

}
int SeqListFloyd(SeqList* phead)
{
	assert(phead);
	SeqList* fast = phead;
	SeqList* slow = phead;
	if (phead->_next == NULL)
		return -1;
	if (phead->_next == phead)
		return 1;
	else
	{
		while ((slow != NULL) && (fast != NULL) && (fast->_next != NULL))
		{
			fast = fast->_next->_next;
			slow = slow->_next;
			if (fast == slow || fast->_next == slow)
				return 1;
		}
		return -1;
	}
}
