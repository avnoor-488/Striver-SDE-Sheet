int lengthLL(Node *head)
{
	int count = 0;
	Node *temp = head;
	if (head == NULL)
	{
		return 0;
	}
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count ;
}

Node * middlePoint(Node *head)
{

	int len = lengthLL(head), count = 0, data;
	Node *temp = head;
	Node *newList = NULL;
	if (len == 1)return head;
	if (head == NULL)return NULL;
	else
	{
		int mid = len / 2 - 1;
		while (temp != NULL && count < mid )
		{
			temp = temp->next;
			count++;
		}
		// break;
		newList = temp->next;

	}

	return newList;
}
