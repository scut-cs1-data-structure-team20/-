#ifndef PAPER_H
#define PAPER_H

#include <string>
#include <vector>

using namespace std;

struct Paper
{
    vector<string> authors; // 作者，不止一个，用数组记录
    string title;           // 标题名
    string journal;         // 发表杂志
    string volume;          // 卷号
    string month;           // 发表月份
    string year;            // 发表年份
    string cdrom;           // 猜测为光盘（存储路径或文件名）
    string ee;              // 猜测为电子版本（存储路径或网址）
};

#endif