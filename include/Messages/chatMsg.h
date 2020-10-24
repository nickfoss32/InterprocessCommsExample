#pragma once

#include <stdint.h>
#include <string>

#include <boost/serialization/string.hpp>

#include "baseMsg.h"


class ChatMessage : public BaseMessage
{
	public:
	
		static constexpr uint8_t CHAT_MSG_MT = 1;

		ChatMessage() :
			BaseMessage(CHAT_MSG_MT)
		{ }

		ChatMessage(std::string data) :
			BaseMessage(CHAT_MSG_MT)
		{ }

		virtual ~ChatMessage()
		{ }

		const std::string getData() const
		{
			return data_;
		}

	private:

		std::string data_;

		friend class boost::serialization::access;
		// When the class Archive corresponds to an output archive, the
		// & operator is defined similar to <<. Likewise, when the class Archive
		// is a type of input archive the & operator is defined similar to >>.
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<BaseMessage>(*this);
			ar & BOOST_SERIALIZATION_NVP(data_);
		}
};
