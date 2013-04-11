#include "MainMenu.h"
#include "ChatMenu.h"
#include <utilities/utilities-socket.h>
#include <utilities/utilities-string.h>

MainMenu::MainMenu()
  : Utilities::CLIMenu("Welcome to chat"),
    mUsername("anonymous"),
    mIP("127.0.0.1"),
    mPort("55555")
{
  Utilities::Socket::localIP(mIP);

  addChoice("Username", Utilities::ObjectCallback0<MainMenu>(this, &MainMenu::setUsername), &mUsername);
  addChoice("Server IP Address", Utilities::ObjectCallback0<MainMenu>(this, &MainMenu::setIP), &mIP);
  addChoice("Server Port", Utilities::ObjectCallback0<MainMenu>(this, &MainMenu::setPort), &mPort);
  addChoice("Create and Join Server", Utilities::ObjectCallback0<MainMenu>(this, &MainMenu::createServer));
  addChoice("Join Server", Utilities::ObjectCallback0<MainMenu>(this, &MainMenu::joinServer));
}

void MainMenu::setUsername()
{
  std::cout << "Please enter username:" << std::endl;
  getline(std::cin, mUsername);
}

void MainMenu::setIP()
{
  std::cout << "Please enter IP address (x.x.x.x):" << std::endl;
  std::string ip;
  std::cin >> ip;
  while (!Utilities::Socket::validateIP(ip))
  {
    std::cout << "Invalid IP address" << std::endl
              << "Please enter IP address (x.x.x.x):" << std::endl;
    std::cin >> ip;
  }
  mIP = ip;
}

void MainMenu::setPort()
{
  std::cout << "Please enter port number (49152-65535):" << std::endl;
  unsigned int port;
  std::cin >> port;
  while (port < 49152 || port > 65535)
  {
    std::cout << "Invalid port" << std::endl
              << "Please enter port number (49152-65535):" << std::endl;
    std::cin >> port;
  }
  mPort = Utilities::toString(port);
}

void MainMenu::createServer()
{
  if (mServer.initialize(mIP, Utilities::toInt(mPort)))
  {
    std::cout << "Server initialized" << std::endl;
    joinServer();
  }
  else
  {
    std::cout << "Failed to create server" << std::endl;
  }
}

void MainMenu::joinServer()
{
  ChatClient client;
  if (client.joinServer(mIP, Utilities::toInt(mPort)))
  {
    std::cout << "Joined Server" << std::endl;

    client.setUsername(mUsername);
    ChatMenu menu(client);
    menu.display();
  }
  else
  {
    std::cout << "Failed to join server" << std::endl;
  }
}
