#include <utilities/utilities-screen.h>
#include <utilities/utilities-time.h>
#include <utilities/utilities-stringrpc.h>

Utilities::StringRPC rpcServer(true);
Utilities::StringRPC rpcClient(false);
std::string input;

void echoServerCallback(const Utilities::StringRPC::MessageID& msg,
                        const Utilities::StringRPC::ClientID& id,
                        const Utilities::StringRPC::ArgsList& args)
{
  if (args.size())
  {
    std::cout << "server " << args[0] << std::endl;
    rpcServer.send(msg, args, id);
  }
  else
  {
    std::cout << "missing arguments" << std::endl;
  }
}

void echoClientCallback(const Utilities::StringRPC::MessageID& msg,
                        const Utilities::StringRPC::ClientID& id,
                        const Utilities::StringRPC::ArgsList& args)
{
  if (args.size())
  {
    std::cout << "client " << args[0] << std::endl;
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

  while (!rpcClient.initialize(serverIp, 44444))
  {
    std::cout << "Waiting for RPC client" << std::endl;
    Utilities::sleep(100);
  }

  std::cout << "Successfully connected to RPC server" << std::endl;
  rpcClient.addCallback(21, &echoClientCallback);

  while(input != "quit")
  {
    Utilities::StringRPC::ArgsList args;
    std::cout << std::endl
              << "Please enter line to echo: ";
    getline(std::cin, input);
    args.push_back(input);
    rpcClient.send(21, args);
  }

  return 0;
}
