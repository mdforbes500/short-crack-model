#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
  if (std::strcmp(argv[1], "--help") == 0)
  {
    std::cout << "SCMOD Usage:" << std::endl << std::endl
              << argv[0] << " [options]" << std::endl << std::endl
              << "Options:" << std::endl << std::endl
              << "--help                  Prints usage information and exits" << std::endl
              << "--run [example | path]  Builds and runs an example, then exits" << std::endl
              << "--list [flags]          Lists all examples and exits" << std::endl
              << "install [flags] [path]  Installs a thirdparty package, then exits" << std::endl
              << "--view [example | path] Displays results of example, then exits" << std::endl
              << std::endl
              << "Flags:" << std::endl << std::endl
              << "-T                      Thirdparty packages" << std::endl
              << "-E                      Examples" <<std::endl
              << std::endl;
  }
  else if (std::strcmp(argv[1], "--run") == 0)
  {
    std::cout << "running example" << std::endl;
  }
  else if (std::strcmp(argv[1], "--list") == 0)
  {
    std::cout << "list example" << std::endl;
  }
  else if (std::strcmp(argv[1], "install") == 0)
  {
    std::cout << "installing thirdparty packages" << std::endl;
  }
  else if (std::strcmp(argv[1], "--view") == 0)
  {
    std::cout << "view" << std::endl;
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [--help] [--run example] [--list] [install --thirdparty] [--view result]"
              << std::endl;
    return 1;
  }
  return 0;
}
