#include"sortable_list_simply_linked.h"

template <class List_entry>		//����
int Sortable_list<List_entry>::max_key(int low, int high)
{
	Node<List_entry>* temp_ptr;
	List_entry temp, temp_largest;
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
	{
		temp_ptr = List<List_entry>::set_position(largest);
		temp_largest = temp_ptr->entry;
		temp_ptr = List<List_entry>::set_position(current);
		temp = temp_ptr->entry;
		if (temp > temp_largest)largest = current;
	}
	return largest;
}

template <class List_entry>		//����
void Sortable_list<List_entry>::Swap(int low, int high)
{
	if (low != high)	//low����high����ִ��
	{
		if (low > high) { int temp = low; low = high; high = temp; }	//ʹlowС��high
		if (low == 0)	//low��ͷ�ڵ�
		{
			Node<List_entry>* temp_low = List<List_entry>::head;
			Node<List_entry>* temp2 = List<List_entry>::set_position(high - 1);
			Node<List_entry>* temp_high = temp2->next;
			Node<List_entry>* temp1 = temp_high->next;
			temp2->next = temp_low;
			temp_high->next = temp_low->next;
			temp_low->next = temp1;
			List<List_entry>::head = temp_high;
		}
		else			//low����ͷ�ڵ�
		{
			Node<List_entry>* temp1, * temp_low, * temp2, * temp_high;
			temp1 = List<List_entry>::set_position(low - 1);
			temp_low = temp1->next;
			temp2 = List<List_entry>::set_position(high - 1);
			temp_high = temp2->next;
			temp1->next = temp_high;
			temp2->next = temp_low;
			temp1 = temp_low->next;
			temp_low->next = temp_high->next;
			temp_high->next = temp1;
			temp1 = temp2 = temp_low = temp_high = NULL;
		}
	}
}

template <class List_entry>		//ѡ������
void Sortable_list<List_entry>::selection_sort()
{
	for (int position = List<List_entry>::count - 1; position > 0; position--)
	{
		int Max = max_key(0, position);
		Swap(Max, position);
	}
}

template <class List_entry>		//�鲢����
void Sortable_list<List_entry>::merge_sort()
{
	recursive_merge_sort(List<List_entry>::head);
}

template <class List_entry>		//�ݹ�鲢����
void Sortable_list<List_entry>::recursive_merge_sort(Node<List_entry>*& sub_list)
{
	if (sub_list != NULL && sub_list->next != NULL)
	{
		Node<List_entry>* second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list, second_half);
	}
}

template <class List_entry>		//���������
Node<List_entry>* Sortable_list<List_entry>::divide_from(Node<List_entry>*& sub_list)
{
	Node<List_entry>* position, * midpoint, * second_half;
	if ((midpoint = sub_list) == NULL)return NULL;
	position = midpoint->next;
	while (position != NULL)		//positionǰ���ٶ���midpoint������
	{
		position = position->next;
		if (position != NULL)
		{
			midpoint = midpoint->next;
			position = position->next;
		}
	}
	second_half = midpoint->next;
	midpoint->next = NULL;
	return second_half;
}

template <class List_entry>		//������������鲢
Node<List_entry>* Sortable_list<List_entry>::merge(Node<List_entry>* first, Node<List_entry>* second)
{
	Node<List_entry>* last_sorted;
	Node<List_entry> combined;		//α�ڵ㣨�ƽڵ㣩
	last_sorted = &combined;
	while (first != NULL && second != NULL)
	{	//����������������ڵ���С��һ��
		if (first->entry <= second->entry)
		{
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;
		}
		else
		{
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}
	//�����������ж��һ����ʣ�ಿ������ȥ
	if (first == NULL)last_sorted->next = second;
	else last_sorted->next = first;
	return combined.next;	//����ʱȥ��α�ڵ�
}