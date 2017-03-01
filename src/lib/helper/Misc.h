// last modified 

#pragma once

#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::ostringstream;
using std::vector;
using std::pair;


// why not std::to_string()? 
// you know, I have to port this linux code to win32 by cygwin, and there
// is a bug on cygwin case it cannot find to_string(), so, I must do it
// by myself
template<typename T>
string
convNumToStr (T num)
{
    ostringstream oss;
    oss << num;

    return(oss.str());
}

// split raw string to more sub-str by token-chars.
void
splitStr ( const string& str,
           const string& tokens_list,
           vector<string>& splited_substr_list,
           vector<char>& appeared_tokens_list );

// fetch string from txt betwen keyword_begin and keyword_end.
// case sensitive 
pair<string, size_t>
fetchStringBetweenKeywords ( const string& txt,
                             const string& keyword_begin,
                             const string& keyword_end,
                             size_t from_pos = 0 );

// get file size by FILE*
long
getFileSize (FILE* fs);

// get random filename, include path
string
makeRandomFilename (void);

// unicode 转 UTF8
pair<size_t, unsigned long long>
convertUnicodeToUtf8 (unsigned int unicode);

// fork() 启动新进程后立即返回，而本函数将等待新进程执行完毕后再返回
bool
wait_cmd ( const string& cmd,
           const vector<string>& argv,
           int* p_exitCode = nullptr,
           bool b_echo = false ); 
