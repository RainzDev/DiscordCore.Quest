namespace discordpp {
    class Client;
}

namespace DiscordCore {
    class Client {
        public:
            void CreateInstance();
            void Disconnect();
            void Authorize();

            ~Client();  // delete client pointer in cpp!!
        private:
            discordpp::Client* client;
            discordpp::Client* GetClient();
    };
}