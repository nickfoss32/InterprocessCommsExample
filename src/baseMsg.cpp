#include "Messaging/baseMsg.h"
#include <boost/serialization/access.hpp>

BaseMessage::BaseMessage(const uint8_t msgType) :
	msgType_(msgType)
{ }

BaseMessage::~BaseMessage()
{ }

const uint8_t BaseMessage::getMsgType() const
{
	return msgType_;
}
