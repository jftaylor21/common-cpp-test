#include <utilities/utilities-logger.h>
#include <iostream>

int main()
{
  Utilities::Logger::get().setMaxLogLevel(Utilities::Logger::LOGLEVEL_ERROR);
  std::cout << "screen disabled" << std::endl;
  Utilities::Logger::get().error("Should not see this\n");
  std::cout << "screen enabled max level error" << std::endl;
  Utilities::Logger::get().setScreenEnable(true);
  Utilities::Logger::get().error("Hello World\n");
  Utilities::Logger::get().warning("Should not see this\n");
  Utilities::Logger::get().info("Should not see this\n");
  Utilities::Logger::get().setMaxLogLevel(Utilities::Logger::LOGLEVEL_INFO);
  std::cout << "screen enabled no max level" << std::endl;
  Utilities::Logger::get().error("Hello World\n");
  Utilities::Logger::get().warning("Hello World\n");
  Utilities::Logger::get().info("Hello World\n");
  Utilities::Logger::get().fatal("Hello World\n");
  std::cout << "You should not see this text" << std::endl;
  return 0;
}
