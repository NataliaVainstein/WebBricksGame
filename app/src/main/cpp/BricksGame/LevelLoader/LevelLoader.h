#ifndef __LEVEL_LOADER__
#define __LEVEL_LOADER__

#include <vector>

class LevelLoader
{
public:
	LevelLoader();
	bool getLine(std::string& _strLine, size_t _numLine);
	size_t numberLines();

private:
	std::vector<std::string> m_level;
};



#endif //__LEVEL_LOADER__
