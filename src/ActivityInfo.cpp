#include "../shared/DiscordCore/ActivityInfo.hpp"

#include "../include/discord_social_sdk/include/discordpp.h"
#include "main.hpp"

namespace DiscordCore {

static std::unique_ptr<discordpp::Client> client;

void Init() {
    client = std::make_unique<discordpp::Client>();

    return;
}

void Shutdown() {
    client.reset();
}

void SetActivity(const Activity& activityInfo) {
    if (!client)
        return;

    discordpp::Activity activity;

    activity.SetState(activityInfo.state);
    activity.SetStateUrl(activityInfo.stateUrl);
    activity.SetDetails(activityInfo.details);
    activity.SetDetailsUrl(activityInfo.detailsUrl);
    // activity.SetTimestamps(activityInfo.timestamps);

    client->UpdateRichPresence(activity, [](auto result) {
        if (!result.Successful()) {
            logger.error("Failed to update rich presence: " + result.Error());
        }
    });
}

}