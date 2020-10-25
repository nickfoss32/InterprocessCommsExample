#include "Messaging/messageBroker.h"
#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

void MessageBroker::threadBody()
{
	using namespace std::chrono_literals;

	while (true)
	{
		try
		{   
			std::cout << "Servicing the msg queue..." << std::endl;

			std::this_thread::sleep_for(1s);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Standard exception caught in MessageBroker thread: " << e.what() << std::endl;
		}
	}
}