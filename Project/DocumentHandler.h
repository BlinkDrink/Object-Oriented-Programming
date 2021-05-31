#include<fstream>
#include<string>

using std::ifstream;
using std::ofstream;
using std::string;

class DocumentHandler {
private:
	ifstream reader;
	ofstream writer;
	bool isSaved;
public:
	DocumentHandler();
	void openFile(const string& path);
	void closeFile();
	void saveToFile();
	~DocumentHandler();
};