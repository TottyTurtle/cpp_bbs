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

void copyFile(string from, string to) {
    ifstream sourceFile(from, std::ios::binary); // Quelldatei im Bin�rmodus �ffnen
    ofstream destFile(to, std::ios::binary); // Zieldatei im Bin�rmodus �ffnen

    if (sourceFile && destFile) {
        // Dateiinhalt von der Quelldatei zur Zieldatei kopieren
        destFile << sourceFile.rdbuf();
    }

    // Dateien schlie�en
    sourceFile.close();
    destFile.close();
}

void prependStringToFile(const std::string& filename, const std::string& str) {
    std::ifstream inputFile(filename); // Datei im Lesemodus �ffnen
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close(); // Datei schlie�en

    std::ofstream tempFile("temp.txt"); // Tempor�re Datei erstellen
    tempFile << str << fileContent; // String vor den Inhalt setzen
    tempFile.close(); // Tempor�re Datei schlie�en

    std::remove(filename.c_str()); // Urspr�ngliche Datei l�schen
    std::rename("temp.txt", filename.c_str()); // Tempor�re Datei umbenennen
}
