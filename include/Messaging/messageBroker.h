#pragma once

#include <queue>
#include "baseMsg.h"

class MessageBroker
{
   public:

		MessageBroker() = default;
		~MessageBroker() = default;
      
		// Enable moving
		MessageBroker(MessageBroker&&) = default;
		MessageBroker& operator=(MessageBroker&&) = default;

		// Disable copying
		MessageBroker(const MessageBroker&) = delete;
		MessageBroker& operator=(const MessageBroker&) = delete;

      void threadBody();

   private:

      std::queue<BaseMessage> msgQueue_;
};