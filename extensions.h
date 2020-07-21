#ifndef FILESORTER_EXTENSIONS_H
#define FILESORTER_EXTENSIONS_H

#include <list>
#include <string>

struct Extensions {
private:
    // Audio file extensions
    const std::list<std::string> audio_ext
            {".aif", ".cda", ".mid", ".midi", ".mp3", ".mpa", ".ogg", ".wav", ".wma", ".wpl"};
    // Compressed file extensions
    const std::list<std::string> compressed_ext
            {".7z", ".arj", ".deb", ".pkg", ".rar", ".rpm", ".tar.gz", ".z", ".zip"};
    // Disc and media file extensions
    const std::list<std::string> disc_ext
            {".dmg", ".iso", ".toast", ".vcd"};
    // Data and database file extensions
    const std::list<std::string> data_ext
            {".csv", ".dat", ".db", ".dbf", ".log", ".mdb", ".sav", ".sql", ".tar", ".xml"};
    // E-mail file extensions
    const std::list<std::string> email_ext
            {".email", ".eml", ".emlx", ".msg", ".oft", ".ost", ".pst", ".vcf"};
    // Executable file extensions
    const std::list<std::string> executable_ext
            {".apk", ".bat", ".bin", ".com", ".exe", ".gadget", ".jar", ".msi", ".wsf"};
    // Font file extensions
    const std::list<std::string> font_ext
            {".fnt", ".fon", ".otf", ".ttf"};
    // Image file extensions
    const std::list<std::string> image_ext
            {".ai", ".bmp", ".gif", ".ico", ".jpeg", ".jpg", ".png", ".ps", ".psd", ".svg", ".tif", ".tiff"};
    // Internet related extensions
    const std::list<std::string> internet_ext
            {".asp", ".aspx", ".cer", ".cfm", ".cgi", ".css", ".htm", ".html", ".js", ".jsp", ".part", ".php",
             ".py", ".rss", ".xhtml"};
    // Presentation file extensions
    const std::list<std::string> presentation_ext
            {".key", ".odp", ".pps", ".ppt", ".pptx"};
    // Programming file extensions
    const std::list<std::string> programming_ext
            {".c", ".class", ".cpp", ".cs", ".h", ".java", ".pl", ".sh", ".swift", ".vb"};
    // Spreadsheet file extensions
    const std::list<std::string> spreadsheet_ext
            {".ods", ".xls", ".xlsm", ".xlsx"};
    // System related file extensions
    const std::list<std::string> system_ext
            {".bak", ".cab", ".cfg", ".cpl", ".cur", ".dll", ".dmp", ".drv", ".icns", ".ini", ".lnk", ".sys", ".tmp"};
    // Video file extensions
    const std::list<std::string> video_ext
            {".3g2", ".3gp", ".avi", ".flv", ".h264", ".m4v", ".mkv", ".mov", ".mp4", ".mpg", ".mpeg", ".rm", ".swf",
             ".vob", ".wmv"};
    // Word processor and text file extensions
    const std::list<std::string> text_ext
            {".doc", ".docx", ".odt", ".pdf", ".rtf", ".tex", ".txt", ".wpd"};

public:
    static constexpr unsigned str_hash(const char *str, int hash = 0) {
        return !str[hash] ? 5381 : (str_hash(str, hash + 1) * 33) ^ str[hash];
    }

    std::list<std::string> get_extensions(const std::string &type) {
        std::list<std::string> empty;

        switch (str_hash(type.c_str())) {
            case str_hash("audio"):
                return audio_ext;
            case str_hash("compressed"):
                return compressed_ext;
            case str_hash("disc"):
                return disc_ext;
            case str_hash("data"):
                return data_ext;
            case str_hash("email"):
                return email_ext;
            case str_hash("executable"):
                return executable_ext;
            case str_hash("font"):
                return font_ext;
            case str_hash("image"):
                return image_ext;
            case str_hash("internet"):
                return internet_ext;
            case str_hash("presentation"):
                return presentation_ext;
            case str_hash("programming"):
                return programming_ext;
            case str_hash("spreadsheet"):
                return spreadsheet_ext;
            case str_hash("system"):
                return system_ext;
            case str_hash("video"):
                return video_ext;
            case str_hash("text"):
                return text_ext;
            default:
                std::cerr << "Invalid type" << std::endl;
                return empty;
        }
    }
};

#endif //FILESORTER_EXTENSIONS_H
