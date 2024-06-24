#include <vector>
#include <string>

struct ASCIIMessage_S
{
    float timeStamp = -1.0;
    int CANBus = -1;
    int messageID = 0;
    bool receivedMessage = false;
    int dataLength = -1;
    std::vector<std::string> bytes;
};

struct dataStamp
{
    float timeStamp = -1.0;
    float engineeringValue = -1.0;
};

struct TranslatedSignals_S
{
    std::string signalName = "";
    std::string unit = "";
    std::vector<dataStamp> dataStampList;
};

class ASCIIParser
{
    private:
        std::string filePath;

        std::vector<struct TranslatedSignals_S> signalTimeSeries;

        void loadMessage(const std::string& line, struct ASCIIMessage_S& message);

        void populateSignals(struct ASCIIMessage_S& message);

        void translateMessageID(struct ASCIIMessage_S& message, std::string messageID);

        void unpackBytes(struct ASCIIMessage_S& message,std::string bytes);

    public:
        ASCIIParser(std::string asciiFilePath) : filePath(asciiFilePath){};

        void run();

        ~ASCIIParser(){};

};