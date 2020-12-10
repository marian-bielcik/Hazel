#if defined(HZ_PLATFORM_LINUX)
#include "Hazel/Utils/PlatformUtils.h"

namespace Hazel {

	std::optional<std::string> FileDialogs::OpenFile(const char* filter)
	{
		char tmp[1024] = {0};
		char parameter[1024] = {0};
		char filename[1024] = {0};
		char *ret = nullptr;

		if(strlen(filter) < sizeof(tmp) - 1){
			strcpy(parameter, "zenity --file-selection");

			ret = getcwd(tmp, sizeof(tmp));
			if(ret && strlen(tmp) > 0 && strlen(tmp) < sizeof(tmp) - 2){
				tmp[strlen(tmp)] = '/';
				tmp[strlen(tmp)+1] = 0;
				strcat(parameter, " --filename=\"");
				strcat(parameter, tmp);
				strcat(parameter, "\"");
			}
			strcat(parameter, " --file-filter=\"");
			
			memcpy(tmp, filter, sizeof(tmp));
			size_t index = strlen(filter);
			if(index < sizeof(tmp) - 1)
				tmp[index] = '|';
			tmp[sizeof(tmp)-1] = 0;
			strcat(parameter, tmp);
			strcat(parameter, "\"");
			
			FILE *f = popen(parameter, "r");
			fgets(filename, sizeof(filename), f);
			if(strlen(filename) > 0)
				filename[strlen(filename)-1] = 0;

			return std::string(filename);
		}else{
			return std::nullopt;
		}
	}

	std::optional<std::string> FileDialogs::SaveFile(const char* filter)
	{
		char tmp[1024] = {0};
		char parameter[1024] = {0};
		char filename[1024] = {0};
		char *ret = nullptr;
		
		if(strlen(filter) < sizeof(tmp) - 1){
			strcpy(parameter, "zenity --file-selection --save --confirm-overwrite");
			
			ret = getcwd(tmp, sizeof(tmp));
			if(ret && strlen(tmp) > 0 && strlen(tmp) < sizeof(tmp) - 2){
				tmp[strlen(tmp)] = '/';
				tmp[strlen(tmp)+1] = 0;
				strcat(parameter, " --filename=\"");
				strcat(parameter, tmp);
				strcat(parameter, "\"");
			}
			strcat(parameter, " --file-filter=\"");
			
			memcpy(tmp, filter, sizeof(tmp));
			size_t index = strlen(filter);
			if(index < sizeof(tmp) - 1)
				tmp[index] = '|';
			tmp[sizeof(tmp)-1] = 0;
			strcat(parameter, tmp);
			strcat(parameter, "\"");
			
			FILE *f = popen(parameter, "r");
			fgets(filename, sizeof(filename), f);
			if(strlen(filename) > 0)
				filename[strlen(filename)-1] = 0;

			return std::string(filename);
		}else{
			return std::nullopt;
		}
	}
}
#endif
