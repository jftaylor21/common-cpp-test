#ifndef CHATMENU_H
#define CHATMENU_H

#include <utilities/utilities-cli-menu.h>
#include <ChatClient.h>

class ChatMenu : public Utilities::CLIMenu
{
public:
  ChatMenu(ChatClient& client);

  void sendChat();

private:
  ChatClient mClient;
};

#endif
