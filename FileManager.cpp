//
// Created by dxuma on 11/24/2019.
//

void FileManager::read(std::string fileName, std::string stringToRead){
    std::ifstream infile(fileName);
    while(infile){
        getline(infile, stringToCheck);
        if (stringToCheck == stringToRead){
            std::cout << stringToCheck << cout::endl
        }
    }

}

void FileManager::write(std::string fileName, std::string stringToWrite){
    std::ofstream outf(filename);
    if (outf){
        outf << stringToWrite << std::endl;
        outf.close();
    }
    else{
        std::cerr << "Can't write to file" << std::endl;
    }
}

