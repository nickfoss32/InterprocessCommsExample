#pragma once

#include <stdint.h>
#include <boost/serialization/string.hpp>


class BaseMessage
{
	public:

		BaseMessage(const uint8_t msgType) :
			msgType_(msgType)
		{ }
		
		virtual ~BaseMessage()
		{ }

		// Enable moving
		BaseMessage(BaseMessage&&) = default;
		BaseMessage& operator=(BaseMessage&&) = default;

		// Disable copying
		BaseMessage(const BaseMessage&) = delete;
		BaseMessage& operator=(const BaseMessage&) = delete;

		const uint8_t getMsgType() const
		{
			return msgType_;
		}

	private:

		uint8_t msgType_;

		friend class boost::serialization::access;
		// When the class Archive corresponds to an output archive, the
		// & operator is defined similar to <<. Likewise, when the class Archive
		// is a type of input archive the & operator is defined similar to >>.
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & BOOST_SERIALIZATION_NVP(msgType_);
		}
};
