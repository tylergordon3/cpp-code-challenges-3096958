// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    std::string line;
    std::vector<std::string> names;
    if(file.is_open()){
        // Write your code here
        while(std::getline(file,line,',')) {
            names.push_back(line);
        }
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    for (int i = 0; i < names.size(); i++) {
        string current = names[i];
        auto pos = current.find(" ");
        string fam_name = current.substr(pos, current.size());

        for (int j = i + 1; j < names.size(); j++) {
            string check = names[j];
            auto pos2 = check.find(" ");
            string fam_name2 = check.substr(pos2,check.size());

            if (fam_name == fam_name2) {
                std::cout << current << " is related to " << check << endl;
                return 0;
            }
        }
    }
    return 0;
}
 