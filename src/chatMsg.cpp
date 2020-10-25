#include "Messaging/chatMsg.h"
#include <boost/serialization/access.hpp>

ChatMessage::ChatMessage() :
	BaseMessage(CHAT_MSG_MT)
{ }

ChatMessage::ChatMessage(std::string data) :
	BaseMessage(CHAT_MSG_MT),
	data_(data)
{ }

ChatMessage::~ChatMessage()
{ }

const std::string ChatMessage::getData() const
{
	return data_;
}
