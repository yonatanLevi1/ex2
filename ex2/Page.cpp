#include "Page.h"
#include <iostream>

void user::init()
{
	_posts = "";
	_status = "";
}

std::string user::getPosts()
{
	return _posts;
}

std::string user::getStatus()
{
	return _status;
}

void user::clearPage()
{
	_posts = "";
}

void user::setStatus(std::string status)
{
	_status = status;
}

void user::addLineToPosts(std::string new_line)
{
	_posts += "\n" + new_line;
		
}
