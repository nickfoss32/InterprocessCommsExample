#pragma once

#include <string>
#include <boost/interprocess/ipc/message_queue.hpp>

#include "Messages/chatMsg.h"

class Client
{
	public:

		Client(std::string queueName) :
			msgQueue_(boost::interprocess::open_only, queueName.c_str())
		{ }

		~Client()
		{ }

		bool startProcessing()
		{
			return true;
		}

	private:

		boost::interprocess::message_queue msgQueue_;
};
