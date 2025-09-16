#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: incorrect argument number!" << " "
                  << "Usage: <filename> <string1> <string2>" << std::endl;
        return (1);
    }

    std::string infile = std::string(av[1]);
    std::string outfile = infile + ".replace";
    std::string s1 = std::string(av[2]);
    std::string s2 = std::string(av[3]);

    if (infile.empty())
    {
        std::cerr << "Error: filename is empty!" << std::endl;
        return (1);
    }

    if (s1.empty())
    {
        std::cerr << "Error: string1 is empty!" << std::endl;
        return (1);
    }

    std::ifstream   inputFile(infile.data());
    if (!inputFile.good())
    {
        std::cerr << "Error: cannot open " << infile << std::endl;
        return (1);
    }
    if (inputFile.peek() == std::ifstream::traits_type::eof()) //check if infile is empty
    {
        std::cerr << "Error: input file is empty" << std::endl;
        inputFile.close();
        return (1);
    }
    std::ofstream   outputFile(outfile.data());
    if (!outputFile.good())
    {
        std::cerr << "Error: cannot open " << outfile << std::endl;
        inputFile.close();
        return (1);
    }

    std::string line;
    size_t  pos_occr;

    while (inputFile.good() && outputFile.good())
    {
        std::getline(inputFile, line); 
        pos_occr = line.find(s1, 0);
        while (pos_occr != std::string::npos)
        {
            line.erase(pos_occr, s1.size());
            line.insert(pos_occr, s2);
            pos_occr = line.find(s1, pos_occr);
        }
        outputFile << line;
        if (!inputFile.eof())
            outputFile << std::endl;
        else
            break ;
    }
    inputFile.close();
    outputFile.close();
    return (0);
}