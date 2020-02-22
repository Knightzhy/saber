#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "load_file.h"
#include "remove_file.h"
#include "types.h"
std::string m_path_profix = "./music/";

extern std::vector<file_info> readFileList(const char *basePath);
extern void remove_file(std::string path);

void remove_files(const std::vector<file_info> &files)
{
    for (const auto& i : files) {
        if (i.can_remove) {
            remove_file(m_path_profix + i.file_name);
        }
    }
}

void rename_files(const std::vector<file_info> &files)
{
    for (const auto& i : files) {
        if (!i.can_remove) {
            if (i.file_name == (i.music_name + i.suffix)) {
                continue;
            }
            if (0 != rename((m_path_profix + i.file_name).c_str(),
              (m_path_profix + i.music_name + i.suffix).c_str())) {
                std::cout << i.file_name << " rename " << i.music_name + i.suffix << " failed." << std::endl;
                continue;
            }
            std::cout << i.file_name << " rename " << i.music_name + i.suffix << " success." << std::endl;
        }
    }
}

void print_files(const std::vector<file_info> &files)
{
    int count = 0;
    for (auto i : files) {
        std::cout << i.can_remove
        << "\t" << i.size
        << "\t" << i.music_name
        << "\t" << i.file_name
        << "\t" << i.suffix
        << std::endl;
        if (i.can_remove) {
            count++;
        }
    }
    std::cout << "files count :" << files.size() << std::endl;
    std::cout << "need rm files count :" << count << std::endl;
}

void fomat_files(std::vector<file_info> &files)
{
    // 去掉文件后缀
    for (auto& i : files) {
        std::string name = i.file_name;
        std::size_t pos = name.rfind(".");
        i.music_name = name.substr(0, pos);
        i.suffix = name.substr(pos);
    }

    // 去掉文件名中(1)结尾
    for (auto& i : files) {
        std::string name = i.music_name;
        std::size_t pos = name.rfind("(1)");
        i.music_name = name.substr(0, pos);
    }
}

void compare(std::vector<file_info> &files)
{
    for (auto& i : files) {
        for (auto& j : files) {
            if (i.music_name == j.music_name) {
                if (i.size < j.size) {
                    i.can_remove = true;
                }
                if (i.size > j.size) {
                    j.can_remove = true;
                }
            }
        }
    }
}

void process(std::vector<file_info> &files) 
{
    fomat_files(files);
    compare(files);
//    remove_files(files);
    rename_files(files);
}

int main()
{
    std::vector<file_info> result = readFileList(m_path_profix.c_str());

    process(result);

//    print_files(result);

    return 0;   
}