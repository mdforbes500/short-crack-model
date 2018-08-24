#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  // Help page
  if (std::strcmp(argv[1], "--help") == 0)
  {
    std::cout << "SCMOD Usage:" << std::endl << std::endl
              << "            "<< argv[0] << " [options]" << std::endl << std::endl
              << "Options:" << std::endl << std::endl
              << "--help                  Prints usage information and exits" << std::endl
              << "--run [example]         Builds and runs an example, then exits" << std::endl
              << "--list [flags]          Lists all examples and exits" << std::endl
              << "install [flags]         Installs a thirdparty package, then exits" << std::endl
              << "--view [example]        Displays results of example, then exits" << std::endl
              << std::endl
              << "Flags:" << std::endl << std::endl
              << "-T             Thirdparty packages" << std::endl
              << "-E             Examples" <<std::endl
              << std::endl;
  }

  // Run an example
  else if (std::strcmp(argv[1], "--run") == 0)
  {
    std::cout << "Searching examples..." << std::endl;
    std::ifstream fin("../build/examples_list.txt");
    std::string temp;
    int found = 0;
    while (std::getline(fin, temp))
    {
      if(std::strcmp(temp.c_str(), argv[2]) == 0)
      {
        std::cout << "   Running " << temp.c_str() << std::endl;
        std::system((std::string("../scripts/casting.sh ") + argv[2]).c_str());
        found = 1;
      }
    }
    fin.close();
    if (found == 0)
    {
      std::cerr << "   Example not found: please check the list of examples" << std::endl
                << "     Try running `scmod --list -E` to see list of examples" << std::endl;
    }
  }

  // For listing thirdparty packages and examples
  else if (std::strcmp(argv[1], "--list") == 0)
  {
    // List all thirdparty packages
    if (std::strcmp(argv[2], "-T") == 0)
    {
      std::cout << "Thirdparty Packages:" << std::endl << std::endl
                << "  deal.II" << std::endl
                << "  Trilinos" << std::endl
                << "  PetSc" << std::endl
                << "  p4est" << std::endl
                << "  Metis" << std::endl
                << "  PRISM packages" << std::endl
                << "  Paraview" << std::endl
                << "  Trelis" << std::endl
                << "  VisIt" << std::endl
                << std::endl;
    }

    // List all Examples
    else if (std::strcmp(argv[2], "-E") == 0)
    {
      std::system("../scripts/dindex.sh");
      std::cout << std::endl;
      std::ifstream fin("../build/examples_list.txt");
      std::string temp;
      while (std::getline(fin, temp))
      {
        std::cout << temp << std::endl;
      }
      fin.close();
      std::cout << std::endl;
    }

    // For invalid flags
    else
    {
      std::cerr << "Usage: " << argv[0] << " --list [-T | -E]" << std::endl
                << "Please specify a relevant flag..."
                << std::endl;
      return 2;
    }
  }

  // For installing thirdparty packages
  else if (std::strcmp(argv[1], "install") == 0)
  {
    std::cout << "installing thirdparty packages" << std::endl;
  }

  // For viewing results
  else if (std::strcmp(argv[1], "--view") == 0)
  {
    std::cout << "Searching examples..." << std::endl;
    std::ifstream fin("../build/examples_list.txt");
    std::string temp;
    int found = 0;
    while (std::getline(fin, temp))
    {
      if(std::strcmp(temp.c_str(), argv[2]) == 0)
      {
        std::cout << "   Displaying results " << temp.c_str() << std::endl;
        std::system((std::string("../scripts/display.sh ") + argv[2]).c_str());
        found = 1;
      }
    }
    fin.close();
    if (found == 0)
    {
      std::cerr << "   Example not found: please check the list of examples" << std::endl
                << "     Try running `scmod --list -E` to see list of examples" << std::endl;
    }
  }

  // Usage errors
  else
  {
    std::cerr << "Usage: " << argv[0] << " [--help] [--run example | path] [--list -T | -E] [install -T | -E path] [--view example | path]"
              << std::endl;
    return 1;
  }
  return 0;
}
