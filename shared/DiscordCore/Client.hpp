namespace discordpp {
    class Client;
}

namespace DiscordCore {
    class Client {
        public:
            void CreateInstance();
            void Shutdown();
            void Authorize();

            ~Client();  // delete client pointer in cpp!!
        private:
            discordpp::Client* client;
            discordpp::Client* GetClient();
    };
}