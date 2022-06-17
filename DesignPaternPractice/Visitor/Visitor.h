#pragma once

class File;
class Directory;

class Visitor
{
public:
	virtual void visit( File file );
	virtual void visit( Directory directory );
};