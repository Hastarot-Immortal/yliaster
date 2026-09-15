#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

template<typename Resource>
inline bool load(Resource& res, const fs::path& resPath);
inline bool load(sf::Font& font, const fs::path& resPath);

template<typename Resource>
class ResourceFactory
{
private:
    std::unordered_map<std::string, Resource> resources_;
public:
    ResourceFactory(const fs::path& path)
    {
        std::unordered_map<std::string, Resource> resources;
        size_t parentDirLength = path.generic_string().length() + 1;

        for (const auto& entry : fs::recursive_directory_iterator(path))
        {
            auto entryPath = entry.path();
            if (entryPath.has_extension())
            {
                Resource res;
                if (load(res, entryPath))
                {
                    auto entryPathWithoutExt = entryPath.replace_extension("");
                    auto key = entryPathWithoutExt.generic_string().substr(parentDirLength);
                    resources.insert({key, res});
                }  
            }
        }
        resources_ = resources;
    }

    const Resource& get(const std::string& key) const
    {
        return resources_.at(key);
    }

    const Resource& get(const std::initializer_list<std::string>& keys) const
    {
        for (auto& key : keys)
            if (resources_.count(key)) return resources_.at(key);
        throw std::out_of_range("No such resource");
    }
};

using TextureFactory = ResourceFactory<sf::Texture>;
using FontFactory = ResourceFactory<sf::Font>;

template<typename Resource>
inline bool load(Resource& res, const fs::path& resPath)
{
    return res.loadFromFile(resPath);
}

inline bool load(sf::Font& font, const fs::path& resPath)
{
    return font.openFromFile(resPath);
}