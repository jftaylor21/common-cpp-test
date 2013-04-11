#include "ChatServer.h"
#include <utilities/utilities-time.h>
#include <utilities/utilities-screen.h>

bool running(false);
void exitCallback()
{
  running = false;
}

int main()
{
  Utilities::installSignalHandler(Utilities::Callback0(exitCallback));

  std::string ip("127.0.0.1");
  Utilities::Socket::localIP(ip);

  unsigned int port(51612);

  std::cout << "initializing server at " << ip << ":" << port << std::endl;
  ChatServer chat;
  if (chat.initialize(ip, port))
  {
    std::cout << "Server initialized" << std::endl;
    running = true;
    while(running)
    {
      Utilities::sleep(100);
    }
  }
  else
  {
    std::cout << "failed to initialize server" << std::endl;
  }
  return 0;
}
