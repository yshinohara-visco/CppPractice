#include "Director.h"
#include "TextBuilder.h"
#include "HTMLBuilder.h"

int main()
{
	int mode = 1;


	if (mode == 0)
	{
		TextBuilder* textbuilder = new TextBuilder();
		Director* director = new Director(textbuilder);

		director->construct();
		string result = textbuilder->getResult();
		cout << result << endl;
	}
	else if (mode == 1)
	{
		HTMLBuilder* htmlbuilder = new HTMLBuilder();
		Director* director = new Director(htmlbuilder);
		director->construct();
		string filename = htmlbuilder->getRusult();
		cout << filename + "が作成されました。" << endl;
	}
	else
	{
		cout << "modeを0か1に設定してください。" << endl;
	}




	return 0;
}