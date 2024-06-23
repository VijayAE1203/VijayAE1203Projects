#include <exception>
#include <string>

namespace unittestdemo
{
    class abnormal_distance_exception: public std::exception
    {
        private:
            std::string message;

        public:
            abnormal_distance_exception(std::string msg);

            const char* what() const;
    };
}
