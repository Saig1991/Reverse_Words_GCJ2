#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]){
    
    //Ensure that the input file was specified on the command line.
    if(argc != 2){
        std::cout << "No input file was specified on the command line." << std::endl;
        std::cout << "Usage: ./program [input file name]" << std::endl;
    } else {
        std::string inputFile(argv[1]);
        std::ifstream ifs(inputFile.c_str(), std::ifstream::in);

        int caseCounter = 0;
        if(ifs.good()){
            //Read each line from the file.
            for(std::string line; std::getline(ifs,line); caseCounter++){
                if(caseCounter == 0) continue;
                //Split each line into a vector of words.
                std::stringstream lineOfWords(line);
                std::string getWords;
                std::vector<std::string> words;
                while(lineOfWords >> getWords){
                    std::vector<std::string>::iterator wordsIt = words.begin();
                    words.insert(wordsIt,getWords);
                }

                std::vector<std::string>::iterator wordsIt = words.begin();
                std::cout << "Case #" << caseCounter << ": ";
                while(wordsIt != words.end()){
                    std::cout << *wordsIt << " ";
                    wordsIt++;
                }
                std::cout << std::endl;
            }
        }
        ifs.close();
    }

    return 0;    
}

