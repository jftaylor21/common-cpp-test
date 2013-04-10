#include "ChatClient.h"
#include "ChatCommon.h"
#include <iostream>

ChatClient::ChatClient()
  : mRPC(false),
    mUsername("anonymous")
{
  mRPC.addCallback(ChatCommon::MESSAGE_CHAT,
                   Utilities::StringRPC::MessageObjectCallback<ChatClient>(this, &ChatClient::onChat));
}

bool ChatClient::joinServer(const std::string &ip, unsigned int port)
{
  return mRPC.initialize(ip, port);
}

void ChatClient::setUsername(const std::string &username)
{
  if (mRPC.initialized())
  {
    Utilities::StringRPC::ArgsList args;
    args.push_back(username);
    mRPC.send(ChatCommon::MESSAGE_USERNAME,
              Utilities::StringRPC::CLIENTID_SERVER,
              args);
  }
  else
  {
    std::cout << "ChatClient::setUsername: ChatClient still uninitialized" << std::endl;
  }
}

void ChatClient::sendChat(const std::string &chat)
{
  if (mRPC.initialized())
  {
    Utilities::StringRPC::ArgsList args;
    args.push_back(chat);
    mRPC.send(ChatCommon::MESSAGE_SENDCHAT,
              Utilities::StringRPC::CLIENTID_SERVER,
              args);
  }
  else
  {
    std::cout << "ChatClient::sendChat: ChatClient still uninitialized" << std::endl;
  }
}

void ChatClient::onChat(const Utilities::StringRPC::Message &msg)
{
  if (msg.args.size() > 1)
  {
    std::string username(msg.args[0]);
    std::string chat(msg.args[1]);
    std::cout << "Received: " << username << ": " << chat << std::endl;
  }
  else
  {
    std::cout << "ChatClient::onChat: Not enough args" << std::endl;
  }
}

std::string ChatClient::username() const
{
  return mUsername;
}
