#include "ChatServer.h"
#include "ChatCommon.h"

ChatServer::ChatServer()
  : mRPC(true)
{
  mRPC.addCallback(ChatCommon::MESSAGE_USERNAME,
                   Utilities::StringRPC::MessageObjectCallback<ChatServer>(this, &ChatServer::onUsername));
  mRPC.addCallback(ChatCommon::MESSAGE_SENDCHAT,
                   Utilities::StringRPC::MessageObjectCallback<ChatServer>(this, &ChatServer::onSendChat));
}

bool ChatServer::initialize(const std::string &ip, unsigned int port)
{
  return mRPC.initialize(ip, port);
}

void ChatServer::onUsername(const Utilities::StringRPC::Message &msg)
{
  if (!mUsernames.count(msg.clientID) && msg.args.size())
  {
    mUsernames[msg.clientID] = msg.args[0];
  }
}

void ChatServer::onSendChat(const Utilities::StringRPC::Message &msg)
{
  if (msg.args.size())
  {
    std::string username("anonymous");
    if (mUsernames.count(msg.clientID))
    {
      username = mUsernames[msg.clientID];
    }

    Utilities::StringRPC::ArgsList args;
    args.push_back(username);
    args.push_back(msg.args[0]);
    mRPC.send(ChatCommon::MESSAGE_CHAT,
              Utilities::StringRPC::CLIENTID_BROADCAST,
              args);
  }
}
