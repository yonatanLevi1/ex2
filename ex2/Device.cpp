#include "Device.h"
#include <string>

Device::Device()
{
	_isActive = true;
	_id = 0;
	_os = "";
}


void Device::init(unsigned int id, DeviceType type, std::string os)
{
	_type = type;
	_id = id;
	_os = os;
}

std::string Device::getOS() const {
	return _os;
}
bool Device::isActive() const {
	return _isActive;
}
void Device::activate() {
	_isActive = true;
}
void Device::deactivate() {
	_isActive = false;
}

unsigned int Device::getID() const
{
	return _id;
}

DeviceType Device::getType()const
{
	return _type;
}
