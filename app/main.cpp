#include <iostream>
#include <thread>
#include <string>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "Messaging/messageBroker.h"
#include "Messaging/chatMsg.h"


int main()
{
   try
   {
      std::cout << "Initializing application..." << std::endl;

      //new any required subsystems for this application
      MessageBroker* theBroker = new MessageBroker();

      if (!theBroker)
      {
         std::cout << "Unable to initialize. Exiting..." << std::endl;
         return -1;
      }

      std::cout << "Application Initialized! Starting execution..." << std::endl;

      //spawn required threads
      std::thread t1(&MessageBroker::threadBody, theBroker);

      //wait for threads to finish execution
      t1.join();

      std::cout << "Shutting down..." << std::endl;

      //clean up
      delete theBroker;

      std::cout << "Shutdown complete! Exiting..." << std::endl;
   }
   catch(const std::exception& e)
   {
      std::cerr << "Standard exception caught in main thread: " << e.what() << std::endl;
      return -1;
   }

   //return program success
   return 0;
}
