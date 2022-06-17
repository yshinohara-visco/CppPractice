#include "Directory.h"
#include "File.h"

int main()
{
    try
    {
        cout << "Making root entries..." << endl;
        Directory* rootdir = new Directory("root");
        Directory* bindir = new Directory("bin");
        Directory* tmpdir = new Directory("tmp");
        Directory* usrdir = new Directory("usr");

        rootdir->add(bindir);
        rootdir->add(tmpdir);
        rootdir->add(usrdir);
        bindir->add(new File("vi", 10000));
        bindir->add(new File("latex", 20000));
        rootdir->printList();

        //ファイルにファイルを入れようとした時
        //File* hoge = new File("hoge", 1);
        //hoge->add(new File("hogehoge", 10000000));


        cout << endl;
        cout << "Making user entries..." << endl;
        Directory* yuki = new Directory("yuki");
        Directory* hanako = new Directory("hanako");
        Directory* tomura = new Directory("tomura");
        usrdir->add(yuki);
        usrdir->add(hanako);
        usrdir->add(tomura);
        yuki->add(new File("dialy.htmo", 100));
        yuki->add(new File("composit.java", 200));
        hanako->add(new File("mmeo.text", 300));
        tomura->add(new File("game.doc", 400));
        tomura->add(new File("junk.mail", 500));
        rootdir->printList();


    }
    catch (FileTreatmentException e)
    {
        cout << e.what() << endl;
    }


    return 0;
}