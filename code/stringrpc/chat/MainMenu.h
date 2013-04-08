#include <utilities/utilities-cli-menu.h>

class MainMenu : public Utilities::CLIMenu
{
public:
  MainMenu();

  void createGame();
  void joinGame();

private:
  bool joinGame(const std::string& ip, unsigned int port);
};
