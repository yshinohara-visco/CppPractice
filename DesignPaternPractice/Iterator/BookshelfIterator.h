#pragma once

//#include "Bookshelf.h"
#include "Iterator.h"
#include "Book.h"
class BookShelf;

class BookShelfIterator : public Iterator
{
public:
	BookShelfIterator(BookShelf* bookShelf)
	{
		m_bookShelf = bookShelf;
		m_index = 0;
	}

	bool hasNext()
	{
		if (m_index < m_bookShelf->getLength())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void* next();
	/*相互参照になるのでimple.cppで実装
	{
		Book* book = bookShelf->getBookAt( index );
		index++;
		return book;
	}
	*/

private:
	BookShelf* m_bookShelf;
	int m_index;
};