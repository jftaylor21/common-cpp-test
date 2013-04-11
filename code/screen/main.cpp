#include <utilities/utilities-screen.h>
#include <list>
#include <iostream>

int main()
{
  //color test
  std::list<Utilities::Color> colorlist;
  colorlist.push_back(Utilities::COLOR_BLACK);
  colorlist.push_back(Utilities::COLOR_BLUE);
  colorlist.push_back(Utilities::COLOR_CYAN);
  colorlist.push_back(Utilities::COLOR_GRAY);
  colorlist.push_back(Utilities::COLOR_GREEN);
  colorlist.push_back(Utilities::COLOR_MAGENTA);
  colorlist.push_back(Utilities::COLOR_RESET);
  colorlist.push_back(Utilities::COLOR_RED);
  colorlist.push_back(Utilities::COLOR_WHITE);
  colorlist.push_back(Utilities::COLOR_YELLOW);
  colorlist.push_back(Utilities::COLOR_RESET);
  std::list<Utilities::Color>::const_iterator it(colorlist.begin());
  for(; it != colorlist.end(); ++it)
  {
    Utilities::setTextColor(*it);
    std::cout << "color " << *it << std::endl;
  }

  return 0;
}
