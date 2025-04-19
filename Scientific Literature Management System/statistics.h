#ifndef STATISTICS
#define STATISTICS

#include "paper.h"

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> top100_authors(unordered_map<string, int> artical_counts) {}; // F3作者统计功能。输出写文章最多的100名作者
vector<string> top10_keywords(vector<string> preyear_titles) {};             // F4热点分析功能。分析每一年发表的文章中，题目所包含的的单词中，出现频率排名前10的关键词

#endif