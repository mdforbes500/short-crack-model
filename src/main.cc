#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
  if (argc > 3)
  {
    std::cerr << "Usage: " << argv[0] << " [--help] [--run example] [--list] [install --thirdparty] [--view result]"
              << std::endl;

    return 1;
  }
  if (std::strcmp(argv[1], "--help") == 0)
  {
    std::cout << "help page" << std::endl;
  }

  return 0;
}
