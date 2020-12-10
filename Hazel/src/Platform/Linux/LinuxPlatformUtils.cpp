#if defined(HZ_PLATFORM_LINUX)
#include "Hazel/Utils/PlatformUtils.h"

namespace Hazel {

	std::optional<std::string> FileDialogs::OpenFile(const char* filter)
	{
		return std::string();
        }

	std::optional<std::string> FileDialogs::SaveFile(const char* filter)
	{
		return std::string();
	}
}
#endif
