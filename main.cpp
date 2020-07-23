#include <iostream>
#include <filesystem>
#include <list>
#include <map>

#include "extensions.h"

namespace fs = std::filesystem;

int main() {
    Extensions exts;

    // Mapping for extension lists
    std::map<std::string, std::list<std::string>> extensions{
            {"audio",        exts.get_extensions("audio")},
            {"compressed",   exts.get_extensions("compressed")},
            {"disc",         exts.get_extensions("disc")},
            {"data",         exts.get_extensions("data")},
            {"email",        exts.get_extensions("email")},
            {"executable",   exts.get_extensions("executable")},
            {"font",         exts.get_extensions("font")},
            {"image",        exts.get_extensions("image")},
            {"internet",     exts.get_extensions("internet")},
            {"presentation", exts.get_extensions("presentation")},
            {"programming",  exts.get_extensions("programming")},
            {"spreadsheet",  exts.get_extensions("spreadsheet")},
            {"system",       exts.get_extensions("system")},
            {"video",        exts.get_extensions("video")},
            {"text",         exts.get_extensions("text")}
    };

    // Get current path
    // If current path is not available, the script shuts down
    std::string cwd = fs::current_path();
    if (!cwd.empty())
        std::cout << "Current directory: " << cwd << std::endl;
    else {
        std::cerr << "Unable to get current directory!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "File list: " << std::endl;
    std::string file;
    std::list<std::string> file_list;

    // Get only file names from paths and print them
    for (const auto &file_path : fs::directory_iterator(cwd)) {
        if (file_path.is_directory())
            continue;
        file = file_path.path();
        file = file.substr(file.find_last_of('/') + 1);
        file_list.push_back(file);
        std::cout << file << std::endl;
    }

    std::cout << "File extensions:" << std::endl;
    std::string ext;

    // This loop gets file extensions and sort files in directories depending on extensions
    // If directory cannot be found, create it in current cwd
    for (auto &item : file_list) {
        ext = item.find_last_of('.') != std::string::npos ? item.substr(item.find_last_of('.')) : "";

        // Search for needed extension in lists
        for (const auto &ext_pair : extensions) {
            // If extensions is found, choose needed case
            // All the cases create needed directory if it is not exists and replace needed file in there
            // The only difference is in file types
            if (std::binary_search(ext_pair.second.cbegin(), ext_pair.second.cend(), ext)) {
                switch (Extensions::str_hash(ext_pair.first.c_str())) {
                    case Extensions::str_hash("audio"):
                        if (!fs::exists(fs::path(cwd + "/Audio"))) {
                            std::cout << "Directory: " + cwd + "/Audio does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Audio"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Audio"));
                        break;
                    case Extensions::str_hash("compressed"):
                        if (!fs::exists(fs::path(cwd + "/Compressed"))) {
                            std::cout << "Directory: " + cwd + "/Compressed does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Audio"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Compressed"));
                        break;
                    case Extensions::str_hash("disc"):
                        if (!fs::exists(fs::path(cwd + "/Disc"))) {
                            std::cout << "Directory: " + cwd + "/Disc does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Disc"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Disc"));
                        break;
                    case Extensions::str_hash("data"):
                        if (!fs::exists(fs::path(cwd + "/Data"))) {
                            std::cout << "Directory: " + cwd + "/Data does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Data"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Data"));
                        break;
                    case Extensions::str_hash("email"):
                        if (!fs::exists(fs::path(cwd + "/Email"))) {
                            std::cout << "Directory: " + cwd + "/Email does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Email"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Email"));
                        break;
                    case Extensions::str_hash("executable"):
                        if (!fs::exists(fs::path(cwd + "/Executable"))) {
                            std::cout << "Directory: " + cwd + "/Executable does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Executable"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Executable"));
                        break;
                    case Extensions::str_hash("font"):
                        if (!fs::exists(fs::path(cwd + "/Font"))) {
                            std::cout << "Directory: " + cwd + "/Font does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Font"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Font"));
                        break;
                    case Extensions::str_hash("image"):
                        if (!fs::exists(fs::path(cwd + "/Image"))) {
                            std::cout << "Directory: " + cwd + "/Image does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Image"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Image"));
                        break;
                    case Extensions::str_hash("internet"):
                        if (!fs::exists(fs::path(cwd + "/Internet"))) {
                            std::cout << "Directory: " + cwd + "/Internet does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Internet"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Internet"));
                        break;
                    case Extensions::str_hash("presentation"):
                        if (!fs::exists(fs::path(cwd + "/Presentation"))) {
                            std::cout << "Directory: " + cwd + "/Presentation does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Presentation"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Presentation"));
                        break;
                    case Extensions::str_hash("programming"):
                        if (!fs::exists(fs::path(cwd + "/Programming"))) {
                            std::cout << "Directory: " + cwd + "/Programming does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Programming"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Programming"));
                        break;
                    case Extensions::str_hash("spreadsheet"):
                        if (!fs::exists(fs::path(cwd + "/Spreadsheet"))) {
                            std::cout << "Directory: " + cwd + "/Spreadsheet does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Spreadsheet"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Spreadsheet"));
                        break;
                    case Extensions::str_hash("system"):
                        if (!fs::exists(fs::path(cwd + "/System"))) {
                            std::cout << "Directory: " + cwd + "/System does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/System"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/System"));
                        break;
                    case Extensions::str_hash("video"):
                        if (!fs::exists(fs::path(cwd + "/Video"))) {
                            std::cout << "Directory: " + cwd + "/Video does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Video"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Video"));
                        break;
                    case Extensions::str_hash("text"):
                        if (!fs::exists(fs::path(cwd + "/Text"))) {
                            std::cout << "Directory: " + cwd + "/Text does not exist. Creating..." << std::endl;
                            if (!fs::create_directory(fs::path(cwd + "/Text"))) {
                                std::cerr << "Unable to create directory" << std::endl;
                                return EXIT_FAILURE;
                            }
                        }

                        fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Text"));
                        break;
                }

                // After replacement, clear extension to sort undefined files
                fs::remove(fs::path(cwd + "/" + item));
                item = "";
            }
        }

        ext.empty() ? std::cout << "Undefined extension" << std::endl : std::cout << ext << std::endl;
    }

    // If there are undefined files in list, sort them in Misc directory
    if (std::binary_search(file_list.cbegin(), file_list.cend(), "")) {
        if (!fs::exists(fs::path(cwd + "/Misc"))) {
            std::cout << "Directory: " + cwd + "/Misc does not exist. Creating..." << std::endl;
            if (!fs::create_directory(fs::path(cwd + "/Misc"))) {
                std::cerr << "Unable to create directory" << std::endl;
                return EXIT_FAILURE;
            }
        }

        for (const auto &item : file_list) {
            if (!item.empty()) {
                fs::copy(fs::path(cwd + "/" + item), fs::path(cwd + "/Misc"));
                fs::remove(fs::path(cwd + "/" + item));
            }
        }
    }

    return EXIT_SUCCESS;
}