#include <utilities/utilities-logger.h>
#include <iostream>

int main()
{
  Utilities::Logger::get().error("Hello World");
  Utilities::Logger::get().warning("Hello World");
  Utilities::Logger::get().info("Hello World");
  Utilities::Logger::get().fatal("Hello World");
  std::cout << "You should not see this text" << std::endl;
  return 0;
}
