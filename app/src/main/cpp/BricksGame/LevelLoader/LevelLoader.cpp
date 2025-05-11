#include "LevelLoader.h"

LevelLoader::LevelLoader()
:m_level({"SNSNSNS", "SNNNNNS", "NNNNNNN"})
{
}

size_t LevelLoader::numberLines()
{
	return m_level.size();
}


bool LevelLoader::getLine(std::string& _strLine, size_t _numLine)
{
		if (_numLine < m_level.size())
		{
			_strLine = m_level[_numLine];
			return true;
		}
		return false;
}
