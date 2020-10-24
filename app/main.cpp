#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <boost/interprocess/ipc/message_queue.hpp>
// #include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "Messages/chatMsg.h"

class MsgHandler
{
   public:
      
      MsgHandler(std::string queueName) :
         msgQueue_(boost::interprocess::open_or_create, queueName.c_str(), 25, 1000)
      { }

      ~MsgHandler()
      { }

      void threadBody()
      {
         using namespace std::chrono_literals;

         // ChatMessage aMsg;
         // unsigned int priority;
         // boost::interprocess::message_queue::size_type bytesReceived;

         while (true)
         {
            // bytesReceived = 0;
            std::cout << "Servicing the msg queue..." << std::endl;

            // ChatMessage aMsg;

            // std::stringstream iss;
            // std::string serialized_string;
            // serialized_string.resize(1000);
            // msgQueue_.receive(&serialized_string[0], 1000, bytesReceived, priority);
            // iss << serialized_string;

            // boost::archive::text_iarchive ia(iss);
            // ia >> aMsg;

            // if (bytesReceived > 0)
            // {
            //    std::cout << "Message received: " << aMsg.getData() << std::endl;

            //    if (aMsg.getData() == "END")
            //    {
            //       break;
            //    }
            // }

            std::this_thread::sleep_for(1s);
         }
      }

   private:

      boost::interprocess::message_queue msgQueue_;
};


int main()
{
   try
   {    
      std::cout << "Initializing application..." << std::endl;

      //new any required subsystems for this application
      static MsgHandler* theHandler = new MsgHandler("myQueue");

      if (!theHandler)
      {
         std::cout << "Unable to initialize. Exiting..." << std::endl;
         return -1;
      }

      std::cout << "Application Initialized! Starting execution..." << std::endl;

      //spawn required threads
      std::thread t1(&MsgHandler::threadBody, theHandler);

      //TEST - send dummy data
      boost::interprocess::message_queue testQueue(boost::interprocess::open_only, "myQueue");
      ChatMessage chatMsg("END");

      std::stringstream oss;
		boost::archive::text_oarchive oa(oss);
      // oa << chatMsg;
		// std::string serialized_string(oss.str());

      // testQueue.send(serialized_string.data(), serialized_string.size(), 0);

      //wait for threads to finish execution
      t1.join();

      std::cout << "Shutting down..." << std::endl;

      //clean up
      delete theHandler;

      std::cout << "Shutdown complete! Exiting..." << std::endl;
   }
   catch(const std::exception& e)
   {
      std::cerr << "exception caught: " << e.what() << '\n';
      return -1;
   }

   //return program success
   return 0;
}
