#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
  if (argc >= 2)
  {
    std::cerr << "Usage: " << argv[0] << " [--help] [--run example] [--list] [install --thirdparty] [--view result]"
              << std::endl;
    return 1;
  }
  else if (std::strcmp(argv[1], "--help"))
  {
    std::cout << "help page" << std::endl;
  }

  return 0;
}
