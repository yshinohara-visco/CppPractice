/*
　相互参照しているコードをJavaパワーで実行しているらしいが
  C++的にはできないのでそれぞれ前方宣言した上で実装を分けるクソださコードに
*/

#include "Bookshelf.h"
#include "BookshelfIterator.h"

Iterator* BookShelf::iterator()
{
	return new BookShelfIterator( this );
}


void* BookShelfIterator::next()
{
	Book* book = m_bookShelf->getBookAt( m_index );
	m_index++;
	return book;
}