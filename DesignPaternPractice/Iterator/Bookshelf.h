#pragma once

#include "Aggregate.h"
#include "Book.h"

class BookShelf : public Aggregate
{
public:
	BookShelf(int maxsize)
	{
		m_books = new Book[maxsize];
	}

	Book* getBookAt(int index)
	{
		return &m_books[index];
	}

	void appendBook(Book book)
	{
		this->m_books[m_last] = book;
		m_last++;
	}

	int getLength()
	{
		return m_last;
	}

	Iterator* iterator();
	/*相互参照になるのでimple.cppで実装
	{
		return new BookShelfIterator(this);
	}
	*/

private:
	Book* m_books;
	int m_last = 0;
};

