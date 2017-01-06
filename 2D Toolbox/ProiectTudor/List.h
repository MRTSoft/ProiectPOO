#pragma once

class List
{
public:
	typedef int listType;
	List*	getHead();
	void	insert(listType value);
	bool	isEmpty();
			List();
			List(const List & l);
			~List();
	List*	operator=(const List &l);

protected:

private:
	struct listElem
	{
		listType data;
		listElem * next;
	};
	listElem * m_head;
	
};