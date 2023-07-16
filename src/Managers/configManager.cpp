//
// Created by trist on 2023-03-20.
//

#include <iostream>
#include "configManager.h"

template<typename T>
T configManager::get(const std::string& name) {
    std::stringstream stream(this->config[name]);
    T value;
    stream >> value;
    return value;
}

configManager::configManager(const std::vector<std::pair<std::string, std::any>>& settings, const std::filesystem::path& path) : config_file_path(path) {
    load(settings);
    save(path);
}

void configManager::set(const std::string name, const std::any value) {
    config[name] = serialize(value);
}

void configManager::save(const std::filesystem::path& path) {
    std::ofstream file{path};
    for (const auto& [key, value] : config) {
        file << key << "=" << value << std::endl;
    }
    file.close();
}

void configManager::load(const std::vector<std::pair<std::string, std::any>>& configs) {
    for (const auto& [key, value] : configs) {
        std::string configs_v = get_settings_file_content(key);
        set(key, configs_v != "unset" ? configs_v : value);
    }
}

std::string configManager::get_settings_file_content(const std::string& config_name) {
    std::ifstream file{config_file_path};
    std::string line;
    std::string value{"unset"};
    std::string key;

    while (std::getline(file, line)) {
        key = line.substr(0, line.find("="));
        trim(key);
        if (key == config_name) {
            value = line.substr(line.find("=") + 1);
            trim(value);
        }
    }
    return value;
}

void configManager::save() {
    save(config_file_path);
}

void configManager::reload() {
    for (const auto& [key, value] : config) {
        std::string configs_v = get_settings_file_content(key);
        set(key, configs_v != "unset" ? configs_v : value);
    }
}

std::string configManager::serialize(const std::any& value) {
    if (value.type() == typeid(int)) {
        return std::to_string(std::any_cast<int>(value));
    } else if (value.type() == typeid(float)) {
        return std::to_string(std::any_cast<float>(value));
    } else if (value.type() == typeid(double)) {
        return std::to_string(std::any_cast<double>(value));
    } else if (value.type() == typeid(bool)) {
        return std::to_string(std::any_cast<bool>(value));
    } else if (value.type() == typeid(std::string)) {
        return std::any_cast<std::string>(value);
    } else if (value.type() == typeid(char)) {
        return std::to_string(std::any_cast<char>(value));
    } else {
        return "unset";
    }
}

void configManager::trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}