#include <utilities/utilities-stringrpc.h>
#include <utilities/utilities-time.h>
#include <utilities/utilities-screen.h>
#include <iostream>

Utilities::StringRPC rpc(true);
bool running(true);

void echoCallback(const Utilities::StringRPC::MessageID& msg,
                  const Utilities::StringRPC::ClientID& id,
                  const Utilities::StringRPC::ArgsList& args)
{
  if (args.size())
  {
    std::cout << "echo " << args[0] << std::endl;
    rpc.send(msg, args, id);
  }
  else
  {
    std::cout << "missing arguments" << std::endl;
  }
}

void exitCallback()
{
  running = false;
}

int main()
{
  std::cout << "Welcome to stringrpc echoserver" << std::endl;
  Utilities::installSignalHandler(Utilities::Callback0(exitCallback));
  if (rpc.initialize("127.0.0.1", 55432))
  {
    rpc.addCallback(21, &echoCallback);
    std::cout << "Server started. Waiting for client..." << std::endl;
    while(running)
    {
      Utilities::sleep(100);
    }
  }
  else
  {
    std::cout << "Could not initialize StringRPC" << std::endl;
  }

  return 0;
}
