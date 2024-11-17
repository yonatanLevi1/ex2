#include "Profile.h"

void Profile::init(User owner)
{
	_user = owner;
	_userList.init();
	_page.init();

}

void Profile::clear()
{
	_user.clear();
	_userList.clear();
	_page.init();
}

User Profile::getOwner() const
{
	User user;
	user.init(_user.getID(), user.getUserName(), user.getAge());
	return _user;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_userList.add(friend_to_add);
}

void Profile::changeAllWordsInStatus(std::string word)
{
	/*std::string status = _page.getStatus();
	std::string newStatus = " ";
	int count = 0;
	for (int i = 0; status[i] != status.length()-1; i++) {
		if (status[i] == ' ')
			count++;
	}
	for (count = count; count > 0; count--) {
		newStatus += "Magshimim ";
	}*/
}

void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word)
{

}

std::string Profile::getPage()const
{
	std::string tmp = "Status: " + _page.getStatus() + "\n*******************\n*******************";
		if (_page.getPosts() == "")
			tmp += "\n";
		else {
			tmp += _page.getPosts()+"\n";
		}
	return tmp;
}

std::string Profile::getFriends()const
{
	std::string friends = "";
	UserNode* lst = _userList.get_first();
	while (lst->get_next() != NULL) {
		friends += lst->get_data().getUserName() + ",";
		lst = lst->get_next();
	}

	friends += lst->get_data().getUserName();
	return friends;
}

std::string Profile::getFriendsWithSameNameLength()const
{
	std::string friends = "";
	UserNode* lst = _userList.get_first();
	int len = _user.getUserName().length();
	while (lst!= NULL) {
		if(lst->get_data().getUserName().length()==len)
			friends += lst->get_data().getUserName() + ",";
		lst = lst->get_next();
	}
	if(!friends.empty())
		friends.erase(friends.length()-1);
	return friends;
}
