#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

namespace app::messages {
    struct Message {
        std::string author;
        std::string text;
    };

    std::string formatMessage(const Message& message);
}

#endif
