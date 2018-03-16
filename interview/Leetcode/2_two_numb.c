#define mallocNode(x)  {x = (struct ListNode*)malloc(sizeof(struct ListNode)); x->next = NULL;}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int nCarry=0, nPreCarry=0, nSum=0;
	struct ListNode *tmp1=NULL, *tmp2=NULL;
	struct ListNode *FirstNode=NULL, *ThisNode=NULL, *NextNode=NULL;
	
	if (l1 == NULL && l2 == NULL)
		return NULL;
		
	tmp1 = l1;
	tmp2 = l2;
	
	mallocNode(FirstNode);
	ThisNode = FirstNode;
	
	while (tmp1 || tmp2)
	{
	    mallocNode(NextNode);
	    
		nSum = 0;
		if(tmp1 != NULL)
			nSum += tmp1->val;
		if(tmp2 != NULL)
			nSum += tmp2->val;
		
		nSum += nPreCarry;
		nCarry = nSum / 10;
		
		NextNode->val = nSum % 10;
		nPreCarry = nCarry;
		
		if (tmp1)
			tmp1 = tmp1->next;
		    
		if (tmp2)
			tmp2 = tmp2->next;
		
		ThisNode->next = NextNode;
		ThisNode = ThisNode->next;
		NextNode = NULL;
	}
	
	if (nPreCarry > 0)
	{
		mallocNode(NextNode);
		NextNode->val = nPreCarry;
		ThisNode->next = NextNode;
	}
	
	return FirstNode->next;
}
