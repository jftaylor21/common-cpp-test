#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <utilities/utilities-stringrpc.h>

class ChatServer
{
public:
  ChatServer();

  bool initialize(const std::string& ip, unsigned int port);

  void onUsername(const Utilities::StringRPC::Message& msg);
  void onSendChat(const Utilities::StringRPC::Message& msg);

private:
  typedef std::map<Utilities::StringRPC::ClientID, std::string> UsernameMap;

  Utilities::StringRPC mRPC;
  UsernameMap mUsernames;
};

#endif
