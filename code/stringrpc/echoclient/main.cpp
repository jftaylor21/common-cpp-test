#include <utilities/utilities-stringrpc.h>
#include <utilities/utilities-time.h>
#include <iostream>

Utilities::StringRPC rpc(false);

void echoCallback(const Utilities::StringRPC::MessageID& msg,
                  const Utilities::StringRPC::ClientID& id,
                  const Utilities::StringRPC::ArgsList& args)
{
  if (args.size())
  {
    std::cout << "echo " << args[0] << std::endl;
  }
  else
  {
    std::cout << "missing arguments" << std::endl;
  }
}

int main()
{
  std::cout << "Welcome to stringrpc echoserver" << std::endl;
  while (!rpc.initialize("127.0.0.1", 55432))
  {
    std::cout << "Waiting for RPC server" << std::endl;
    Utilities::sleep(100);
  }

  std::cout << "Successfully connected to RPC server" << std::endl;
  rpc.addCallback(21, &echoCallback);
  while(true)
  {
    Utilities::StringRPC::ArgsList args;
    std::string input;
    std::cout << std::endl
              << "Please enter line to echo: ";
    getline(std::cin, input);
    args.push_back(input);
    rpc.send(21, args);
  }

  return 0;
}
