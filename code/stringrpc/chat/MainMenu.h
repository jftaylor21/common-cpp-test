#include <utilities/utilities-cli-menu.h>
#include <ChatClient.h>
#include <ChatServer.h>

class MainMenu : public Utilities::CLIMenu
{
public:
  MainMenu();

  void setUsername();
  void setIP();
  void setPort();
  void createServer();
  void joinServer();

private:
  bool joinServer(const std::string& ip, unsigned int port);

  ChatClient mClient;
  ChatServer mServer;
  std::string mUsername;
  std::string mIP;
  std::string mPort;
};
