#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <utilities/utilities-stringrpc.h>

class ChatClient
{
public:
  ChatClient();

  bool joinServer(const std::string& ip, unsigned int port);
  void setUsername(const std::string& username);
  void sendChat(const std::string& chat);

  void onChat(const Utilities::StringRPC::Message& msg);

private:
  Utilities::StringRPC mRPC;
};

#endif
