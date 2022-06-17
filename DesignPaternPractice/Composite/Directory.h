#pragma once

#include "Entry.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Directory : public Entry
{
public:
    Directory(string name)
    {
        this->name = name;
    }

    string getName() override
    {
        return name;
    }
    
    int getSize()
    {
        int size = 0;
        for (Entry* entry : directory)
        {
            size += entry->getSize();
        }
        return size;
    }

    Entry* add(Entry* entry)
    {
        directory.push_back(entry);
        return this;
    }

    //認識してくれなかった
    using Entry::printList;

    void printList(string prefix) override
    {
        cout << prefix + "/" + this->toString();
        for (Entry* entry : directory)
        {
            entry->printList(prefix + "/" + name);
        }
    }

private:
    string name;
    vector<Entry*> directory;
};