#include <utilities/utilities-screen.h>
#include <utilities/utilities-time.h>
#include <utilities/utilities-stringrpc.h>

Utilities::StringRPC rpcServer(true);
Utilities::StringRPC rpcClient(false);
std::string input;

void echoServerCallback(const Utilities::StringRPC::Message& msg)
{
  if (msg.args.size())
  {
    std::cout << "server " << msg.args[0] << std::endl;
    rpcServer.send(msg);
  }
  else
  {
    std::cout << "missing arguments" << std::endl;
  }
}

void echoClientCallback(const Utilities::StringRPC::Message& msg)
{
  if (msg.args.size())
  {
    std::cout << "client " << msg.args[0] << std::endl;
  }
  else
  {
    std::cout << "missing arguments" << std::endl;
  }
}

void exitCallback()
{
  input = "quit";
}

int main()
{
  std::cout << "Welcome to stringrpc echoserverclient" << std::endl;
  Utilities::installSignalHandler(Utilities::Callback0(exitCallback));

  std::string serverIp;
  Utilities::Socket::localIP(serverIp);
  if (rpcServer.initialize(serverIp, 44444))
  {
    rpcServer.addCallback(21, &echoServerCallback);
    std::cout << "Server started." << std::endl;
  }

  rpcClient.initialize(serverIp, 44444);

  std::cout << "Successfully connected to RPC server" << std::endl;
  rpcClient.addCallback(21, &echoClientCallback);

  while(input != "quit")
  {
    Utilities::StringRPC::ArgsList args;
    std::cout << std::endl
              << "Please enter line to echo: ";
    getline(std::cin, input);
    args.push_back(input);
    rpcClient.send(21, Utilities::StringRPC::CLIENTID_SERVER, args);
  }

  return 0;
}
