#ifndef SEARCH_H
#define SEARCH_H

#include "paper.h"

#include <unordered_map>
#include <vector>

using namespace std;

vector<Paper *> search(string &author) {};        // F1基本搜索功能。输入作者名，能展示该作者发表的所有论文信息。
Paper *searchBytitle(string &title) {};           // F1基本搜索功能。输入完整的论文题目，能展示该论文的其他相关信息。
vector<string> searchByauthor(string &author) {}; // F2相关搜索。输入作者，能展示与该作者有合作关系的所有作者。
vector<Paper *> partSearch(string &keywords) {};  // F5部分匹配搜索功能。给定若干个关键字，能快速搜索到题目中包含该关键字的文章信息

#endif