#include <string>
#include <fstream>
#include <utility>
#include <iostream>

/**
 * @brief class that parse yaml file
 * 
 */
class yamlParser {
private:
    std::string data;
    int position = 0;
public:
    yamlParser(const std::string path) {
        std::ifstream file (path);
		if (file) {

			std::string buffer;
			while (!file.eof()) {
				std::getline(file, buffer);
				data.append(buffer + '\n');
			}
			file.close();
		}
		else {
			std::cout << "Cannot open the file in path " + path;
		}
    };
    auto nextLine() -> std::string {
        std::string temp = "";  
        int count = position;   
        while(data.at(count) != '\n') {
            temp += data.at(count);
            count++;
        }
        position = ++count;		// counting 1 up for '\n'
		if (temp.find("-") != std::string::npos) {
			temp.erase(std::find(temp.begin(), temp.end(), '-'));
		}
        return temp;
    };
    auto nextStringString() -> std::pair<std::string, std::string> {
        std::string buffer = nextLine();    // Get the next line.
        int position = buffer.find(":");    // find where the tag ends.
        std::string tag = buffer.substr(0, position);   // Get the tag string.
        std::string value = buffer.substr(position + 1, buffer.size());	// Get the value string.
        std::pair<std::string, std::string> stringString (tag, value);	// Make a pair of string and string.
        return stringString;
    }

    auto nextStringInt() -> std::pair<std::string, int> {
        std::string buffer = nextLine(); // Get the next line.
        int position = buffer.find(":");    // Find where the tag ends
        std::string tag = buffer.substr(0, position);  // Get the string.
        int value = std::stoi(buffer.substr(position + 1));    // Get the int.
        std::pair<std::string, int> stringInt (tag, value);   // Make a pair of string and int.

        return stringInt;        
    };
};