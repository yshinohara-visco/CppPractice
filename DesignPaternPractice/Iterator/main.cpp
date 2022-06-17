#include "Bookshelf.h"
#include "BookshelfIterator.h"
#include <iostream>
int main()
{
	BookShelf* bookShelf = new BookShelf( 4 );
	bookShelf->appendBook( Book( "Arround the World in 80 days" ) );
	bookShelf->appendBook( Book( "Bible" ) );
	bookShelf->appendBook( Book( "Cinderella" ) );
	bookShelf->appendBook( Book( "Daddy-Long-legs" ) );

	Iterator* it = bookShelf->iterator();
	while (it->hasNext())
	{
		Book* book = (Book*)it->next();
		std::cout << book->getName() << std::endl;
	}
}