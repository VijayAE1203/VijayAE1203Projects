#include <string>
#include <vector>

struct Signal_S
{
    std::string signalName = "";
    int multiplexorID = 0; 
    int startBit = 0;
    int signalLength = 0;
    bool isLittleEndian = false;
    bool isUnsigned = false;
    float factor = 0.0;
    float offset = 0.0;
    std::string max = "";
    std::string min = "";
    std::string unit = "";
    std::string RXNode = "";
};

struct Message_S
{
    std::string messageID = "";
    std::string messageName = "";
    std::string dataLength = "";
    std::string TXNode = "";
    std::vector<struct Signal_S> signals;
    bool isMultiplexed = false;
    std::string multiplexorName = "";

};

class DBCParser
{
    private:
        std::string filePath;

        std::vector<struct Message_S> messageList;
        
        void setMessages(const std::string& line);

        void setSignals(const std::string& line);

        void checkMultiplex(struct Signal_S& signal);

    public:
        DBCParser(std::string dbcFilePath) : filePath(dbcFilePath){};

        void load();

        ~DBCParser(){};

};