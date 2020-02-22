#ifndef __H_TYPES_H__
#define __H_TYPES_H__
#include <string>

struct file_info {
    std::string file_name; // 名字
    std::string music_name; // 歌曲名
    int size; // 文件大小
    bool can_remove; // 可以删除
    std::string suffix; // 文件后缀
};

#endif