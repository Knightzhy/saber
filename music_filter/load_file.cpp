#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <io.h>
#include <cstring>
#include "load_file.h"
#include "types.h"


std::vector<file_info> readFileList(const char *basePath){
    std::vector<file_info> result;
    char dirNew[200];
    strcpy(dirNew, basePath);
    strcat(dirNew, "\\*.*");    // 在目录后面加上"\\*.*"进行第一次搜索

    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dirNew, &findData);
    if (handle == -1)        // 检查是否成功
        return result;

    do
    {
        if (findData.attrib & _A_SUBDIR)
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            std::cout << findData.name << "\t<dir>\n";

            // 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
            strcpy(dirNew, basePath);
            strcat(dirNew, "\\");
            strcat(dirNew, findData.name);

            std::vector<file_info> tmp = readFileList(dirNew);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        else {
        //    std::cout << findData.name << "\t" << findData.size << " bytes.\n";
            file_info item;
            item.file_name = findData.name;
            item.size = findData.size;
            item.can_remove = false;
            result.push_back(item);
        }
    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // 关闭搜索句柄
    return result;
}