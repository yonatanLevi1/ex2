#pragma once
#include "User.h"
#include "Page.h"
#include "Userlist.h"
class Profile {
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	void changeAllWordsInStatus(std::string word);
	void changeWordInStatus(std::string word_to_replace,std::string new_word);
	std::string getPage()const;
	std::string getFriends()const;
	std::string getFriendsWithSameNameLength()const;
private:
	User _user;
	Page _page;
	UserList _userList;
};