#include"SeqList.h"

int main()
{
	SeqList* pHead = NULL;
	SeqList* head = NULL;
	InitList(&pHead);
	InitList(&head);
//////////////////////////////////
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	PushBack(&pHead,5);
	PushBack(&pHead,6);
	PushBack(&pHead,7);
	PushBack(&pHead,8);
	PushBack(&pHead, 9);
	printf("判断是否是循环链表>%d\n", SeqListFloyd(pHead));
	PushBack(&head, 0);
	PushBack(&head, 2);
	PushBack(&head, 6);
	PushBack(&head, 8);
	PushBack(&head, 10);
	PushBack(&head, 11);
	PushBack(&head, 12);

	/*printf("尾插->\n");
	PrintList(pHead);
///////////////////////////////////
	printf("尾删->\n");
	PopBack(&pHead);
	PrintList(pHead);
///////////////////////////////////
	printf("头插->\n");
	PushFront(&pHead, 0);
	PrintList(pHead);
//////////////////////////////////
	printf("头删->\n");
	PopFront(&pHead);
	PrintList(pHead);
//////////////////////////////////
	printf("指定位置插入->\n");
	PopList(&pHead,pHead->_next, 6);
	PrintList(pHead);
//////////////////////////////////
	printf("指定位置删除->\n");
	ListErase(&pHead, pHead->_next);
	PrintList(pHead);*/
///////////////////////////////////
//	printf("初始链表>");
//	PrintList(pHead);
//	printf("从尾到头打印> ");
//	SLitsPrintTailToHead(pHead);
//	printf("\n");
//////////////////////////////////////////
//	printf("初始链表>");
//	PrintList(pHead);
//	printf("删除一个无头单链表的非尾节点>");
//	SListDelNonTailNode(pHead->_next);
//	PrintList(pHead);
///////////////////////////////////////////////
//	printf("初始链表>");
//	PrintList(pHead);
//	printf("在无头单链表的一个节点前插入一个节点>");
//	NoHeadSeqListInsert(&pHead, pHead->_next, 2);
//	PrintList(pHead);
//////////////////////////////////////////////////
//	printf("逆置单链表> ");
//	SeqListReverse(&pHead);
//	PrintList(pHead);
///////////////////////////////////////////////
//	printf("冒泡排序> ");
//	SListBubbleSort(pHead);
//	PrintList(pHead);
//////////////////////////////////////////////
//	/*printf("合并有序链表> ");
//	SListMerge(&pHead,&head);*/
////////////////////////////////////////////
//	printf("寻找中间节点> ");
//	SeqList* pos = SListFindMidNode(&pHead);
//	printf("中间节点数据>%d\n", pos->_data);
//////////////////////////////////////////
//	SeqList* cur=SListFindTailKNode(&pHead, 3);
//	printf("倒数第三个节点数据>%d\n", cur->_data);
//	printf("倒数第三个节点地址>%#p\n", &cur);
//////////////////////////////////////////////
//	printf("初始链表> ");
//	PrintList(pHead);
//	printf("删除倒数第三个节点> ");
//	DeleteKNode(&pHead, 3);
//	PrintList(pHead);
//	NoHeadSeqListInsert(&pHead, pHead->_next->_next->_next->_next->_next, 6);
	//PrintList(pHead);
	//SeqList* tmp= CircleSListNode(&pHead);
	//printf("交点数据>%d\n", tmp->_data);
	test11(&pHead);
	system("pause");
	return 0;
}