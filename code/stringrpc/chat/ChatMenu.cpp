#include "ChatMenu.h"

ChatMenu::ChatMenu(ChatClient &client)
  : Utilities::CLIMenu("Chatting as "+client.username()),
    mClient(client)
{
  addChoice("Send Message", Utilities::ObjectCallback0<ChatMenu>(this, &ChatMenu::sendChat));
  setExitString("Disconnect");
}

void ChatMenu::sendChat()
{
  std::cout << "Please enter message" << std::endl;
  std::string msg;
  getline(std::cin, msg);
  mClient.sendChat(msg);
}
