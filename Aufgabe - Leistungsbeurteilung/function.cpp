int getKey()
{
   int result = getch();
   if(result==0) {
      result = 256 + getch();
   }
   return result;
}

bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
int isFile(const char* name)
{
    DIR* directory = opendir(name);
    if(directory != NULL) {
     closedir(directory);
     return 0;
    }
    if(errno == ENOTDIR) {
     return 1;
    }
    return -1;
}
