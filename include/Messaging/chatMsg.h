#pragma once

#include <string>
#include <stdint.h>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "baseMsg.h"

class ChatMessage : public BaseMessage
{
	public:
	
		static constexpr uint8_t CHAT_MSG_MT = 1;

		ChatMessage();
		ChatMessage(std::string data);

		virtual ~ChatMessage();

		const std::string getData() const;

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
			ar & data_;
		}
};
