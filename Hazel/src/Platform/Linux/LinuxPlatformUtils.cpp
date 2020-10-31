#if defined(HZ_PLATFORM_LINUX)
#include "Hazel/Utils/PlatformUtils.h"

namespace Hazel {

	std::string FileDialogs::OpenFile(const char* filter)
	{
		return std::string();
        }

	std::string FileDialogs::SaveFile(const char* filter)
	{
		return std::string();
	}
}
#endif
