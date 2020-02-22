#ifndef __H_LOAD_FILE_H__
#define __H_LOAD_FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include "types.h"

std::vector<file_info> readFileList(const char *basePath);
std::vector<std::string> readFileDirent(const char *basePath);

#endif

