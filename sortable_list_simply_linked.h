#pragma once

#include"list_simply_linked_no_remembering.h"
#include"list_simply_linked_no_remembering.cpp"

template <class List_entry>		//ø…≈≈–Ú±Ì
class Sortable_list :public List<List_entry>
{
public:
	void selection_sort();
	void merge_sort();
private:
	int max_key(int low, int high);
	void Swap(int low, int high);
	void recursive_merge_sort(Node<List_entry>*& sub_list);
	Node<List_entry>* divide_from(Node<List_entry>*& sub_list);
	Node<List_entry>* merge(Node<List_entry>* first, Node<List_entry>* second);
};