#include "MsgError.h"


extern void msgError(std::string msg, std::string extra)
{
	std::cout << (msg + " " + extra).c_str() << std::endl;
}