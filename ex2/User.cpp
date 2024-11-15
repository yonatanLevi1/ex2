#include "User.h"
#include <iostream>

void User::init(unsigned int id, std::string username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;
	_deviceList.init();
}

void User::clear()
{
	_id = 0;
	_username = "";
	_age = 0;
	_deviceList.init();
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices() 
{
	DevicesList& tmp1 = _deviceList;
	return tmp1;
}

void User::addDevice(Device newDevice)
{
	_deviceList.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* first = _deviceList.get_first();
	while (first != NULL) {
		if (first->get_data().isActive() == false)
			return false;
		first = first->get_next();
	}
	return true;
}
