#pragma once

template <class T>
class List
{

	/* * * * * * * * * * * DATA TYPES  * * * * * * * * */

public:
	struct listElem
	{
		T data;
		listElem * next;
	};

private:
	/* * * * * * *  Members and methods  * * * * * * */
public:
	void insert(T value)
	{
		listElem * p = new listElem;
		p->data = value;
		p->next = m_head;
		m_head = p;
	}

	bool		isEmpty() const
	{
		return (m_head == nullptr);
	}

	List<T>()
	{
		m_head = nullptr;
	}

	List<T>(const List<T> & l)
	{
		m_head = nullptr;
		listElem * p = l.m_head;
		listElem * q = nullptr;
		if (l.isEmpty() == false)
		{
			m_head = new listElem;
			m_head->data = p->data;
			m_head->next = nullptr;
			q = m_head;
			p = p->next;
		}
		while (p != nullptr)
		{
			//creem un nou nod si il adaugam la sfarsitul listei.
			//pentru a nu parcurge de mai multe ori lista vom retine in q ultimul nod din lista
			q->next = new listElem;
			q = q->next;
			q->data = p->data;
			q->next = nullptr;
			p = p->next;
		}
	}

	~List<T>()
	{
		//Dealocare memorie
		while (!isEmpty())
		{
			removeHead();
		}
	}

	List<T>* operator=(const List<T> &l)
	{
		//1. Dealoca lista curenta
		while (!isEmpty())
		{
			removeHead();
		}

		//2. Copie valorila din lista l
		listElem * p = l.m_head;
		listElem * q = nullptr;
		if (l.isEmpty() == false)
		{
			m_head = new listElem;
			m_head->data = p->data;
			m_head->next = nullptr;
			q = m_head;
			p = p->next;
		}
		while (p != nullptr)
		{
			//creem un nou nod si il adaugam la sfarsitul listei.
			//pentru a nu parcurge de mai multe ori lista vom retine in q ultimul nod din lista
			q->next = new listElem;
			q = q->next;
			q->data = p->data;
			q->next = nullptr;
			p = p->next;
		}
		return this;
	}


	//! Removes the first element of the list
	T removeHead()
	{
		T retValue = 0;
		if (!isEmpty()) {
			retValue = m_head->data;
			listElem * p = m_head;
			m_head = m_head->next;
			delete p;
		}

		return retValue;
	}

protected:
	listElem *	getHead()
	{
		return m_head;
	}

private:
	listElem *	m_head;
	
	/* * * * * * * * * * *    -F.R.I.E.N.D.S.-   * * * * * * * * * * * * */
	friend PointSet;
	friend ConvexPolygon;
};
