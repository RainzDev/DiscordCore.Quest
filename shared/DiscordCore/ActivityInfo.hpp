#pragma once

#include <string>
#include <ctime>
#include <array>

namespace DiscordCore {


struct Secrets {
    std::string join;
    std::string spectate;
    std::string match;
};

struct Party {
    std::string id;
    std::array<int, 2> size;
};

struct Assets {
    std::string largeImage;
    std::string largeText;
    std::string largeUrl;
    std::string smallImage;
    std::string smallText;
    std::string smallUrl;
};

struct Timestamps {
    std::time_t start;
    std::time_t end;
};

struct Activity {
    std::string state;
    std::string stateUrl;
    std::string details;
    std::string detailsUrl;
    Timestamps timestamps;
    Assets assets;
    Party party;
    Secrets secrets;
    bool instance = false;
};

void Init();

void SetActivity(const Activity& activity);

}