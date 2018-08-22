#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
  if (std::strcmp(argv[1], "--help") == 0)
  {
    std::cout << "help page" << std::endl;
  }
  else if (std::strcmp(argv[1], "--run") == 0)
  {
    std::cout << "running example" << std:endl;
  }
  else if (std::strcmp(argv[1], "--list") == 0)
  {
    std::cout << "list example" << std:endl;
  }
  else if (std::strcmp(argv[1], "install") == 0)
  {
    std::cout << "installing thirdparty packages" << std:endl;
  }
  else if (std::strcmp(argv[1], "--view") == 0)
  {
    std::cout << "view" << std:endl;
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [--help] [--run example] [--list] [install --thirdparty] [--view result]"
              << std::endl;

    return 1;
  }

  return 0;
}
