#pragma once

#include <stdint.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class BaseMessage
{
	public:

		BaseMessage(const uint8_t msgType);
		virtual ~BaseMessage();

		// Enable moving
		BaseMessage(BaseMessage&&) = default;
		BaseMessage& operator=(BaseMessage&&) = default;

		// Disable copying
		BaseMessage(const BaseMessage&) = delete;
		BaseMessage& operator=(const BaseMessage&) = delete;

		const uint8_t getMsgType() const;

	private:

		uint8_t msgType_;

		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & msgType_;
		}
};