#include "Item.h"

#include "Factory.h"
#include "ListFactory.h"


int main()
{
    int mode = 0;

    factory::Factory* factory;
    //if(mode == 0)
    factory = new listfactory::ListFactory(); //「具体的なファクトリーも知らない」部分は妥協
    

	factory::Link* asahi = factory->createLink("朝日新聞", "http://www.asahi.com/");
	factory::Link* yomiuri = factory->createLink("読売新聞", "http://www.yomiuri.co.jp");

	factory::Link* us_yahoo = factory->createLink("Yahoo!", "http://www.yahoo.com/");
	factory::Link* jp_yahoo = factory->createLink("Yahoo!Japan", "http://www.yahoo.co.jp/");
	factory::Link* excite = factory->createLink("Excite", "http://www.excite.com/");
	factory::Link* google = factory->createLink("Gogle", "http://www.google.com/");

	factory::Tray* traynews = factory->createTray("新聞");
    traynews->add(asahi);
    traynews->add(yomiuri);

	factory::Tray* trayyahoo = factory->createTray("Yahoo!");
    trayyahoo->add(us_yahoo);
    trayyahoo->add(jp_yahoo);

	factory::Tray* traysearch = factory->createTray("サーチエンジン");
    traysearch->add(trayyahoo);
    traysearch->add(excite);
    traysearch->add(google);

	factory::Page* page = factory->createPage("LinkPage", "hoge太郎");
    page->add(traynews);
    page->add(traysearch);
    page->output();
}