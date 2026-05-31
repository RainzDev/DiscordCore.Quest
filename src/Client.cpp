#define DISCORDPP_IMPLEMENTATION

#include "discordpp.h"

#include "../shared/DiscordCore/Auth.hpp"
#include "../shared/DiscordCore/Client.hpp"

discordpp::Client* client;

namespace DiscordCore {    
    void Client::CreateInstance() {
        if (!client) {
            client = new discordpp::Client();
        }
    }

    discordpp::Client* Client::GetClient() {
        if (!client) {
            return nullptr;
        }
        return client;
    }

    void Disconnect() {
        if (client) {
            client->Disconnect();
        }
    }

    void Authorize(discordpp::AuthorizationArgs args, discordpp::Client::AuthorizationCallback callback) {
        client->Authorize(args, callback);
    }
}