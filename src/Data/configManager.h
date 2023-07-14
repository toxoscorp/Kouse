//
// Created by trist on 2023-03-20.
//

#ifndef KOUSECPP_CONFIGMANAGER_H
#define KOUSECPP_CONFIGMANAGER_H

#include <iostream>
#include <any>
#include <vector>
#include <filesystem>
#include <map>
#include <regex>
#include <fstream>

class configManager {
public:
    typedef std::vector<std::pair<std::string, std::any>> configFile;

    explicit configManager(const configFile& configs, const std::filesystem::path& path = "./config.json");

    template<typename T>
    T get(const std::string& name);
    void set(const std::string name, const std::any value);
    void save();
    void load();
    void reload();

private:
    std::filesystem::path config_file_path{};
    std::map<std::string, std::string> config{};

    static void trim(std::string& str);
    static std::string serialize(const std::any& value);
    static std::any deserialize(const std::string& value);
    std::string get_settings_file_content(const std::string& config_name);
    void load(const configFile& configs);
    void save(const std::filesystem::path& path);
};

#endif //KOUSECPP_CONFIGMANAGER_H
