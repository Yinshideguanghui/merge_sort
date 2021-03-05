#pragma once
#include<iostream>
using namespace std;

enum Error_code { success, underflow, overflow, Range_error, not_present, fail };

template <class Node_entry>
struct Node		//节点
{
	Node_entry entry;
	Node<Node_entry>* next;

	Node() {}
	Node(Node_entry entry_, Node<Node_entry>* link = NULL) :entry(entry_), next(link) {}
};

class Key		//键
{
public:
	Key(char item = '\0') :item_(item) {}
	bool operator == (Key& k) { return item_ == k.item_; }
	bool operator > (Key& k) { return item_ > k.item_; }
	bool operator < (Key& k) { return item_ < k.item_; }
	bool operator >= (Key& k) { return item_ >= k.item_; }
	bool operator <= (Key& k) { return item_ <= k.item_; }
protected:
	char item_;
};
class Record	//记录的项目
{
public:
	Record(char Item = '\0') :item(Item) {}
	operator Key() const
	{
		Key k(item);
		return k;
	}
	char retrieve_item() const { return item; }
protected:
	char item;
};

template<class List_entry>
class List		//表
{
public:
	List() { count = 0; head = NULL; }
	List(const List<List_entry>& copy);
	//void operator = (const List<List_entry>& copy);
	~List() { clear(); }

	int size()const;
	bool empty()const;
	void clear();
	void traverse(void(*visit)(List_entry&));

	Error_code retrieve(int position, List_entry& x)const;
	//Error_code replace(int position, const List_entry& x);
	Error_code remove(int position, List_entry& x);
	Error_code insert(int position, const List_entry& x);
protected:
	int count;
	Node<List_entry>* head;
	Node<List_entry>* set_position(int position)const;
};