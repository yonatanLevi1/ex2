#include "SocialNetwork.h"


void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profileList.init();
}

void SocialNetwork::clear()
{
	_networkName = "";
	_minAge = 0;
	_profileList.init();
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
		return false;
	_profileList.add(profile_to_add);
	return true;



	return true;
	
}

std::string SocialNetwork::getWindowsDevices()
{
	std::string tmp = "";
	ProfileNode* lst = _profileList.get_first();
	DeviceNode* lstIn;
	while (lst != NULL) {
		lstIn = lst->get_data().getOwner().getDevices().get_first();
		while (lstIn != NULL) {
			if(!lstIn->get_data().getOS().find("Windows"))
				tmp += "[" + std::to_string(lstIn->get_data().getID()) + ", "+lstIn->get_data().getOS()+"], ";
			lstIn = lstIn->get_next();
		}
		lst = lst->get_next();
	}
	if (tmp.length() - 2 >= 0)
		return tmp.erase(tmp.length() - 2);
	else
		return tmp;
}
